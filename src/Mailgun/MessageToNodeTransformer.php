<?php

namespace Drupal\bonsai\Mailgun;

// Internal depenencies.
use Bonsai\MessageTransformerInterface;

class MessageToNodeTransformer implements MessageTransformerInterface {
  public function transform($message) {
    // Convert the time to a unix timestamp so that we can store it in a date
    // field of unix timestamp type.
    $time = strtotime($message->{'Date'});

    // Get the recipients' emails.
    /**
     * @Issue(
     *   "Store both the email but also the full address incl. name, if
     *   available, for sender and recipients fields"
     *   type="improvement"
     *   priority="low"
     *   labels="data"
     * )
     * @Issue(
     *   "Detect and store CC and BCC recipients as well"
     *   type="bug"
     *   priority="low"
     *   labels="data"
     * )
     */
    $recipients = [$message->{'recipients'}];

    // Create a node for storing the message.
    $node = entity_create('node', array('type' => 'bonsai_message_email'));

    // We always assign the superuser as the owner of the email to indicate that
    // the node was created automatically. We may change this when the we create
    // nodes for messages send by from within the system.
    $node->uid = 1;

    // The title fiels is mandatory for nodes. If the email does not have a
    // subject, we store a placeholder field.
    /**
     * @Issue(
     *   "Change the email message's node view page to be the email's subject"
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

    // Mandatory fields.
    $node_wrapper->bonsai_email_id  = _bonsai_email_trim_email_id($message->{'Message-Id'});
    $node_wrapper->bonsai_email     = $message->{'sender'};
    $node_wrapper->bonsai_emails    = $recipients;
    $node_wrapper->bonsai_timestamp = $time;
    $node_wrapper->bonsai_json      = json_encode($message);

    /**
     * @Issue(
     *   "Retrieve and store the full raw email as well as a node field"
     *   type="bug"
     *   priority="normal"
     *   labels="data"
     * )
     */

    // Optional fields.
    if (!empty($message->{'subject'})) {
      $node_wrapper->bonsai_email_subject = $message->{'subject'};
    }
    if (!empty($message->{'body-plain'})) {
      $node_wrapper->bonsai_long_text     = $message->{'body-plain'};
    }
    if (!empty($message->{'body-html'})) {
      $node_wrapper->bonsai_long_text2    = $message->{'body-html'};
    }

    /**
     * @Issue(
     *   "Confirm that the current authenticity/spam validation is adequate"
     *   type="bug"
     *   priority="normal"
     *   labels="security"
     * )
     */

    // Does the email look spoofed?
    if (!empty($message->{'X-Mailgun-Dkim-Check-Result'}) && $message->{'X-Mailgun-Dkim-Check-Result'} === 'Pass') {
      $node_wrapper->bonsai_boolean = TRUE;
    }
    else {
      $node_wrapper->bonsai_boolean = FALSE;
    }

    // Is it spam?
    if (!empty($message->{'X-Mailgun-Sflag'}) && $message->{'X-Mailgun-Sflag'} === 'No') {
      $node_wrapper->bonsai_boolean2 = FALSE;
    }
    else {
      $node_wrapper->bonsai_boolean2 = TRUE;
    }

    return $node_wrapper;
  }
}
