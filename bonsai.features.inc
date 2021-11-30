<?php

/**
 * @file
 * bonsai.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bonsai_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function bonsai_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function bonsai_image_default_styles() {
  $styles = array();

  // Exported image style: 1080.
  $styles[1080] = array(
    'label' => 1080,
    'effects' => array(
      21 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1080,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function bonsai_node_info() {
  $items = array(
    'bonsai_message_email' => array(
      'name' => t('Email Message'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
