<?php

/**
 * @file
 * bonsai.field_formatter.inc
 */

/**
 * Implements hook_field_formatter_info().
 */
function bonsai_field_formatter_info() {
  return [
    'bonsai_boolean' => array(
      'label' => t('Yes/No'),
      'field types' => ['list_boolean'],
      'settings' => [],
    ),
  ];
}

/**
 * Implements hook_field_formatter_view().
 */
function bonsai_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  if ($display['type'] !== 'bonsai_boolean') {
    return [];
  }

  $element = [];

  foreach ($items as $delta => $item) {
    $element[$delta] = array(
      '#markup' => $item['value'] ? 'Yes' : 'No',
    );
  }

  return $element;
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function bonsai_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  if ($instance['display'][$view_mode]['type'] !== 'bonsai_boolean') {
    return [];
  }

  return [];
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function bonsai_field_formatter_settings_summary($field, $instance, $view_mode) {
  if ($instance['display'][$view_mode]['type'] !== 'bonsai_boolean') {
    return '';
  }

  return '';
}
