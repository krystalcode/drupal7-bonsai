<?php

/**
 * @file
 * bonsai.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function bonsai_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:bonsai_group_email:access authoring options of bonsai_message_email content'
  $permissions['node:bonsai_group_email:access authoring options of bonsai_message_email content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:bonsai_group_email:access publishing options of bonsai_message_email content'
  $permissions['node:bonsai_group_email:access publishing options of bonsai_message_email content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:bonsai_group_email:add user'
  $permissions['node:bonsai_group_email:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:bonsai_group_email:administer group'
  $permissions['node:bonsai_group_email:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:bonsai_group_email:approve and deny subscription'
  $permissions['node:bonsai_group_email:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:bonsai_group_email:create bonsai_message_email content'
  $permissions['node:bonsai_group_email:create bonsai_message_email content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:bonsai_group_email:delete any bonsai_message_email content'
  $permissions['node:bonsai_group_email:delete any bonsai_message_email content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:bonsai_group_email:delete own bonsai_message_email content'
  $permissions['node:bonsai_group_email:delete own bonsai_message_email content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:bonsai_group_email:manage members'
  $permissions['node:bonsai_group_email:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:bonsai_group_email:manage permissions'
  $permissions['node:bonsai_group_email:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:bonsai_group_email:manage roles'
  $permissions['node:bonsai_group_email:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:bonsai_group_email:subscribe'
  $permissions['node:bonsai_group_email:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:bonsai_group_email:subscribe without approval'
  $permissions['node:bonsai_group_email:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:bonsai_group_email:unsubscribe'
  $permissions['node:bonsai_group_email:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:bonsai_group_email:update any bonsai_message_email content'
  $permissions['node:bonsai_group_email:update any bonsai_message_email content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:bonsai_group_email:update group'
  $permissions['node:bonsai_group_email:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:bonsai_group_email:update own bonsai_message_email content'
  $permissions['node:bonsai_group_email:update own bonsai_message_email content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:bonsai_group_email:view any unpublished bonsai_message_email content'
  $permissions['node:bonsai_group_email:view any unpublished bonsai_message_email content'] = array(
    'roles' => array(),
  );

  return $permissions;
}
