<?php

namespace Drupal\bonsai\Mailgun;

// Internal depenencies.
use Bonsai\MessageTransformerInterface;

class MessageToNodeTransformer implements MessageTransformerInterface {
  public function transform($message, array $options = array()) {
    // If we are given a node, we are updating a draft message awaiting for
    // delivery. Otherwise it is an incoming email and we are creating a new
    // node for storing it.
    if (empty($options['node'])) {
      return $this->createNode($message);
    }

    return $this->updateNode($message, $options['node']);
  }

  private function createNode($message) {
    try {
      return $this->doCreateNode($message);
    }
    catch (\Exception $e) {
      $exception_class = get_class($e);
      throw new $exception_class(
        sprintf(
          'An exception was thrown while transforming the incoming message with ID "%s" to a node. The full message is "%s" and the exception message is "%s"',
          _bonsai_email_trim_email_id($message->{'Message-Id'}),
          json_encode($message),
          $e->getMessage()
        )
      );
    }
  }

  private function doCreateNode($message) {
    // Create a node for storing the message.
    $node = entity_create('node', array('type' => 'bonsai_message_email'));

    // We always assign the superuser as the owner of the email to indicate that
    // the node was created automatically as an incoming email and not by a user
    // in the system.
    $node->uid = 1;

    // Convert the time to a unix timestamp so that we can store it in a date
    // field of unix timestamp type. If we can't properly detect the time we'll
    // use the current timestamp . It won't be very accurate as it could be a
    // few minutes, up to 30 minutes, later than the correct date depending on
    // how frequently the cron job run. We can always correct the time later
    // though when we fix any problems with the detection.
    $time = time();

    // First try the Date header.
    if (!empty($message->{'Date'})) {
      $parsed_time = strtotime($message->{'Date'});
      // See Issue below.
      if ($parsed_time) {
        $time = $parsed_time;
      }
    }
    // When we send an email to one of our own accounts, the Date headers will
    // be missing (update: it seems this happens in other cases as well). There
    // will be the Received headers though. It is in the format: by
    // luna.mailgun.net with HTTP; Thu, 09 Mar 2017 03:08:06 +0000
    elseif (!empty($message->{'Received'})) {
      $received_time_parts = explode(';', $message->{'Received'});
      /**
       * @Issue(
       *   "Validate the format of the Received header"
       *   type="bug"
       *   priority="low"
       *   labels="mailgun api"
       * )
       * @Issue(
       *   "Refactor the function that extracts the timestamp from the Received
       *   header so that it can be reused"
       *   type="task"
       *   priority="low"
       *   labels="refactoring"
       * )
       */
      if (!empty($received_time_parts[1])) {
        $parsed_time = strtotime(trim($received_time_parts[1]));
        // If the datetime string cannot be parsed 'strtotime will return
        // FALSE. Only use it when parsed correctly.
        // @Issue(
        //   "Some datetime strings include the timezone for a second time in
        //   parenthesis and parsing fails"
        //   type="bug"
        //   priority="normal"
        // )
        // Example: "from prd-backend5 (backend5 [23.253.213.234])\tby smtp.efact.pe (Postfix) with ESMTP id A7203474A3\tfor; Wed, 20 Dec 2017 11:35:55 -0500 (-05)".
        if ($parsed_time) {
          $time = $parsed_time;
        }
      }
    }

    // Get the recipients' emails.
    $recipients = array();
    // The message may not have the To property if it is sent to undisclosed
    // recipients.
    /**
     * @Issue(
     *   "Save the 'recipients' property for messages with undisclosed
     *   recipients, possibly on a separate field"
     *   type="improvements"
     *   priority="low"
     * )
     */
    if (isset($message->{'To'})) {
      $recipients = explode(',', $message->{'To'});
      $recipients = array_map('trim', $recipients);
    }

    // The title fiels is mandatory for nodes. If the email does not have a
    // subject, we store a placeholder field.
    /**
     * @Issue(
     *   "Change the message's node view page title to be the email's subject"
     *   type="bug"
     *   priority="low"
     *   labels="ux"
     * )
     */
    if (!empty($message->{'subject'})) {
      $node->title = substr($message->{'subject'}, 0, 255);
    }
    else {
      $node->title = 'No Subject';
    }

    // We will be using, and returning, an entity wrapper for easer field
    // handling.
    $node_wrapper = entity_metadata_wrapper('node', $node);

    // Add the raw data, if available.
    $this->updateBonsaiData($message, $node_wrapper);

    // Mandatory fields.
    $node_wrapper->bonsai_email_id  = _bonsai_email_trim_email_id($message->{'Message-Id'});
    $node_wrapper->bonsai_email     = $message->{'From'};
    $node_wrapper->bonsai_json      = json_encode($message);
    $node_wrapper->bonsai_timestamp = $time;

    // The To field is normally mandatory, but it can be empty for emails sent
    // to undisclosed recipients.
    if ($recipients) {
      $node_wrapper->bonsai_emails = $recipients;
    }

    /**
     * @Issue(
     *   "Retrieve and store the full raw email as well as a node field"
     *   type="bug"
     *   priority="normal"
     *   labels="data"
     * )
     */

    // Optional fields.
    if (!empty($message->{'Cc'})) {
      $cc_recipients = explode(',', $message->{'Cc'});
      $cc_recipients = array_map('trim', $cc_recipients);
      $node_wrapper->bonsai_emails2 = $cc_recipients;
    }
    /**
     * @Issue(
     *   "Validate that the Bcc field is properly retrieved"
     *   type="bug"
     *   priority="low"
     *   labels="data"
     * )
     */
    if (!empty($message->{'Bcc'})) {
      $bcc_recipients = explode(',', $message->{'Bcc'});
      $bcc_recipients = array_map('trim', $bcc_recipients);
      $node_wrapper->bonsai_emails3 = $bcc_recipients;
    }
    if (!empty($message->{'subject'})) {
      $node_wrapper->bonsai_email_subject = $message->{'subject'};
    }
    if (!empty($message->{'body-plain'})) {
      $node_wrapper->bonsai_text_long = $message->{'body-plain'};
    }
    if (!empty($message->{'body-html'})) {
      /**
       * @Issue(
       *   "Check if we should be setting the text format to bonsai_html for
       *   incoming email messages"
       *   type="bug"
       *   priority="low"
       *   labels="data"
       * )
       */
      $node_wrapper->bonsai_text_long2->value = $message->{'body-html'};
    }

    // Add labels - Inbox, Spam, spoof.
    /**
     * @Issue(
     *   "Confirm that the current authenticity/spam validation is adequate"
     *   type="bug"
     *   priority="normal"
     *   labels="security"
     * )
     * @Issue(
     *   "Consider not adding the Inbox labels to Spam messages"
     *   type="improvement"
     *   priority="normal"
     *   labels="ux"
     * )
     */
    // We are dealing with incoming emails only here, so we can always safely
    // direct them to Inbox.
    $labels = array(
      'Inbox',
    );

    // Does the email look spoofed?
    if (empty($message->{'X-Mailgun-Dkim-Check-Result'}) || $message->{'X-Mailgun-Dkim-Check-Result'} !== 'Pass') {
      $labels[] = 'spoof';
    }

    // Is it spam?
    if (!empty($message->{'X-Mailgun-Sflag'}) && $message->{'X-Mailgun-Sflag'} !== 'No') {
      $labels[] = 'Spam';
    }

    $tids = _bonsai_taxonomy_term_multiple_by_name($labels, array('tids_only' => TRUE));
    $node_wrapper->bonsai_labels_ref = $tids;

    // User reference fields (sender and recipients).
    _bonsai_update_message_users($node_wrapper);

    // Finally, set the node status to be published since incoming messages can
    // never be drafts.
    $node_wrapper->status = 1;

    return $node_wrapper;
  }

