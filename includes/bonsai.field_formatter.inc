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
    'bonsai_entity_email' => array(
      'label' => t('Full email format'),
      'field types' => array('entityreference'),
      'settings' => array(
        'mode' => 'mailto',
        'field' => '',
        'no_access_skip' => TRUE,
      ),
    ),
  ];
}

/**
 * Implements hook_field_formatter_prepare_view().
 */
function bonsai_field_formatter_prepare_view($entity_type, $entities, $field, $instances, $langcode, &$items, $displays) {
  /**
   * @Issue(
   *   "Check if getting the formatter type from the first display item is
   *   always correct in hook_field_formatter_prepare_view"
   *   type="bug"
   *   priority="normal"
   * )
   */
  $display = current($displays);
  $function = '_bonsai_field_formatter_prepare_view__' . $display['type'];
  if (function_exists($function)) {
    return $function($entity_type, $entities, $field, $instances, $langcode, $items, $displays);
  }
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
 * Implements hook_field_formatter_settings_form() via
 * bonsai_field_formatter_settings_form().
 */
function _bonsai_field_formatter_settings_form__bonsai_entity_email($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $element['field'] = array(
    '#title' => t('Email field'),
    '#description' => t('The entity field containing the email that should be used. The entity sould contain at least one field of type "email", unless it is a user entity where the field can be omitted. In that case, the default user mail will be used.'),
    '#type' => 'select',
    '#default_value' => $settings['field'],
    '#options' => array(
    ),
  );

  $element['mode'] = array(
    '#title' => t('Display the email as:'),
    '#type' => 'select',
    '#default_value' => $settings['mode'],
    '#options' => array(
      'mailto' => 'Mail-to link',
      'link' => 'Link to the referenced entity',
      'text' => 'Plain text',
    ),
  );

  $element['no_access_skip'] = array(
    '#title' => t('Skip entities when user has no access'),
    '#description' => t('When checked, entities that the user has no access to (view or update) will not be rendered at all. When unchecked, and the "link" mode is selected, they will be rendered as plain text, otherwise they will be rendered as normal.'),
    '#type' => 'checkbox',
    '#default_value' => $settings['no_access_skip'],
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
 * Implements hook_field_formatter_settings_summary() via
 * bonsai_field_formatter_settings_summary().
 */
function _bonsai_field_formatter_settings_summary__bonsai_entity_email($field, $instance, $view_mode) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $summary = array();

  if ($settings['field']) {
    $summary[] = t('Use the email contained in the @field', array('@field' => $settings['field']));
  }
  elseif ($field['settings']['target_type'] === 'user') {
    $summary[] = t('Use the default user mail');
  }

  switch ($settings['mode']) {
    case 'mailto':
      $summary[] = t('Display as a mail-to link');
      break;
    case 'link':
      $summary[] = t('Display as a link to the referenced entity');
      break;
    case 'text':
      $summary[] = t('Display as plain text');
      break;
  }

  if ($settings['no_access_skip']) {
    $summary[] = t('Skip entities that the user does not have access to');
  }
  else {
    $summary[] = t('Do not skip entities that the user does not have access to');
  }

  return implode('<br />', $summary);
}

/**
 * Implements hook_field_formatter_prepare_view() via
 * bonsai_field_formatter_prepare_view().
 */
function _bonsai_field_formatter_prepare_view__bonsai_entity_email($entity_type, $entities, $field, $instances, $langcode, &$items, $displays) {
  entityreference_field_formatter_prepare_view($entity_type, $entities, $field, $instances, $langcode, $items, $displays);
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

/**
 * Implements hook_field_formatter_view() via bonsai_field_formatter_view().
 */
function _bonsai_field_formatter_view__bonsai_entity_email($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();

  // Rebuild the items list to contain only those with access, if the related
  // setting is set to TRUE.
  if ($display['settings']['no_access_skip']) {
    foreach ($items as $key => $item) {
      if (empty($item['access'])) {
        unset($items[$key]);
      }
    }
  }

  $handler = entityreference_get_selection_handler($field, $instance, $entity_type, $entity);

  foreach ($items as $delta => $item) {
    $label = check_plain($handler->getLabel($item['entity']));
    $email = '';
    if ($field['settings']['target_type'] === 'user') {
      $email = $item['entity']->mail;
    }
    /**
     * @Issue(
     *   "Fetch the email from a field, if defined"
     *   type="bug"
     *   priority="normal"
     * )
     */
    if ($email) {
      $label .= ' <' . check_plain($email) . '>';
    }

    switch ($display['settings']['mode']) {
      case 'mailto':
        $element[$delta] = array('#markup' => l($label, 'mailto:' . $label, array('HTML' => TRUE)));
        break;

      // If the link is to be displayed and the entity has a uri, display a
      // link.
      case 'link':
        // If the setting is set to not skip entities that the user does not
        // have access to, we render such entities as simple text.
        if (empty($display['settings']['no_access_skip']) && empty($item['access'])) {
          $element[$delta] = array('#markup' => check_plain($label));
        }
        // Otherwise, a) the setting is set to skip and entities that the user
        // does not have access to have been already removed from the $items
        // array, or b) the user has access to the entity and we render it
        // normally as a link. If the link fails to be generate by the
        // 'entity_uri' function, we fall back to text mode.
        else {
          $uri = entity_uri($field['settings']['target_type'], $item['entity']);
          if ($uri) {
            $element[$delta] = array('#markup' => l($label, $uri['path'], $uri['options']));
          }
          else {
            $element[$delta] = array('#markup' => check_plain($label));
          }
        }
        break;

      case 'text':
      default:
        $element[$delta] = array('#markup' => check_plain($label));
        break;
    }
  }

  return $element;
}
