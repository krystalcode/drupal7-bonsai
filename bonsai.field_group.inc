<?php
/**
 * @file
 * bonsai.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bonsai_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_r1c1|node|bonsai_message_email|form';
  $field_group->group_name = 'group_r1c1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bonsai_message_email';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_r1';
  $field_group->data = array(
    'label' => 'Row 1 Col 1',
    'weight' => '24',
    'children' => array(
      0 => 'bonsai_email',
      1 => 'bonsai_emails',
      2 => 'bonsai_emails2',
      3 => 'bonsai_emails3',
    ),
    'format_type' => 'bootstrap_grid_col',
    'format_settings' => array(
      'label' => 'Row 1 Col 1',
      'instance_settings' => array(
        'panelize' => '1',
        'show_heading' => '0',
        'heading_position' => '0',
        'label_element' => 'h3',
        'description_element' => 'p',
        'panel_style' => 'default',
        'bootstrap_grid_col_xs' => '12',
        'bootstrap_grid_col_sm' => '9',
        'bootstrap_grid_col_md' => '0',
        'bootstrap_grid_col_lg' => '0',
        'required_fields' => 1,
        'classes' => 'group-r1c1 field-group-bootstrap_grid_col',
        'description' => '',
      ),
    ),
  );
  $field_groups['group_r1c1|node|bonsai_message_email|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_r1|node|bonsai_message_email|form';
  $field_group->group_name = 'group_r1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bonsai_message_email';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sender & Recipients',
    'weight' => '0',
    'children' => array(
      0 => 'group_r1c1',
    ),
    'format_type' => 'bootstrap_grid_row',
    'format_settings' => array(
      'label' => 'Sender & Recipients',
      'instance_settings' => array(
        'show_heading' => '1',
        'heading_position' => '0',
        'label_element' => 'h3',
        'description_element' => 'p',
        'panelize' => '0',
        'panel_style' => 'default',
        'bootstrap_grid_col_xs' => '12',
        'bootstrap_grid_col_sm' => '3',
        'bootstrap_grid_col_md' => '0',
        'bootstrap_grid_col_lg' => '0',
        'required_fields' => 1,
        'classes' => 'group-r1 field-group-bootstrap_grid_row',
        'description' => 'The address from which the email should be send from, and the recipients. If there are users corresponding to the recipients they will be automatically detected by the system.',
      ),
    ),
  );
  $field_groups['group_r1|node|bonsai_message_email|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_r2c1|node|bonsai_message_email|form';
  $field_group->group_name = 'group_r2c1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bonsai_message_email';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_r2';
  $field_group->data = array(
    'label' => 'Row 2 Col 1',
    'weight' => '14',
    'children' => array(
      0 => 'bonsai_email_subject',
      1 => 'bonsai_long_text2',
    ),
    'format_type' => 'bootstrap_grid_col',
    'format_settings' => array(
      'label' => 'Row 2 Col 1',
      'instance_settings' => array(
        'panelize' => '1',
        'show_heading' => '0',
        'heading_position' => '0',
        'label_element' => 'h3',
        'description_element' => 'p',
        'panel_style' => 'default',
        'bootstrap_grid_col_xs' => '12',
        'bootstrap_grid_col_sm' => '9',
        'bootstrap_grid_col_md' => '0',
        'bootstrap_grid_col_lg' => '0',
        'required_fields' => 1,
        'classes' => 'group-r2c1 field-group-bootstrap_grid_col',
        'description' => '',
      ),
    ),
  );
  $field_groups['group_r2c1|node|bonsai_message_email|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_r2|node|bonsai_message_email|form';
  $field_group->group_name = 'group_r2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bonsai_message_email';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '1',
    'children' => array(
      0 => 'group_r2c1',
    ),
    'format_type' => 'bootstrap_grid_row',
    'format_settings' => array(
      'label' => 'Content',
      'instance_settings' => array(
        'show_heading' => '1',
        'heading_position' => '0',
        'label_element' => 'h3',
        'description_element' => 'p',
        'panelize' => '0',
        'panel_style' => 'default',
        'bootstrap_grid_col_xs' => '12',
        'bootstrap_grid_col_sm' => '3',
        'bootstrap_grid_col_md' => '0',
        'bootstrap_grid_col_lg' => '0',
        'required_fields' => 1,
        'classes' => 'group-r2 field-group-bootstrap_grid_row',
        'description' => 'Write the subject and the main body of the email.',
      ),
    ),
  );
  $field_groups['group_r2|node|bonsai_message_email|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_r3c1|node|bonsai_message_email|form';
  $field_group->group_name = 'group_r3c1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bonsai_message_email';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_r3';
  $field_group->data = array(
    'label' => 'Row 3 Col 1',
    'weight' => '16',
    'children' => array(
      0 => 'bonsai_files',
      1 => 'bonsai_images',
    ),
    'format_type' => 'bootstrap_grid_col',
    'format_settings' => array(
      'label' => 'Row 3 Col 1',
      'instance_settings' => array(
        'panelize' => '1',
        'show_heading' => '0',
        'heading_position' => '0',
        'label_element' => 'h3',
        'description_element' => 'p',
        'panel_style' => 'default',
        'bootstrap_grid_col_xs' => '12',
        'bootstrap_grid_col_sm' => '9',
        'bootstrap_grid_col_md' => '0',
        'bootstrap_grid_col_lg' => '0',
        'required_fields' => 1,
        'classes' => 'group-r3c1 field-group-bootstrap_grid_col',
        'description' => '',
      ),
    ),
  );
  $field_groups['group_r3c1|node|bonsai_message_email|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_r3|node|bonsai_message_email|form';
  $field_group->group_name = 'group_r3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bonsai_message_email';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Attachments',
    'weight' => '2',
    'children' => array(
      0 => 'group_r3c1',
    ),
    'format_type' => 'bootstrap_grid_row',
    'format_settings' => array(
      'label' => 'Attachments',
      'instance_settings' => array(
        'show_heading' => '1',
        'heading_position' => '0',
        'label_element' => 'h3',
        'description_element' => 'p',
        'panelize' => '0',
        'panel_style' => 'default',
        'bootstrap_grid_col_xs' => '12',
        'bootstrap_grid_col_sm' => '3',
        'bootstrap_grid_col_md' => '0',
        'bootstrap_grid_col_lg' => '0',
        'required_fields' => 1,
        'classes' => 'group-r3 field-group-bootstrap_grid_row',
        'description' => 'You may also add file or image attachments to accompany the message when sent to the recipients.',
      ),
    ),
  );
  $field_groups['group_r3|node|bonsai_message_email|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_r4c1|node|bonsai_message_email|form';
  $field_group->group_name = 'group_r4c1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bonsai_message_email';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_r4';
  $field_group->data = array(
    'label' => 'Row 4 Col 1',
    'weight' => '31',
    'children' => array(
      0 => 'bonsai_labels_ref',
      1 => 'ogmk_labels_ref',
      2 => 'ogmk_blog_labels_ref',
      3 => 'ogmk_categories_ref',
    ),
    'format_type' => 'bootstrap_grid_col',
    'format_settings' => array(
      'label' => 'Row 4 Col 1',
      'instance_settings' => array(
        'panelize' => '1',
        'show_heading' => '0',
        'heading_position' => '0',
        'label_element' => 'h3',
        'description_element' => 'p',
        'panel_style' => 'default',
        'bootstrap_grid_col_xs' => '12',
        'bootstrap_grid_col_sm' => '9',
        'bootstrap_grid_col_md' => '0',
        'bootstrap_grid_col_lg' => '0',
        'required_fields' => 1,
        'classes' => 'group-r4c1 field-group-bootstrap_grid_col',
        'description' => '',
      ),
    ),
  );
  $field_groups['group_r4c1|node|bonsai_message_email|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_r4|node|bonsai_message_email|form';
  $field_group->group_name = 'group_r4';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bonsai_message_email';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '3',
    'children' => array(
      0 => 'group_r4c1',
    ),
    'format_type' => 'bootstrap_grid_row',
    'format_settings' => array(
      'label' => 'Metadata',
      'instance_settings' => array(
        'show_heading' => '1',
        'heading_position' => '0',
        'label_element' => 'h3',
        'description_element' => 'p',
        'panelize' => '0',
        'panel_style' => 'default',
        'bootstrap_grid_col_xs' => '12',
        'bootstrap_grid_col_sm' => '3',
        'bootstrap_grid_col_md' => '0',
        'bootstrap_grid_col_lg' => '0',
        'required_fields' => 1,
        'classes' => 'group-r4 field-group-bootstrap_grid_row',
        'description' => 'You may categorise messages using categories and labels. The Message Labels can play a role similar to traditional mail folders e.g. Inbox, Sent, Archive etc. or they can be custom labels that make sense to your team. You may use the Product Categories/Labels and the Blog Labels for messages that are relevant to the corresponding categories for better integration with the marketplace and the blog.',
      ),
    ),
  );
  $field_groups['group_r4|node|bonsai_message_email|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Attachments');
  t('Content');
  t('Metadata');
  t('Row 1 Col 1');
  t('Row 2 Col 1');
  t('Row 3 Col 1');
  t('Row 4 Col 1');
  t('Sender & Recipients');

  return $field_groups;
}
