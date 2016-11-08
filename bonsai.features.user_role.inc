<?php
/**
 * @file
 * bonsai.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function bonsai_user_default_roles() {
  $roles = array();

  // Exported role: bonsai administrator.
  $roles['bonsai administrator'] = array(
    'name' => 'bonsai administrator',
    'weight' => 4,
  );

  // Exported role: bonsai user.
  $roles['bonsai user'] = array(
    'name' => 'bonsai user',
    'weight' => 5,
  );

  return $roles;
}
