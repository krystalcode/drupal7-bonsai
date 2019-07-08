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
    'bonsai_message_email_action_buttons' => array(
      'variables' => array(
        'node' => NULL,
        'can_send' => NULL,
        'can_create_reply' => NULL,
        'can_move' => NULL,
        'can_clone' => NULL,
      ),
     'template' => 'templates/message-email-action-buttons',
    ),
    'bonsai_message_email_icons' => array(
      'variables' => array(
        'icons' => NULL,
      ),
     'template' => 'templates/message-email-icons',
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

function template_preprocess_bonsai_message_email_action_buttons(
  &$variables,
  $hook
) {
  $nid = $variables['node']->nid;
  // Prepare the links for the Reply and Reply To All buttons.
  if ($variables['can_create_reply']) {
    $link_options = array(
      'attributes' => array(
        'class' => array('btn btn-link'),
      ),
      'html' => TRUE,
      'query' => array(
        'bonsai_message_email_ref' => $nid,
        'reply' => 'sender',
      ),
    );
    $variables['reply_link'] = l(
      '<span class="fa fa-reply"></span> ' . t('Reply'),
      'node/add/bonsai-message-email',
      $link_options
    );

    $link_options['query']['reply'] = 'all';
    $variables['reply_all_link'] = l(
      '<span class="fa fa-reply-all"></span> ' . t('Reply To All'),
      'node/add/bonsai-message-email',
      $link_options
    );
  }

  if ($variables['can_move']) {
    $node_wrapper = _bonsai_ensure_node_wrapper($variables['node']);
    $current_folders = _bonsai_message_get_folder_names($node_wrapper);
    /**
     * @Issue(
     *   "Allow moving to any folder instead of just the default ones"
     *   type="improvement"
     *   priority="normal"
     *   labels="ux"
     * )
     */
    $folders = _bonsai_taxonomy_term_multiple_by_name(array('Inbox', 'Archive', 'Spam', 'Trash'));
    $move_folders = array_reduce(
      $folders,
      function ($carry, $item) use ($current_folders) {
        if (isset($carry[$item->name]) || in_array($item->name, $current_folders)) {
          return $carry;
        }

        $carry[$item->name]= $item->tid;
        return $carry;
      },
      []
    );

    if ($move_folders) {
      $variables['move_buttons'] = array();
      $icons = array(
        'Inbox' => 'envelope',
        'Archive' => 'archive',
        'Spam' => 'warning',
        'Trash' => 'trash',
      );
      foreach ($move_folders as $folder_name => $folder_tid) {
        $variables['move_buttons'][] = array(
          'tid' => $folder_tid,
          'name' => t($folder_name),
          'icon' => $icons[$folder_name],
        );
      }
    }
  }
}
