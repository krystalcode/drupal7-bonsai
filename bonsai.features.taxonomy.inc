<?php

/**
 * @file
 * bonsai.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function bonsai_taxonomy_default_vocabularies() {
  return array(
    'bonsai_labels' => array(
      'name' => 'Message Labels',
      'machine_name' => 'bonsai_labels',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
