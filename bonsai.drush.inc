<?php

/**
 * @file
 * Drush commands for the Bonsai module.
 */

/**
 * Implements hook_drush_command().
 */
function bonsai_drush_command() {
  $items = array();

  // Message commands.
  $items['bonsai-messages-incoming'] = array(
    'aliases' => array('bmi'),
    'description' => 'Fetches incoming messages.',
    'options' => array(),
    'arguments' => array(),
    'examples' => array(),
    'drupal dependencies' => array(),
  );

  $items['bonsai-messages-delivered'] = array(
    'aliases' => array('bmd'),
    'description' => 'Fetches delivered messages.',
    'options' => array(),
    'arguments' => array(),
    'examples' => array(),
    'drupal dependencies' => array(),
  );

  return $items;
}

/**
 * Fetches incoming messages.
 */
function drush_bonsai_messages_incoming() {
  $domains = variable_get('bonsai_domains');
  if (!$domains) {
    _bonsai_cron__bonsai_messages_incoming();
    return;
  }

  foreach ($domains as $domain => $api_key) {
    _bonsai_cron__bonsai_messages_incoming($domain, $api_key);
  }
}

/**
 * Updates delivered messages.
 */
function drush_bonsai_messages_delivered() {
  $domains = variable_get('bonsai_domains');
  if (!$domains) {
    _bonsai_cron__bonsai_messages_delivered();
    return;
  }

  foreach ($domains as $domain => $api_key) {
    _bonsai_cron__bonsai_messages_delivered($domain, $api_key);
  }
}
