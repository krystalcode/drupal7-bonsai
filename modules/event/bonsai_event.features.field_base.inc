<?php

/**
 * @file
 * bonsai_event.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function bonsai_event_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'bonsai_event_id'.
  $field_bases['bonsai_event_id'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bonsai_event_id',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 998,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'bonsai_event_type'.
  $field_bases['bonsai_event_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bonsai_event_type',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        BONSAI_EVENT_TYPE_ACCEPTED => 'Accepted',
        BONSAI_EVENT_TYPE_REJECTED => 'Rejected',
        BONSAI_EVENT_TYPE_DELIVERED => 'Delivered',
        BONSAI_EVENT_TYPE_FAILED => 'Failed',
        BONSAI_EVENT_TYPE_OPENED => 'Opened',
        BONSAI_EVENT_TYPE_CLICKED => 'Clicked',
        BONSAI_EVENT_TYPE_UNSUBSCRIBED => 'Unsubscribed',
        BONSAI_EVENT_TYPE_COMPLAINED => 'Complained',
        BONSAI_EVENT_TYPE_STORED => 'Stored',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  // Exported field_base: 'bonsai_event_failed_status'.
  $field_bases['bonsai_event_failed_status'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bonsai_event_failed_status',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        BONSAI_EVENT_FAILED_STATUS_TEMPORARY => 'Temporary',
        BONSAI_EVENT_FAILED_STATUS_PERMANENT => 'Permanent',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  return $field_bases;
}
