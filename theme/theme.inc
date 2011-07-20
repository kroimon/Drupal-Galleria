<?php
/**
 * @file
 * Theming functions for the Galleria module.
 * 
 * Preprocessor functions fill variables for templates and helper
 * functions to make theming easier.
 */

/**
 * Template preprocess handler for 'galleria_container' theme.
 */
function template_preprocess_galleria_container(&$vars) {
  $settings = &$vars['settings'];

  // Each Galleria instance gets a unique id
  $galleria_id = &drupal_static('galleria_id', 0);
  $vars['id'] = ++$galleria_id;

  // Attach Galleria JavaScript
  galleria_add_js($galleria_id, $settings);

  // Prepare image elements
  $items = $vars['items'];
  $vars['items'] = array();
  foreach ($items as $delta => $item) {
    $thumb_style = empty($settings['galleria_thumb_style']) ? 'galleria_thumb' : $settings['galleria_thumb_style'];
    
    // Get URL for "normal" image
    if (empty($settings['galleria_zoom_style'])) {
       $zoom_url = file_create_url($item['uri']);
    }
    else {
       $zoom_url = image_style_url($settings['galleria_zoom_style'], $item['uri']);
    }

    // Get URL for "big" image (for lightbox and fullscreen)
    if (empty($settings['galleria_big_style'])) {
      $big_url = file_create_url($item['uri']);
    }
    elseif ($settings['galleria_big_style'] != $settings['galleria_zoom_style']) {
      $big_url = image_style_url($settings['galleria_big_style'], $item['uri']);
    }

    if (!empty($big_url)) {
      $options = array(
        'attributes' => array(
          'rel' => $big_url,
        )
      );
    }
    else {
      $options = array();
    }
    $vars['items'][$delta] = array(
      '#theme' => 'image_formatter',
      '#item' => $item,
      '#image_style' => $thumb_style,
      '#path' => array(
         'path' => $zoom_url,
         'options' => $options,
      ),
    );
  }
}

/**
 * Theme 'views_view_galleria'.
 */
function theme_views_view_galleria($vars) {
  $items = array();

  $view = $vars['view'];
  $img_field_name = $vars['img_field_name'];
  foreach ($vars['rows'] as $row) {
    $lang = $row->_field_data[$view->base_field]['entity']->language;
    // omit rows without image field.
    if (!isset($row->_field_data[$view->base_field]['entity']->{$img_field_name})) {
      continue;
    }
    $item = $row->_field_data[$view->base_field]['entity']->{$img_field_name}[$lang][0];
    $items[] = $item;
  }

  return theme('galleria_container', array(
    'items' => $items,
    'settings' => $vars['options'],
  ));
}
