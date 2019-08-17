<?php

namespace Drupal\bonsai_event\Mailgun;

// External depenencies.
use Bonsai\EventTransformerInterface;

class EventToNodeTransformer implements EventTransformerInterface {
  public function transform($event, array $options = array()) {
    // Create a node for storing the message.
    $node = entity_create('node', array('type' => 'bonsai_message_event'));

    // We always assign the superuser as the owner of the event to indicate that
    // the node was created automatically as an incoming event and not by a user
    // in the system.
    $node->uid = 1;

    // We will be using, and returning, an entity wrapper for easer field
    // handling.
    $node_wrapper = entity_metadata_wrapper('node', $node);

    // The timestamp is given as a float (i.e. with microseconds) but the field
    // requires an integer value (seconds). Convert, we don't really care about
    // microsecond accuracy.
    $node_wrapper->bonsai_timestamp = _bonsai_event_timestamp_from_json($event);

    // Event IDs are guaranteed to be unique within a day. We therefore store
    // them together with the event timestamp to make sure we create a globally
    // unique ID. We also use it as the node title that is mandatory.
    $event_id = _bonsai_event_id_from_json($event);
    $node->title = $event_id;
    $node_wrapper->bonsai_event_id = $event_id;

    // Event type.
    $node_wrapper->bonsai_event_type = _bonsai_event_type_from_json($event);

    // Recipient.
    if (isset($event->recipient)) {
      $node_wrapper->bonsai_email = $event->recipient;
    }

    // Store the reference to the message.
    if (isset($event->message->headers->{'message-id'})) {
      $message_id = $event->message->headers->{'message-id'};
      $message_node_id = _bonsai_message_node_id_by_email_id($message_id, TRUE);
      if ($message_node_id) {
        $node_wrapper->bonsai_message_email_ref = $message_node_id;
      }
    }

    // Failed status.
    if (_bonsai_event_type_from_json($event) === BONSAI_EVENT_TYPE_FAILED) {
      $node_wrapper->bonsai_event_failed_status = _bonsai_event_failed_status_from_json($event);
    }

    // Store the full JSON event.
    $node_wrapper->bonsai_json = json_encode($event);

    // Finally, set the node status to be published since events can never be
    // drafts.
    $node_wrapper->status = 1;

    return $node_wrapper;
  }
}
