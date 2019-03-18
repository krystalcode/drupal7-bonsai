<?php
/**
 * @file
 * bonsai.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function bonsai_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'bonsai_messages_email';
  $view->description = '';
  $view->tag = 'bonsai, email, support';
  $view->base_table = 'node';
  $view->human_name = 'Bonsai Messages';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Email Messages';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'have the bonsai user role';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '48';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_table_plugin_style';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="alert alert-warning"><span class="fa fa-exclamation"></span> There are no messages in the Inbox folder at the moment. Messages may have been moved to the Archive.</div>';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::bonsai_move_to_folder' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Subject';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: From */
  $handler->display->display_options['fields']['bonsai_email']['id'] = 'bonsai_email';
  $handler->display->display_options['fields']['bonsai_email']['table'] = 'field_data_bonsai_email';
  $handler->display->display_options['fields']['bonsai_email']['field'] = 'bonsai_email';
  /* Field: Content: Emails */
  $handler->display->display_options['fields']['bonsai_emails']['id'] = 'bonsai_emails';
  $handler->display->display_options['fields']['bonsai_emails']['table'] = 'field_data_bonsai_emails';
  $handler->display->display_options['fields']['bonsai_emails']['field'] = 'bonsai_emails';
  $handler->display->display_options['fields']['bonsai_emails']['label'] = 'To';
  $handler->display->display_options['fields']['bonsai_emails']['delta_offset'] = '0';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['bonsai_timestamp']['id'] = 'bonsai_timestamp';
  $handler->display->display_options['fields']['bonsai_timestamp']['table'] = 'field_data_bonsai_timestamp';
  $handler->display->display_options['fields']['bonsai_timestamp']['field'] = 'bonsai_timestamp';
  $handler->display->display_options['fields']['bonsai_timestamp']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Sort criterion: Content: Date (bonsai_timestamp) */
  $handler->display->display_options['sorts']['bonsai_timestamp_value']['id'] = 'bonsai_timestamp_value';
  $handler->display->display_options['sorts']['bonsai_timestamp_value']['table'] = 'field_data_bonsai_timestamp';
  $handler->display->display_options['sorts']['bonsai_timestamp_value']['field'] = 'bonsai_timestamp_value';
  $handler->display->display_options['sorts']['bonsai_timestamp_value']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bonsai_message_email' => 'bonsai_message_email',
  );
  /* Filter criterion: Content: Message Labels (bonsai_labels_ref) */
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['id'] = 'bonsai_labels_ref_tid';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['table'] = 'field_data_bonsai_labels_ref';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['field'] = 'bonsai_labels_ref_tid';

  // Restrict to messages that have the Inbox label.
  $inbox_labels = _bonsai_taxonomy_term_multiple_by_name(array('Inbox'), array('tids_only' => TRUE));
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['value'] = $inbox_labels;

  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['expose']['operator_id'] = 'bonsai_labels_ref_tid_op';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['expose']['label'] = 'Message Labels (bonsai_labels_ref)';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['expose']['operator'] = 'bonsai_labels_ref_tid_op';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['expose']['identifier'] = 'message-labesl';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['vocabulary'] = 'bonsai_labels';
  /* Filter criterion: Content: From (bonsai_email) */
  $handler->display->display_options['filters']['bonsai_email_email']['id'] = 'bonsai_email_email';
  $handler->display->display_options['filters']['bonsai_email_email']['table'] = 'field_data_bonsai_email';
  $handler->display->display_options['filters']['bonsai_email_email']['field'] = 'bonsai_email_email';
  $handler->display->display_options['filters']['bonsai_email_email']['operator'] = 'contains';
  $handler->display->display_options['filters']['bonsai_email_email']['exposed'] = TRUE;
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['operator_id'] = 'bonsai_email_email_op';
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['label'] = 'From';
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['operator'] = 'bonsai_email_email_op';
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['identifier'] = 'from';
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: To (bonsai_emails) */
  $handler->display->display_options['filters']['bonsai_emails_email']['id'] = 'bonsai_emails_email';
  $handler->display->display_options['filters']['bonsai_emails_email']['table'] = 'field_data_bonsai_emails';
  $handler->display->display_options['filters']['bonsai_emails_email']['field'] = 'bonsai_emails_email';
  $handler->display->display_options['filters']['bonsai_emails_email']['operator'] = 'contains';
  $handler->display->display_options['filters']['bonsai_emails_email']['exposed'] = TRUE;
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['operator_id'] = 'bonsai_emails_email_op';
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['label'] = 'To';
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['operator'] = 'bonsai_emails_email_op';
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['identifier'] = 'to';
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );

  /* Display: Inbox */
  $handler = $view->new_display('page', 'Inbox', 'inbox');
  $handler->display->display_options['path'] = 'bonsai/messages/email/inbox';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Inbox';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Inbox';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Archive */
  $handler = $view->new_display('page', 'Archive', 'archive');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="alert alert-warning"><span class="fa fa-exclamation"></span> There are no messages in the Archive folder at the moment.</div>';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bonsai_message_email' => 'bonsai_message_email',
  );
  /* Filter criterion: Content: Message Labels (bonsai_labels_ref) */
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['id'] = 'bonsai_labels_ref_tid';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['table'] = 'field_data_bonsai_labels_ref';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['field'] = 'bonsai_labels_ref_tid';

  // Restrict to messages that have the Archive label.
  $archive_labels = _bonsai_taxonomy_term_multiple_by_name(array('Archive'), array('tids_only' => TRUE));
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['value'] = $archive_labels;

  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['expose']['operator_id'] = 'bonsai_labels_ref_tid_op';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['expose']['label'] = 'Message Labels (bonsai_labels_ref)';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['expose']['operator'] = 'bonsai_labels_ref_tid_op';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['expose']['identifier'] = 'bonsai_labels_ref_tid';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['vocabulary'] = 'bonsai_labels';
  /* Filter criterion: Content: From (bonsai_email) */
  $handler->display->display_options['filters']['bonsai_email_email']['id'] = 'bonsai_email_email';
  $handler->display->display_options['filters']['bonsai_email_email']['table'] = 'field_data_bonsai_email';
  $handler->display->display_options['filters']['bonsai_email_email']['field'] = 'bonsai_email_email';
  $handler->display->display_options['filters']['bonsai_email_email']['operator'] = 'contains';
  $handler->display->display_options['filters']['bonsai_email_email']['exposed'] = TRUE;
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['operator_id'] = 'bonsai_email_email_op';
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['label'] = 'From';
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['operator'] = 'bonsai_email_email_op';
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['identifier'] = 'from';
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: To (bonsai_emails) */
  $handler->display->display_options['filters']['bonsai_emails_email']['id'] = 'bonsai_emails_email';
  $handler->display->display_options['filters']['bonsai_emails_email']['table'] = 'field_data_bonsai_emails';
  $handler->display->display_options['filters']['bonsai_emails_email']['field'] = 'bonsai_emails_email';
  $handler->display->display_options['filters']['bonsai_emails_email']['operator'] = 'contains';
  $handler->display->display_options['filters']['bonsai_emails_email']['exposed'] = TRUE;
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['operator_id'] = 'bonsai_emails_email_op';
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['label'] = 'To';
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['operator'] = 'bonsai_emails_email_op';
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['identifier'] = 'to';
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['path'] = 'bonsai/messages/email/archive';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Archive';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Drafts */
  $handler = $view->new_display('page', 'Drafts', 'drafts');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="alert alert-warning"><span class="fa fa-exclamation"></span> There are no messages in the Drafts folder at the moment.</div>';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['realname']['label'] = 'Author';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Subject';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: From */
  $handler->display->display_options['fields']['bonsai_email']['id'] = 'bonsai_email';
  $handler->display->display_options['fields']['bonsai_email']['table'] = 'field_data_bonsai_email';
  $handler->display->display_options['fields']['bonsai_email']['field'] = 'bonsai_email';
  /* Field: Content: Emails */
  $handler->display->display_options['fields']['bonsai_emails']['id'] = 'bonsai_emails';
  $handler->display->display_options['fields']['bonsai_emails']['table'] = 'field_data_bonsai_emails';
  $handler->display->display_options['fields']['bonsai_emails']['field'] = 'bonsai_emails';
  $handler->display->display_options['fields']['bonsai_emails']['label'] = 'To';
  $handler->display->display_options['fields']['bonsai_emails']['delta_offset'] = '0';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['bonsai_timestamp']['id'] = 'bonsai_timestamp';
  $handler->display->display_options['fields']['bonsai_timestamp']['table'] = 'field_data_bonsai_timestamp';
  $handler->display->display_options['fields']['bonsai_timestamp']['field'] = 'bonsai_timestamp';
  $handler->display->display_options['fields']['bonsai_timestamp']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '0';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bonsai_message_email' => 'bonsai_message_email',
  );
  /* Filter criterion: Content: ID (bonsai_email_id) */
  $handler->display->display_options['filters']['bonsai_email_id_value']['id'] = 'bonsai_email_id_value';
  $handler->display->display_options['filters']['bonsai_email_id_value']['table'] = 'field_data_bonsai_email_id';
  $handler->display->display_options['filters']['bonsai_email_id_value']['field'] = 'bonsai_email_id_value';
  $handler->display->display_options['filters']['bonsai_email_id_value']['operator'] = 'not empty';
  /* Filter criterion: Content: From (bonsai_email) */
  $handler->display->display_options['filters']['bonsai_email_email']['id'] = 'bonsai_email_email';
  $handler->display->display_options['filters']['bonsai_email_email']['table'] = 'field_data_bonsai_email';
  $handler->display->display_options['filters']['bonsai_email_email']['field'] = 'bonsai_email_email';
  $handler->display->display_options['filters']['bonsai_email_email']['operator'] = 'contains';
  $handler->display->display_options['filters']['bonsai_email_email']['exposed'] = TRUE;
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['operator_id'] = 'bonsai_email_email_op';
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['label'] = 'From';
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['operator'] = 'bonsai_email_email_op';
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['identifier'] = 'from';
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: To (bonsai_emails) */
  $handler->display->display_options['filters']['bonsai_emails_email']['id'] = 'bonsai_emails_email';
  $handler->display->display_options['filters']['bonsai_emails_email']['table'] = 'field_data_bonsai_emails';
  $handler->display->display_options['filters']['bonsai_emails_email']['field'] = 'bonsai_emails_email';
  $handler->display->display_options['filters']['bonsai_emails_email']['operator'] = 'contains';
  $handler->display->display_options['filters']['bonsai_emails_email']['exposed'] = TRUE;
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['operator_id'] = 'bonsai_emails_email_op';
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['label'] = 'To';
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['operator'] = 'bonsai_emails_email_op';
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['identifier'] = 'to';
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['path'] = 'bonsai/messages/email/drafts';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Drafts';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Sent */
  $handler = $view->new_display('page', 'Sent', 'sent');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="alert alert-warning"><span class="fa fa-exclamation"></span> There are no messages in the Sent folder at the moment.</div>';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Subject';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: From */
  $handler->display->display_options['fields']['bonsai_email']['id'] = 'bonsai_email';
  $handler->display->display_options['fields']['bonsai_email']['table'] = 'field_data_bonsai_email';
  $handler->display->display_options['fields']['bonsai_email']['field'] = 'bonsai_email';
  /* Field: Content: Emails */
  $handler->display->display_options['fields']['bonsai_emails']['id'] = 'bonsai_emails';
  $handler->display->display_options['fields']['bonsai_emails']['table'] = 'field_data_bonsai_emails';
  $handler->display->display_options['fields']['bonsai_emails']['field'] = 'bonsai_emails';
  $handler->display->display_options['fields']['bonsai_emails']['label'] = 'To';
  $handler->display->display_options['fields']['bonsai_emails']['delta_offset'] = '0';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['bonsai_timestamp']['id'] = 'bonsai_timestamp';
  $handler->display->display_options['fields']['bonsai_timestamp']['table'] = 'field_data_bonsai_timestamp';
  $handler->display->display_options['fields']['bonsai_timestamp']['field'] = 'bonsai_timestamp';
  $handler->display->display_options['fields']['bonsai_timestamp']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'uid';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bonsai_message_email' => 'bonsai_message_email',
  );
  /* Filter criterion: Content: Message Labels (bonsai_labels_ref) */
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['id'] = 'bonsai_labels_ref_tid';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['table'] = 'field_data_bonsai_labels_ref';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['field'] = 'bonsai_labels_ref_tid';

  // Restrict to messages that have the Sent label.
  $sent_labels = _bonsai_taxonomy_term_multiple_by_name(array('Sent'), array('tids_only' => TRUE));
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['value'] = $sent_labels;

  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['expose']['operator_id'] = 'bonsai_labels_ref_tid_op';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['expose']['label'] = 'Message Labels (bonsai_labels_ref)';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['expose']['operator'] = 'bonsai_labels_ref_tid_op';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['expose']['identifier'] = 'bonsai_labels_ref_tid';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['vocabulary'] = 'bonsai_labels';
  /* Filter criterion: Content: From (bonsai_email) */
  $handler->display->display_options['filters']['bonsai_email_email']['id'] = 'bonsai_email_email';
  $handler->display->display_options['filters']['bonsai_email_email']['table'] = 'field_data_bonsai_email';
  $handler->display->display_options['filters']['bonsai_email_email']['field'] = 'bonsai_email_email';
  $handler->display->display_options['filters']['bonsai_email_email']['operator'] = 'contains';
  $handler->display->display_options['filters']['bonsai_email_email']['exposed'] = TRUE;
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['operator_id'] = 'bonsai_email_email_op';
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['label'] = 'From';
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['operator'] = 'bonsai_email_email_op';
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['identifier'] = 'from';
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: To (bonsai_emails) */
  $handler->display->display_options['filters']['bonsai_emails_email']['id'] = 'bonsai_emails_email';
  $handler->display->display_options['filters']['bonsai_emails_email']['table'] = 'field_data_bonsai_emails';
  $handler->display->display_options['filters']['bonsai_emails_email']['field'] = 'bonsai_emails_email';
  $handler->display->display_options['filters']['bonsai_emails_email']['operator'] = 'contains';
  $handler->display->display_options['filters']['bonsai_emails_email']['exposed'] = TRUE;
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['operator_id'] = 'bonsai_emails_email_op';
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['label'] = 'To';
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['operator'] = 'bonsai_emails_email_op';
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['identifier'] = 'to';
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['path'] = 'bonsai/messages/email/sent';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Sent';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Spam */
  $handler = $view->new_display('page', 'Spam', 'spam');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="alert alert-warning"><span class="fa fa-exclamation"></span> There are no messages in the Spam folder at the moment.</div>';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bonsai_message_email' => 'bonsai_message_email',
  );
  /* Filter criterion: Content: Message Labels (bonsai_labels_ref) */
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['id'] = 'bonsai_labels_ref_tid';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['table'] = 'field_data_bonsai_labels_ref';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['field'] = 'bonsai_labels_ref_tid';

  // Restrict to messages that have the Spam label.
  $spam_labels = _bonsai_taxonomy_term_multiple_by_name(array('Spam'), array('tids_only' => TRUE));
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['value'] = $spam_labels;

  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['expose']['operator_id'] = 'bonsai_labels_ref_tid_op';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['expose']['label'] = 'Message Labels (bonsai_labels_ref)';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['expose']['operator'] = 'bonsai_labels_ref_tid_op';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['expose']['identifier'] = 'bonsai_labels_ref_tid';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['vocabulary'] = 'bonsai_labels';
  /* Filter criterion: Content: From (bonsai_email) */
  $handler->display->display_options['filters']['bonsai_email_email']['id'] = 'bonsai_email_email';
  $handler->display->display_options['filters']['bonsai_email_email']['table'] = 'field_data_bonsai_email';
  $handler->display->display_options['filters']['bonsai_email_email']['field'] = 'bonsai_email_email';
  $handler->display->display_options['filters']['bonsai_email_email']['operator'] = 'contains';
  $handler->display->display_options['filters']['bonsai_email_email']['exposed'] = TRUE;
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['operator_id'] = 'bonsai_email_email_op';
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['label'] = 'From';
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['operator'] = 'bonsai_email_email_op';
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['identifier'] = 'from';
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: To (bonsai_emails) */
  $handler->display->display_options['filters']['bonsai_emails_email']['id'] = 'bonsai_emails_email';
  $handler->display->display_options['filters']['bonsai_emails_email']['table'] = 'field_data_bonsai_emails';
  $handler->display->display_options['filters']['bonsai_emails_email']['field'] = 'bonsai_emails_email';
  $handler->display->display_options['filters']['bonsai_emails_email']['operator'] = 'contains';
  $handler->display->display_options['filters']['bonsai_emails_email']['exposed'] = TRUE;
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['operator_id'] = 'bonsai_emails_email_op';
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['label'] = 'To';
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['operator'] = 'bonsai_emails_email_op';
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['identifier'] = 'to';
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['path'] = 'bonsai/messages/email/spam';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Spam';
  $handler->display->display_options['menu']['weight'] = '4';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Labels */
  $handler = $view->new_display('page', 'Labels', 'page_5');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="alert alert-warning"><span class="fa fa-exclamation"></span> There are no messages with the selected labels at the moment.</div>';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bonsai_message_email' => 'bonsai_message_email',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: From (bonsai_email) */
  $handler->display->display_options['filters']['bonsai_email_email']['id'] = 'bonsai_email_email';
  $handler->display->display_options['filters']['bonsai_email_email']['table'] = 'field_data_bonsai_email';
  $handler->display->display_options['filters']['bonsai_email_email']['field'] = 'bonsai_email_email';
  $handler->display->display_options['filters']['bonsai_email_email']['operator'] = 'contains';
  $handler->display->display_options['filters']['bonsai_email_email']['group'] = 1;
  $handler->display->display_options['filters']['bonsai_email_email']['exposed'] = TRUE;
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['operator_id'] = 'bonsai_email_email_op';
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['label'] = 'From';
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['operator'] = 'bonsai_email_email_op';
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['identifier'] = 'from';
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: To (bonsai_emails) */
  $handler->display->display_options['filters']['bonsai_emails_email']['id'] = 'bonsai_emails_email';
  $handler->display->display_options['filters']['bonsai_emails_email']['table'] = 'field_data_bonsai_emails';
  $handler->display->display_options['filters']['bonsai_emails_email']['field'] = 'bonsai_emails_email';
  $handler->display->display_options['filters']['bonsai_emails_email']['operator'] = 'contains';
  $handler->display->display_options['filters']['bonsai_emails_email']['group'] = 1;
  $handler->display->display_options['filters']['bonsai_emails_email']['exposed'] = TRUE;
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['operator_id'] = 'bonsai_emails_email_op';
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['label'] = 'To';
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['operator'] = 'bonsai_emails_email_op';
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['identifier'] = 'to';
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Message Labels (bonsai_labels_ref) */
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['id'] = 'bonsai_labels_ref_tid';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['table'] = 'field_data_bonsai_labels_ref';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['field'] = 'bonsai_labels_ref_tid';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['group'] = 1;
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['expose']['operator_id'] = 'bonsai_labels_ref_tid_op';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['expose']['label'] = 'Message Labels';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['expose']['operator'] = 'bonsai_labels_ref_tid_op';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['expose']['identifier'] = 'bonsai_labels_ref_tid';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['type'] = 'select';
  $handler->display->display_options['filters']['bonsai_labels_ref_tid']['vocabulary'] = 'bonsai_labels';
  /* Filter criterion: Content: Product Categories (ogmk_categories_ref) */
  $handler->display->display_options['filters']['ogmk_categories_ref_tid']['id'] = 'ogmk_categories_ref_tid';
  $handler->display->display_options['filters']['ogmk_categories_ref_tid']['table'] = 'field_data_ogmk_categories_ref';
  $handler->display->display_options['filters']['ogmk_categories_ref_tid']['field'] = 'ogmk_categories_ref_tid';
  $handler->display->display_options['filters']['ogmk_categories_ref_tid']['group'] = 1;
  $handler->display->display_options['filters']['ogmk_categories_ref_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['ogmk_categories_ref_tid']['expose']['operator_id'] = 'ogmk_categories_ref_tid_op';
  $handler->display->display_options['filters']['ogmk_categories_ref_tid']['expose']['label'] = 'Product Categories';
  $handler->display->display_options['filters']['ogmk_categories_ref_tid']['expose']['operator'] = 'ogmk_categories_ref_tid_op';
  $handler->display->display_options['filters']['ogmk_categories_ref_tid']['expose']['identifier'] = 'product-categories';
  $handler->display->display_options['filters']['ogmk_categories_ref_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['ogmk_categories_ref_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['ogmk_categories_ref_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['ogmk_categories_ref_tid']['type'] = 'select';
  $handler->display->display_options['filters']['ogmk_categories_ref_tid']['vocabulary'] = 'ogmk_categories';
  /* Filter criterion: Content: Product Labels (ogmk_labels_ref) */
  $handler->display->display_options['filters']['ogmk_labels_ref_tid']['id'] = 'ogmk_labels_ref_tid';
  $handler->display->display_options['filters']['ogmk_labels_ref_tid']['table'] = 'field_data_ogmk_labels_ref';
  $handler->display->display_options['filters']['ogmk_labels_ref_tid']['field'] = 'ogmk_labels_ref_tid';
  $handler->display->display_options['filters']['ogmk_labels_ref_tid']['group'] = 1;
  $handler->display->display_options['filters']['ogmk_labels_ref_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['ogmk_labels_ref_tid']['expose']['operator_id'] = 'ogmk_labels_ref_tid_op';
  $handler->display->display_options['filters']['ogmk_labels_ref_tid']['expose']['label'] = 'Product Labels';
  $handler->display->display_options['filters']['ogmk_labels_ref_tid']['expose']['operator'] = 'ogmk_labels_ref_tid_op';
  $handler->display->display_options['filters']['ogmk_labels_ref_tid']['expose']['identifier'] = 'product-labels';
  $handler->display->display_options['filters']['ogmk_labels_ref_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['ogmk_labels_ref_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['ogmk_labels_ref_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['ogmk_labels_ref_tid']['type'] = 'select';
  $handler->display->display_options['filters']['ogmk_labels_ref_tid']['vocabulary'] = 'ogmk_labels';
  /* Filter criterion: Content: Labels (ogmk_blog_labels_ref) */
  $handler->display->display_options['filters']['ogmk_blog_labels_ref_tid']['id'] = 'ogmk_blog_labels_ref_tid';
  $handler->display->display_options['filters']['ogmk_blog_labels_ref_tid']['table'] = 'field_data_ogmk_blog_labels_ref';
  $handler->display->display_options['filters']['ogmk_blog_labels_ref_tid']['field'] = 'ogmk_blog_labels_ref_tid';
  $handler->display->display_options['filters']['ogmk_blog_labels_ref_tid']['group'] = 1;
  $handler->display->display_options['filters']['ogmk_blog_labels_ref_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['ogmk_blog_labels_ref_tid']['expose']['operator_id'] = 'ogmk_blog_labels_ref_tid_op';
  $handler->display->display_options['filters']['ogmk_blog_labels_ref_tid']['expose']['label'] = 'Blog Labels';
  $handler->display->display_options['filters']['ogmk_blog_labels_ref_tid']['expose']['operator'] = 'ogmk_blog_labels_ref_tid_op';
  $handler->display->display_options['filters']['ogmk_blog_labels_ref_tid']['expose']['identifier'] = 'blog-labels';
  $handler->display->display_options['filters']['ogmk_blog_labels_ref_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['ogmk_blog_labels_ref_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['ogmk_blog_labels_ref_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['ogmk_blog_labels_ref_tid']['type'] = 'select';
  $handler->display->display_options['filters']['ogmk_blog_labels_ref_tid']['vocabulary'] = 'ogmk_blog_labels';
  $handler->display->display_options['path'] = 'bonsai/messages/email/labels';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Labels';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Outbox */
  $handler = $view->new_display('page', 'Outbox', 'outbox');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="alert alert-warning"><span class="fa fa-exclamation"></span> There are no messages in the Outbox folder at the moment. The Outbox folder contains messages that have been queued for delivery.</div>';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '0';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bonsai_message_email' => 'bonsai_message_email',
  );
  /* Filter criterion: Content: ID (bonsai_email_id) */
  $handler->display->display_options['filters']['bonsai_email_id_value']['id'] = 'bonsai_email_id_value';
  $handler->display->display_options['filters']['bonsai_email_id_value']['table'] = 'field_data_bonsai_email_id';
  $handler->display->display_options['filters']['bonsai_email_id_value']['field'] = 'bonsai_email_id_value';
  $handler->display->display_options['filters']['bonsai_email_id_value']['operator'] = 'not empty';
  /* Filter criterion: Content: From (bonsai_email) */
  $handler->display->display_options['filters']['bonsai_email_email']['id'] = 'bonsai_email_email';
  $handler->display->display_options['filters']['bonsai_email_email']['table'] = 'field_data_bonsai_email';
  $handler->display->display_options['filters']['bonsai_email_email']['field'] = 'bonsai_email_email';
  $handler->display->display_options['filters']['bonsai_email_email']['operator'] = 'contains';
  $handler->display->display_options['filters']['bonsai_email_email']['exposed'] = TRUE;
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['operator_id'] = 'bonsai_email_email_op';
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['label'] = 'From';
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['operator'] = 'bonsai_email_email_op';
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['identifier'] = 'from';
  $handler->display->display_options['filters']['bonsai_email_email']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: To (bonsai_emails) */
  $handler->display->display_options['filters']['bonsai_emails_email']['id'] = 'bonsai_emails_email';
  $handler->display->display_options['filters']['bonsai_emails_email']['table'] = 'field_data_bonsai_emails';
  $handler->display->display_options['filters']['bonsai_emails_email']['field'] = 'bonsai_emails_email';
  $handler->display->display_options['filters']['bonsai_emails_email']['operator'] = 'contains';
  $handler->display->display_options['filters']['bonsai_emails_email']['exposed'] = TRUE;
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['operator_id'] = 'bonsai_emails_email_op';
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['label'] = 'To';
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['operator'] = 'bonsai_emails_email_op';
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['identifier'] = 'to';
  $handler->display->display_options['filters']['bonsai_emails_email']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['path'] = 'bonsai/messages/email/outbox';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Outbox';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['bonsai_messages_email'] = array(
    t('Master'),
    t('Email Messages'),
    t('more'),
    t('Filter'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('<div class="alert alert-warning"><span class="fa fa-exclamation"></span> There are no messages in the Inbox folder at the moment. Messages may have been moved to the Archive.</div>'),
    t('Subject'),
    t('From'),
    t('To'),
    t('Date'),
    t('Message Labels (bonsai_labels_ref)'),
    t('Inbox'),
    t('Archive'),
    t('<div class="alert alert-warning"><span class="fa fa-exclamation"></span> There are no messages in the Archive folder at the moment.</div>'),
    t('Drafts'),
    t('<div class="alert alert-warning"><span class="fa fa-exclamation"></span> There are no messages in the Drafts folder at the moment.</div>'),
    t('author'),
    t('Author'),
    t('Sent'),
    t('<div class="alert alert-warning"><span class="fa fa-exclamation"></span> There are no messages in the Sent folder at the moment.</div>'),
    t('Real name'),
    t('Spam'),
    t('<div class="alert alert-warning"><span class="fa fa-exclamation"></span> There are no messages in the Spam folder at the moment.</div>'),
    t('Labels'),
    t('<div class="alert alert-warning"><span class="fa fa-exclamation"></span> There are no messages with the selected labels at the moment.</div>'),
    t('Message Labels'),
    t('Product Categories'),
    t('Product Labels'),
    t('Blog Labels'),
    t('Outbox'),
    t('<div class="alert alert-warning"><span class="fa fa-exclamation"></span> There are no messages in the Outbox folder at the moment. The Outbox folder contains messages that have been queued for delivery.</div>'),
  );
  $export['bonsai_messages_email'] = $view;

  return $export;
}
