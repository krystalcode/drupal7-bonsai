<?php

/**
 * @file
 * bonsai.pages.inc
 */

/**
 * @Issue(
 *   "Properly handle error cases instead of always returning 404"
 *   type="improvement"
 *   priority="low"
 *   labels="correctedness"
 * )
 */
function _bonsai_messages_send_page($node) {
  // Attachments are meant to be added via a POST request.
  if ($_SERVER['REQUEST_METHOD'] !== 'POST') {
    drupal_not_found();
    return;
  }

  // Currently only the node type provided by this module is supported.
  if (empty($node) || $node->type !== 'bonsai_message_email') {
    drupal_not_found();
    return;
  }

  // We have already checked whether the user has permissions to send the
  // requested message in the corresponding access callback. So let's go ahead
  // and create the message.

  // We'll be using an entity wrapper for getting field values more easily.
  $node_wrapper = entity_metadata_wrapper('node', $node);

  $domain = variable_get('bonsai_domain');
  $client = bonsai_get_client();

  // Mandatory message fields.
  $message = array(
    'from' => $node_wrapper->bonsai_email->value(),
    'to'   => implode(',', $node_wrapper->bonsai_emails->value()),
  );

  // Optional CC/BCC recipients.
  $cc = $node_wrapper->bonsai_emails2->value();
  if ($cc) {
    $message['cc'] = implode(',', $cc);
  }
  $bcc = $node_wrapper->bonsai_emails3->value();
  if ($bcc) {
    $message['bcc'] = implode(',', $bcc);
  }

  // Optional subject.
  $subject = $node_wrapper->bonsai_email_subject->value();
  if ($subject) {
    $message['subject'] = $subject;
  }

  // Optional body.
  // Currently, message authors can only write an HTML body using the rich text
  // editor. Mailgun will be creating a plain text version based on
  // that. However, let's just check if there is a plain text version and add
  // it, in case we support both plain text and HTML authoring in the future.
  $text = $node_wrapper->bonsai_long_text->value();
  if ($text) {
    $message['text'] = $text;
  }
  $html = $node_wrapper->bonsai_long_text2->value->value();
  if ($html) {
    $message['html'] = '<html>' . $html . '</html>';
  }

  // Attachments.
  $files = $node_wrapper->bonsai_files->value();
  $images = $node_wrapper->bonsai_images->value();
  $attachments = array_merge($files, $images);
  $attachment_paths = array_map(function($attachment) {
    return drupal_realpath($attachment['uri']);
  }, $attachments);

  // Send the message.
  $response = $client->sendMessage(
    $domain,
    $message,
    array(
      'attachment' => $attachment_paths
    )
  );

  // There's an error if the response is not 200.
  if ($response->http_response_code !== 200) {
    watchdog(
      'bonsai',
      'Mailgun returned an unsuccessful response code (@response_code) in a request for sending the message of node with ID "!node_id". The full body of the response is: "@response_body"',
      array(
        '!node_id'       => $node_wrapper->getIdentifier(),
        '@response_code' => $response->http_response_code,
        '@response_body' => $response->http_response_body,
      ),
      WATCHDOG_ERROR
    );
    drupal_set_message(
      t('The email service provider returned an error while sending the email, please try again. If the problem persists, please contact the site administrator.'),
      'error'
    );
  }
  // There's something wrong if the response does not contain the email ID.
  elseif (empty($response->http_response_body->id)) {
    watchdog(
      'bonsai',
      'Mailgun returned a successful response code (@response_code) in a request for sending the message of node with ID "!node_id", but did not return the ID of the email as expected. The full body of the response is: "@response_body"',
      array(
        '!node_id'       => $node_wrapper->getIdentifier(),
        '@response_code' => $response->http_response_code,
        '@response_body' => $response->http_response_body,
      ),
      WATCHDOG_ERROR
    );
    drupal_set_message(
      t('There was something wrong with the response from the email service provider and we could not validate that the email has been queue for delivery. Please contact the site administrator if it is important that the email is not sent twice, otherwise try again. If the problem persists, please contact the site administrator.'),
      'error'
    );
  }
  // Otherwise, the email was successfully queued for delivery.
  else {
    $node_wrapper->bonsai_email_id = _bonsai_email_trim_email_id($response->http_response_body->id);

    // We currently do not have confidence in extracting the date from the JSON
    // source of the email when delivery is confirmed. Until we verify the
    // format of the 'Received' header with Mailgun, we can use the current
    // timestamp - it should only be a few hundred milliseconds different than
    // the timestamp that Mailgun received the request. We can always correct
    // the values later from the JSON source, if desired.
    $node_wrapper->bonsai_timestamp = time();

    $node_wrapper->save();

    drupal_set_message(
      t('The email message has been successfully queued for delivery.'),
      'status'
    );
  }

  /**
   * @Issue(
   *   "Allow a redirect url via a query parameter to accommodate adding
   *   attachments from pages other than the node view page"
   *   type="improvement"
   *   priority="low"
   * )
   */

  // Go back to the node page.
  drupal_goto('node/' . $node_wrapper->getIdentifier());
}

