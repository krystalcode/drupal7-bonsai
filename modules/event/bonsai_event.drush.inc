<?php

/**
 * @file
 * Drush commands for the Bonsai Events module.
 */

/**
 * Implements hook_drush_command().
 */
function bonsai_event_drush_command() {
  $items = array();

  // Message commands.
  $items['bonsai-event-fetch-events'] = array(
    'aliases' => array('befe'),
    'description' => 'Fetches the latest events from the service provider.',
    'options' => array(),
    'arguments' => array(),
    'examples' => array(),
    'drupal dependencies' => array(),
  );

  return $items;
}

/**
 * Fetches the latest events from the service provider.
 */
function drush_bonsai_event_fetch_events() {
  $domains = variable_get('bonsai_domains');
  if (!$domains) {
    _bonsai_event_cron__fetch_events();
    return;
  }

  foreach ($domains as $domain => $api_key) {
    _bonsai_event_cron__fetch_events($domain, $api_key);
  }
}
