<?php
/**
 * @file
 * bonsai.theme.inc
 */

/**
 * Implements hook_theme().
 *
 * @Issue(
 *   "Move the bootstrap-related theme to another module"
 *   type="improvement"
 *   priority="low"
 *   labels="modularity"
 * )
 */
function bonsai_theme() {
  return array(
    'bootstrap_thumbnail_formatter' => array(
      'variables' => array(
        'item'         => NULL,
        'path'         => NULL,
        'image_style'  => NULL,
        'caption'      => NULL,
        'caption_html' => FALSE
      ),
    ),
  );
}

/**
 * Returns HTML for an bootstrap thumbnail field formatter.
 *
 * @param $variables
 *   An associative array containing:
 *   - item: Associative array of image data, which may include "uri", "alt",
 *     "width", "height", "title" and "attributes".
 *   - image_style: An optional image style.
 *   - path: An array containing the link 'path' and link 'options'.
 *   - caption: Text or HTML to be displayed as the image's caption.
 *   - caption_html: Whether the caption contains HTML.
 *
 * @ingroup themeable
 */
function theme_bootstrap_thumbnail_formatter($variables) {
  $item = $variables['item'];
  $image = array(
    'path' => $item['uri'],
  );

  if (array_key_exists('alt', $item)) {
    $image['alt'] = $item['alt'];
  }

  if (isset($item['attributes'])) {
    $image['attributes'] = $item['attributes'];
  }

  if (isset($item['width']) && isset($item['height'])) {
    $image['width'] = $item['width'];
    $image['height'] = $item['height'];
  }

  // Do not output an empty 'title' attribute.
  if (isset($item['title']) && drupal_strlen($item['title']) > 0) {
    $image['title'] = $item['title'];
  }

  if ($variables['image_style']) {
    $image['style_name'] = $variables['image_style'];
    $output = theme('image_style', $image);
  }
  else {
    $output = theme('image', $image);
  }

  // The link path and link options are both optional, but for the options to be
  // processed, the link path must at least be an empty string.
  if (isset($variables['path']['path'])) {
    $path = $variables['path']['path'];
    $options = isset($variables['path']['options']) ? $variables['path']['options'] : array();
    // When displaying an image inside a link, the html option must be TRUE.
    $options['html'] = TRUE;
    $output = l($output, $path, $options);
  }

  // The code above is directly take from the image field formatter and it
  // creates the image output. We now wrap it in a Bootstrap thumbnail, possibly
  // with a caption.
  $thumbnail = '<div class="thumbnail">';
  $thumbnail .= $output;

  // Add the caption, if we are given one.
  if (isset($variables['caption'])) {
    $thumbnail .= '<div class="caption">';

    // If the caption is not supposed to have HTML in it, we escape it.
    if (empty($variables['caption_html'])) {
      $thumbnail .= '<p>' . check_plain($variables['caption']) . '</p>';
    }
    // Otherwise, the safety of the content is the caller's responsibility.
    else {
      $thumbnail .= $variables['caption'];
    }

    $thumbnail .= '</div>';
  }

  $thumbnail .= '</div>';

  return $thumbnail;
}
