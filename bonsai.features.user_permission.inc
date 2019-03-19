<?php

/**
 * @file
 * bonsai.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function bonsai_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'bonsai fetch attachments'.
  $permissions['bonsai fetch attachments'] = array(
    'name' => 'bonsai fetch attachments',
    'roles' => array(
      'bonsai administrator' => 'bonsai administrator',
      'bonsai user' => 'bonsai user',
    ),
    'module' => 'bonsai',
  );

  // Exported permission: 'bonsai send any messages'.
  $permissions['bonsai send any messages'] = array(
    'name' => 'bonsai send any messages',
    'roles' => array(
      'bonsai administrator' => 'bonsai administrator',
    ),
    'module' => 'bonsai',
  );

  // Exported permission: 'bonsai send own messages'.
  $permissions['bonsai send own messages'] = array(
    'name' => 'bonsai send own messages',
    'roles' => array(
      'bonsai administrator' => 'bonsai administrator',
      'bonsai user' => 'bonsai user',
    ),
    'module' => 'bonsai',
  );

  // Exported permission: 'bonsai view any published messages'.
  $permissions['bonsai view any published messages'] = array(
    'name' => 'bonsai view any published messages',
    'roles' => array(
      'bonsai administrator' => 'bonsai administrator',
      'bonsai user' => 'bonsai user',
    ),
    'module' => 'bonsai',
  );

  // Exported permission: 'bonsai view any unpublished messages'.
  $permissions['bonsai view any unpublished messages'] = array(
    'name' => 'bonsai view any unpublished messages',
    'roles' => array(
      'bonsai administrator' => 'bonsai administrator',
      'bonsai user' => 'bonsai user',
    ),
    'module' => 'bonsai',
  );

  // Exported permission: 'bonsai view messages source'.
  $permissions['bonsai view messages source'] = array(
    'name' => 'bonsai view messages source',
    'roles' => array(
      'bonsai administrator' => 'bonsai administrator',
      'bonsai user' => 'bonsai user',
    ),
    'module' => 'bonsai',
  );

  // Exported permission: 'bonsai view own unpublished messages'.
  $permissions['bonsai view own unpublished messages'] = array(
    'name' => 'bonsai view own unpublished messages',
    'roles' => array(
      'bonsai administrator' => 'bonsai administrator',
      'bonsai user' => 'bonsai user',
    ),
    'module' => 'bonsai',
  );

  // Exported permission: 'create bonsai_message_email content'.
  $permissions['create bonsai_message_email content'] = array(
    'name' => 'create bonsai_message_email content',
    'roles' => array(
      'bonsai administrator' => 'bonsai administrator',
      'bonsai user' => 'bonsai user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any bonsai_message_email content'.
  $permissions['delete any bonsai_message_email content'] = array(
    'name' => 'delete any bonsai_message_email content',
    'roles' => array(
      'bonsai administrator' => 'bonsai administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own bonsai_message_email content'.
  $permissions['delete own bonsai_message_email content'] = array(
    'name' => 'delete own bonsai_message_email content',
    'roles' => array(
      'bonsai administrator' => 'bonsai administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any bonsai_message_email content'.
  $permissions['edit any bonsai_message_email content'] = array(
    'name' => 'edit any bonsai_message_email content',
    'roles' => array(
      'bonsai administrator' => 'bonsai administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own bonsai_message_email content'.
  $permissions['edit own bonsai_message_email content'] = array(
    'name' => 'edit own bonsai_message_email content',
    'roles' => array(
      'bonsai administrator' => 'bonsai administrator',
      'bonsai user' => 'bonsai user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