  private function updateNode($message, $node_wrapper) {
    try {
      return $this->doUpdateNode($message, $node_wrapper);
    }
    catch (\Exception $e) {
      $exception_class = get_class($e);
      throw new $exception_class(
        sprintf(
          'An exception was thrown while updating the node with ID "%s" with the message with ID "%s". The full message is "%s" and the exception message is "%s"',
          $node_wrapper->getIdentifier(),
          _bonsai_email_trim_email_id($message->{'Message-Id'}),
          json_encode($message),
          $e->getMessage()
        )
      );
    }
  }

  private function doUpdateNode($message, $node_wrapper) {
    $node_wrapper = _bonsai_ensure_node_wrapper($node_wrapper);

    // We want to ensure that we are storing the email details on a node that is
    // already associated to this email. If not, it's a programming error and we
    // throw an exception.
    if ($node_wrapper->bonsai_email_id->value() !== _bonsai_email_trim_email_id($message->{'Message-Id'})) {
      throw new \Exception(
        sprintf(
          'Trying to update a node (ID: "%s", email ID: "%s") with the information of an email that is not associated with it (ID: "%s").',
          $node_wrapper->getIdentifier(),
          $node_wrapper->bonsai_email_id->value(),
          _bonsai_email_trim_email_id($message->{'Message-Id'})
        )
      );
    }

    // Set the JSON source of the message.
    /**
     * @Issue(
     *   "Store the raw email source as well for delivered messages"
     *   type="bug"
     *   priority="normal"
     *   labels="priority"
     * )
     */
    $node_wrapper->bonsai_json = json_encode($message);

    // Add the raw data, if available.
    $this->updateBonsaiData($message, $node_wrapper);

    // We're only sending HTML body, but Mailgun creates a plain text version of
    // it before sending it. Add this to the corresponding field as well.
    $node_wrapper->bonsai_text_long = $message->{'body-plain'};

    // Add the Sent label. The node message is only moved to the Sent folder
    // (via the Sent label) only after it has successfully been
    // delivered. Otherwise it stays on the Outbox folder, with a notice that it
    // is awaiting for delivery.
    _bonsai_message_add_labels($node_wrapper, array('Sent'));

    // Finally, set the node status to be published since we know it is now
    // delivered.
    $node_wrapper->status = 1;

    return $node_wrapper;
  }

  protected function updateBonsaiData(\stdClass $message, $node_wrapper) {
    if (empty($message->bonsai)) {
      return;
    }

    // Store the raw MIME message data, if available.
    // Strangely, this sometimes arrives here as an array (create node) and
    // sometimes as an `stdClass` (update node);
    $raw_data = NULL;
    if (is_array($message->bonsai) && !empty($message->bonsai['raw'])) {
      $raw_data = $message->bonsai['raw'];
    }
    if (is_object($message->bonsai) && !empty($message->bonsai->raw)) {
      $raw_data = $message->bonsai->raw;
    }
    $node_wrapper->bonsai_json2 = $raw_data;

    unset($message->bonsai);
  }
}
