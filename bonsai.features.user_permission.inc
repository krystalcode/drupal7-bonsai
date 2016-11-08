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
      'bonsai user' => 'bonsai user',
    ),
    'module' => 'bonsai',
  );

  // Exported permission: 'bonsai send messages'.
  $permissions['bonsai send messages'] = array(
    'name' => 'bonsai send messages',
    'roles' => array(
      'bonsai user' => 'bonsai user',
    ),
    'module' => 'bonsai',
  );

  // Exported permission: 'bonsai view messages'.
  $permissions['bonsai view messages'] = array(
    'name' => 'bonsai view messages',
    'roles' => array(
      'bonsai user' => 'bonsai user',
    ),
    'module' => 'bonsai',
  );

  // Exported permission: 'bonsai view messages source'.
  $permissions['bonsai view messages source'] = array(
    'name' => 'bonsai view messages source',
    'roles' => array(
      'bonsai user' => 'bonsai user',
    ),
    'module' => 'bonsai',
  );

  return $permissions;
}
