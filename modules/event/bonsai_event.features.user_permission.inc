<?php

/**
 * @file
 * bonsai_event.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function bonsai_event_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create bonsai_message_event content'.
  $permissions['create bonsai_message_event content'] = array(
    'name' => 'create bonsai_message_event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any bonsai_message_event content'.
  $permissions['delete any bonsai_message_event content'] = array(
    'name' => 'delete any bonsai_message_event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own bonsai_message_event content'.
  $permissions['delete own bonsai_message_event content'] = array(
    'name' => 'delete own bonsai_message_event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any bonsai_message_event content'.
  $permissions['edit any bonsai_message_event content'] = array(
    'name' => 'edit any bonsai_message_event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own bonsai_message_event content'.
  $permissions['edit own bonsai_message_event content'] = array(
    'name' => 'edit own bonsai_message_event content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