function _bonsai_messages_clone_page($existing_node) {
  // Attachments are meant to be added via a POST request.
  if ($_SERVER['REQUEST_METHOD'] !== 'POST') {
    //drupal_not_found();
    //return;
  }

  // Currently only the node type provided by this module is supported.
  if (empty($existing_node) || $existing_node->type !== 'bonsai_message_email') {
    drupal_not_found();
    return;
  }

  // We have already checked whether the user has permissions to send the
  // requested message in the corresponding access callback. So let's go ahead
  // and create the cloned message.

  // Create a new node for storing the cloned message.
  $cloned_node = entity_create('node', array('type' => 'bonsai_message_email'));

  // We assign the current user as the author of the new node.
  global $user;
  $cloned_node->uid = $user->uid;

  // We'll be using an entity wrapper for getting field values more easily.
  $existing_node_wrapper = entity_metadata_wrapper('node', $existing_node);
  $cloned_node_wrapper   = entity_metadata_wrapper('node', $cloned_node);

  // We will be copying the email's content e.g. sender, recipients, subject and
  // body. The purpose of cloning is to create a new email message that will be
  // sent separately, so the source of the email will not be copied since it
  // will obtain its own when it will be delivered.
  // We will also copy the metadata, but without the 'Sent' label since the
  // cloned message will be a draft.

  $cloned_node_wrapper->bonsai_email            = $existing_node_wrapper->bonsai_email->value();
  $cloned_node_wrapper->bonsai_emails           = $existing_node_wrapper->bonsai_emails->value();
  $cloned_node_wrapper->bonsai_emails2          = $existing_node_wrapper->bonsai_emails2->value();
  $cloned_node_wrapper->bonsai_emails3          = $existing_node_wrapper->bonsai_emails3->value();
  $cloned_node_wrapper->bonsai_email_subject    = $existing_node_wrapper->bonsai_email_subject->value();
  $cloned_node_wrapper->bonsai_long_text        = $existing_node_wrapper->bonsai_long_text->value();
  $cloned_node_wrapper->bonsai_long_text2       = $existing_node_wrapper->bonsai_long_text2->value();
  $cloned_node_wrapper->bonsai_labels_ref       = $existing_node_wrapper->bonsai_labels_ref->value();
  $cloned_node_wrapper->ogmk_categories_ref     = $existing_node_wrapper->ogmk_categories_ref->value();
  $cloned_node_wrapper->ogmk_labels_ref         = $existing_node_wrapper->ogmk_labels_ref->value();
  $cloned_node_wrapper->ogmk_blog_labels_ref    = $existing_node_wrapper->ogmk_blog_labels_ref->value();
  $cloned_node_wrapper->bonsai_message_email_ref= $existing_node_wrapper->bonsai_message_email_ref->value();

  // We are not copying the user reference and title fields since they will be
  // populated anyway during execution of hook_node_presave().

  /**
   * @Issue(
   *   "Remove 'Sent' label from cloned messages"
   *   type="bug"
   *   priority="low"
   *   labels="ux"
   * )
   * @Issue(
   *   "Clone attachments as well when cloning messages"
   *   type="bug"
   *   priority="normal"
   *   labels="ux"
   * )
   */

  $cloned_node_wrapper->save();

  //
  drupal_goto('node/' . $cloned_node_wrapper->getIdentifier());
}