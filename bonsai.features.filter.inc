<?php

/**
 * @file
 * bonsai.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function bonsai_filter_default_formats() {
  $formats = array();

  // Exported format: Email HTML.
  $formats['bonsai_html'] = array(
    'format' => 'bonsai_html',
    'name' => 'Email HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(),
  );

  return $formats;
}
