<?php

/**
 * @file
 * bonsai.field_formatter.inc
 */


/**
 * Hooks.
 */

/**
 * Implements hook_field_formatter_info().
 *
 * @Issue(
 *   "Move the bootstrap-related formatter to another module"
 *   type="improvement"
 *   priority="low"
 *   labels="modularity"
 * )
 */
function bonsai_field_formatter_info() {
  return [
    'bonsai_boolean' => array(
      'label' => t('Yes/No'),
      'field types' => array('list_boolean'),
      'settings' => array(),
    ),
    'bonsai_bootstrap_thumbnail' => array(
      'label' => t('Bootstrap thumbnail'),
      'field types' => array('image'),
      'settings' => array(
        'image_style' => '',
        'image_link'  => '',
        'display_caption' => TRUE,
      ),
    ),
  ];
}

/**
 * Implements hook_field_formatter_view().
 */
function bonsai_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $function = '_bonsai_field_formatter_view__' . $display['type'];
  if (function_exists($function)) {
    return $function($entity_type, $entity, $field, $instance, $langcode, $items, $display);
  }

  return array();
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function bonsai_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $function = '_bonsai_field_formatter_settings_form__' . $instance['display'][$view_mode]['type'];
  if (function_exists($function)) {
    return $function($field, $instance, $view_mode, $form, $form_state);
  }

  return array();
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function bonsai_field_formatter_settings_summary($field, $instance, $view_mode) {
  $function = '_bonsai_field_formatter_settings_summary__' . $instance['display'][$view_mode]['type'];
  if (function_exists($function)) {
    return $function($field, $instance, $view_mode);
  }

  return '';
}


/**
 * Stub hook implementations.
 */

/**
 * Implements hook_field_formatter_settings_form() via
 * bonsai_field_formatter_settings_form().
 */
function _bonsai_field_formatter_settings_form__bonsai_bootstrap_thumbnail($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $image_styles = image_style_options(FALSE, PASS_THROUGH);
  $element['image_style'] = array(
    '#title' => t('Image style'),
    '#type' => 'select',
    '#default_value' => $settings['image_style'],
    '#empty_option' => t('None (original image)'),
    '#options' => $image_styles,
  );

  $link_types = array(
    'content' => t('Content'),
    'file' => t('File'),
  );
  $element['image_link'] = array(
    '#title' => t('Link image to'),
    '#type' => 'select',
    '#default_value' => $settings['image_link'],
    '#empty_option' => t('Nothing'),
    '#options' => $link_types,
  );

  $element['display_caption'] = array(
    '#title' => t('Display image info as caption'),
    '#type' => 'checkbox',
    '#default_value' => $settings['display_caption'],
  );

  return $element;
}

/**
 * Implements hook_field_formatter_settings_summary() via
 * bonsai_field_formatter_settings_summary().
 */
function _bonsai_field_formatter_settings_summary__bonsai_bootstrap_thumbnail($field, $instance, $view_mode) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $summary = array();

  $image_styles = image_style_options(FALSE, PASS_THROUGH);
  // Unset possible 'No defined styles' option.
  unset($image_styles['']);
  // Styles could be lost because of enabled/disabled modules that defines
  // their styles in code.
  if (isset($image_styles[$settings['image_style']])) {
    $summary[] = t('Image style: @style', array('@style' => $image_styles[$settings['image_style']]));
  }
  else {
    $summary[] = t('Original image');
  }

  $link_types = array(
    'content' => t('Linked to content'),
    'file' => t('Linked to file'),
  );
  // Display this setting only if image is linked.
  if (isset($link_types[$settings['image_link']])) {
    $summary[] = $link_types[$settings['image_link']];
  }

  if ($settings['display_caption']) {
    $summary[] = t('Displaying image info as caption');
  }

  return implode('<br />', $summary);
}

/**
 * Implements hook_field_formatter_view() via bonsai_field_formatter_view().
 */
function _bonsai_field_formatter_view__bonsai_boolean($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = [];

  foreach ($items as $delta => $item) {
    $element[$delta] = array(
      '#markup' => $item['value'] ? 'Yes' : 'No',
    );
  }

  return $element;
}

/**
 * Implements hook_field_formatter_view() via bonsai_field_formatter_view().
 */
function _bonsai_field_formatter_view__bonsai_bootstrap_thumbnail($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();

  // Check if the formatter involves a link.
  if ($display['settings']['image_link'] == 'content') {
    $uri = entity_uri($entity_type, $entity);
  }
  elseif ($display['settings']['image_link'] == 'file') {
    $link_file = TRUE;
  }

  foreach ($items as $delta => $item) {
    if (isset($link_file)) {
      $uri = array(
        'path' => file_create_url($item['uri']),
        'options' => array(),
      );
    }
    $element[$delta] = array(
      '#theme' => 'bootstrap_thumbnail_formatter',
      '#item' => $item,
      '#image_style' => $display['settings']['image_style'],
      '#path' => isset($uri) ? $uri : '',
    );

    if ($display['settings']['display_caption']) {
      $element[$delta] += array(
        '#caption' => '<p>' . check_plain($item['filename']) . ', <span class="text-muted">' . $item['filemime'] . '</span>, ' . format_size($item['filesize']) . '</p>',
        '#caption_html' => TRUE,
      );
    }
  }

  return $element;
}
