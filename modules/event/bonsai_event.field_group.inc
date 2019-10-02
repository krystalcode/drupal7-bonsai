<?php

/**
 * @file
 * bonsai_event.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bonsai_event_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_r1|node|bonsai_message_event|default';
  $field_group->group_name = 'group_r1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bonsai_message_event';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Info',
    'weight' => '0',
    'children' => array(
      0 => 'bonsai_message_email_ref',
      1 => 'bonsai_timestamp',
      2 => 'bonsai_event_id',
      3 => 'bonsai_email',
      4 => 'bonsai_event_type',
      5 => 'bonsai_event_failed_status',
    ),
    'format_type' => 'bootstrap_panel',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'show_heading' => 0,
        'heading_position' => 0,
        'panel_style' => 'default',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_r1|node|bonsai_message_event|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_r2|node|bonsai_message_event|default';
  $field_group->group_name = 'group_r2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bonsai_message_event';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Data',
    'weight' => '8',
    'children' => array(
      0 => 'bonsai_json',
    ),
    'format_type' => 'bootstrap_panel',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'show_heading' => 0,
        'heading_position' => 0,
        'panel_style' => 'default',
        'required_fields' => 1,
        'classes' => 'group-r2 field-group-bootstrap_panel',
      ),
    ),
  );
  $field_groups['group_r2|node|bonsai_message_event|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Data');
  t('Info');

  return $field_groups;
}
