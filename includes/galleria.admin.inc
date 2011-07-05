<?php
/**
 * @file
 * Administrative page callbacks for the galleria module.
 */

/**
 * General configuration form for controlling the galleria behaviour.
 */
function galleria_admin_settings() {
  $form = array();

  $transition_options = array(
    'fade'      => t('<strong>fade:</strong> <em>crossfade betweens images</em>'),
    'flash'     => t('<strong>flash:</strong> <em>fades into background color between images</em>'),
    'pulse'     => t('<strong>pulse:</strong> <em>quickly removes the image into background color, then fades the next image</em>'),
    'slide'     => t('<strong>slide:</strong> <em>slides the images depending on image position</em>'),
    'fadeslide' => t('<strong>fadeslide:</strong> <em>fade between images and slide slightly at the same time</em>'),
  );
  $form['galleria_transition'] = array(
    '#type' => 'radios',
    '#title' => t('Transition'),
    '#description' => t('The transition that is used when displaying the images.'),
    '#options' => $transition_options,
    '#default_value' => variable_get('galleria_transition', 'fade'),
  );

  $thumbnails_options = array(
    'on'      => 'Show thumbnails',
    'off'     => 'No thumbnails',
    'numbers' => '<strong>numbers:</strong> <em>Show empty spans with numbers instead of thumbnails</em>',
    'empty'   => '<strong>empty:</strong> <em>Show empty spans with the className img instead of thumbnails</em>',
  );
  $form['galleria_thumbnails'] = array(
    '#type' => 'radios',
    '#title' => t('Show Thumbnails'),
    '#description' => t('Sets the creation of thumbnails.'),
    '#options' => $thumbnails_options,
    '#default_value' => variable_get('galleria_thumbnails', 'on'),
  );

  $form['galleria_show_imagenav'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Imagenav'),
    '#default_value' => variable_get('galleria_show_imagenav', TRUE),
    '#description' => t('Set this to false if you do not wish to display the image navigation (next/prev arrows).'),
  );

  $form['galleria_clicknext'] = array(
    '#type' => 'checkbox',
    '#title' => t('clicknext'),
    '#description' => t('This options adds a click event over the stage that navigates to the next image in the gallery. Useful for mobile browsers and other simpler applications. Note that setting this to true will disable any other links that you might have in the data object.'),
    '#default_value' => variable_get('galleria_clicknext', TRUE),
  );

  $form['galleria_queue'] = array(
    '#type' => 'checkbox',
    '#title' => t('queue'),
    '#description' => t('Galleria queues all activation clicks (next/prev & thumbnails). You can see this effect when for example clicking “next” fast many times. If you don’t want Galleria to queue, set this to false. This will make Galleria stall during anim'),
    '#default_value' => variable_get('galleria_queue', TRUE),
  );


  $form['galleria_show_counter'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Counter'),
    '#default_value' => variable_get('galleria_show_counter', TRUE),
  );

  $form['galleria_show_info'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Info'),
    '#description' => t('Disable this if you do not wish to display the caption.'),
    '#default_value' => variable_get('galleria_show_info', TRUE),
  );

  $form['galleria_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#description' => t('Set the width of your galleria display in pixels.'),
    '#element_validate' => array('_galleria_validate_numeric_element'),
    '#default_value' => variable_get('galleria_width', 450),
  );

  $form['galleria_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Height'),
    '#description' => t('Set the height of your galleria display in pixels.'),
    '#element_validate' => array('_galleria_validate_numeric_element'),
    '#default_value' => variable_get('galleria_height', 300),
  );

  $form['galleria_preload'] = array(
    '#type' => 'textfield',
    '#title' => t('Preload'),
    '#description' => t('Defines how many images Galleria should preload in advance. Please note that this only applies when you are using separate thumbnail files. Galleria always cache all preloaded images. 2 preloads the next 2 images in line, ‘all’ forces Galleria to start preloading all images. This may slow down client. 0 will not preload any images'),
    '#element_validate' => array('_galleria_validate_numeric_element'),
    '#default_value' => variable_get('galleria_preload', 3),
  );

  $form['galleria_autoplay'] = array(
    '#type' => 'textfield',
    '#title' => t('Autoplay'),
    '#description' => t('Sets Galleria to play slidehow when initialized. Value in milliseconds, for example 5000 will move forward every 5 seconds. 0 will disable autoplay'),
    '#default_value' => variable_get('galleria_autoplay', 0),
  );

  $galleria_imagecrop_options = array(
    'on'   => 'Crop',
    'off'  => 'No Crop',
    'height' => 'Crop horizontally, fill the height',
    'width'  => 'Crop vertically, fill the width',
  );
  $form['galleria_imagecrop'] = array(
    '#type' => 'radios',
    '#title' => t('Cropping'),
    '#description' => t('Defines how the main image will be cropped inside it’s container.'),
    '#options' => $galleria_imagecrop_options,
    '#default_value' => variable_get('galleria_imagecrop', 'true'),
  );

  $form['galleria_max_scale_ratio'] = array(
    '#type' => 'textfield',
    '#title' => t('Max Scale Ratio'),
    '#description' => t('Sets the maximum scale ratio for images. For example, if you don’t want Galleria to upscale any images, set this to 1. Leave empty to allow any scaling of the images.'),
    '#element_validate' => array('_galleria_validate_numeric_element'),
    '#default_value' => variable_get('galleria_max_scale_ratio', 1),
  );

  $form['galleria_min_scale_ratio'] = array(
    '#type' => 'textfield',
    '#title' => t('Min Scale Ratio'),
    '#description' => t('Sets the minimum scale ratio for images. For example, if you don’t want Galleria to downscale any images, set this to 1. Leave empty to allow any scaling of the images.'),
    '#element_validate' => array('_galleria_validate_numeric_element'),
    '#default_value' => variable_get('galleria_min_scale_ratio', 1),
  );

  $form['galleria_overlay_opacity'] = array(
    '#type' => 'textfield',
    '#title' => t('Overlay Opacity'),
    '#description' => t('This sets how much opacity the overlay should have when calling <em>showLightbox()</em>'),
    '#element_validate' => array('_galleria_validate_numeric_element'),
    '#default_value' => variable_get('galleria_overlay_opacity', 0.85),
  );

  return system_settings_form($form);
}

/**
 * Validate a form element that should have an numeric value.
 */
function _galleria_validate_numeric_element($element, &$form_state) {
  $value = $element['#value'];

  if (!empty($value) && !is_numeric($value)) {
    form_error($element, t('The value of field %name should be numeric.', array('%name' => $element['#title'])));
  }
}
