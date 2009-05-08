<?php
// $Id$

/**
 * @file
 * Administration callbacks for the galleria module.
 */

/**
 * Form builder. Configure gallerias.
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function galleria_admin_settings() {
  $form['galleria_admin'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#title' => t('Main options')
  );

  $form['galleria_admin']['galleria_thumb_opacity'] = array(
    '#type' => 'textfield',
    '#title' => t('Opacity of thumbnails'),
    '#size' => 15,
    '#default_value' => variable_get('galleria_thumb_opacity', 0.3),
    '#description' => t('Value from 0 .. 1'),
  );

  $form['galleria_admin']['galleria_thumb_location'] = array(
    '#type' => 'select',
    '#title' => t('Location of thumbnails'),
    '#options' => array(
      'above' => t('Above main image'),
      'below' => t('Below main image'),
    ),
    '#default_value' => variable_get('galleria_thumb_location', 'below'),
  );

  $form['galleria_admin']['galleria_show_page_warning'] = array(
    '#type' => 'checkbox',
    '#title' => t('Galleria warnings'),
    '#default_value' => variable_get('galleria_show_page_warning', 1),
    '#description' => t('Show warning and error messages on Gallerias if they aren\'t configured properly.'),
  );

  // Code based on from Taxonomy Image's ImageCache support
  // If ImageCache module is found, add its presets as available options
  // for how to display the image.
  if (module_exists('imagecache')) {
    $raw_presets = imagecache_presets();
    $presets[''] = t('None');
    foreach ($raw_presets as $preset_id => $preset_info) {
      $preset = $preset_info['presetname'];
      $presets[$preset] = $preset;
    }
    $form['galleria_imagecache'] = array(
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#title' => t('ImageCache integration')
    );

    $form['galleria_imagecache']['galleria_imagecache_preset'] = array(
      '#type' => 'select',
      '#title' => t('ImageCache gallery preset'),
      '#options' => $presets,
      '#default_value' => variable_get('galleria_imagecache_preset', ''),
    );

    $form['galleria_imagecache']['galleria_thumb_imagecache_preset'] = array(
      '#type' => 'select',
      '#title' => t('ImageCache thumbnail preset'),
      '#options' => $presets,
      '#default_value' => variable_get('galleria_thumb_imagecache_preset', ''),
    );
  }
  else {
    drupal_set_message(t('If you install the imagecache module, you will get extra options here for integration.'), 'status');
  }

  // jCarousel integration settings.
  if (module_exists('jcarousel')) {
    $form['galleria_jcarousel'] = array(
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#title' => t('jCarousel integration')
    );

    $form['galleria_jcarousel']['galleria_jcarousel'] = array(
      '#type' => 'select',
      '#title' => t('jCarousel Integration'),
      '#options' => array(
        'enabled' => t('Enabled'),
        'disabled' => t('Disabled'),
      ),
      '#default_value' => variable_get('galleria_jcarousel', 'enabled'),
    );

    $form['galleria_jcarousel']['galleria_jcarousel_vertical'] = array(
      '#type' => 'select',
      '#title' => t('Orientation'),
      '#options' => array(
        'false' => t('Horizontal'),
        'true' => t('Vertical'),
      ),
      '#default_value' => variable_get('galleria_jcarousel_vertical', 'false'),
    );

    $form['galleria_jcarousel']['galleria_jcarousel_visible'] = array(
      '#type' => 'textfield',
      '#title' => t('Limit of visible thumbnails'),
      '#size' => 15,
      '#default_value' => variable_get('galleria_jcarousel_visible', '3'),
      '#description' => t('Thumbnails will be cropped so exactly this number of thumbnails is always shown. Must be an integer greater than zero.'),
    );

    $form['galleria_jcarousel']['galleria_jcarousel_scroll'] = array(
      '#type' => 'textfield',
      '#title' => t('Scroll size'),
      '#size' => 15,
      '#default_value' => variable_get('galleria_jcarousel_scroll', '3'),
      '#description' => t('The number of thumbnails to scroll with each mouse click.'),
    );

    $form['galleria_jcarousel']['galleria_jcarousel_animation'] = array(
      '#type' => 'textfield',
      '#title' => t('Animation speed'),
      '#size' => 15,
      '#default_value' => variable_get('galleria_jcarousel_animation', 'fast'),
      '#description' => t('The speed of the scroll animation. Use "slow", "normal", "fast", or the number of milliseconds (ie. "100"). If set to 0, animation is turned off.'),
    );

    $form['galleria_jcarousel']['galleria_jcarousel_wrap'] = array(
      '#type' => 'select',
      '#title' => t('Wrap'),
      '#options' => array(
        'null' => t('None'),
        'left' => t('Left'),
        'right' => t('Right'),
        'both' => t('Both'),
      ),
      '#default_value' => variable_get('galleria_jcarousel_wrap', 'null'),
      '#description' => t('Specifies whether to wrap at the first/last item (or both) and jump back to the start/end.'),
    );
  }
  else {
    drupal_set_message(t('If you install the jCarousel module, you will get extra options here for integration.'), 'status');
  }

  drupal_set_message(t('To customize Galleria position on a page (e.g. if you want to have Galleria placed below the node body), install the CCK module and rearrange fields for the content type that has Galleria enabled.'), 'status');

  return system_settings_form($form);
}

/**
 * Validation for the administration form.
 */
function galleria_admin_settings_validate($form, &$form_state) {
  if (module_exists('jcarousel')) {
    $input_names = array(
      'visible' => t('Limit of visible thumbnails'),
      'scroll' => t('Scroll size'),
    );

    foreach ($input_names as $name => $title) {
      $value =& $form_state['values']['galleria_jcarousel_' . $name];
      if (!is_numeric($value)) {
        form_set_error('galleria_jcarousel_' . $name, t('"' . $title . '" must be an integer.'));
      }
      else {
        $value = intval($value);
      }
    }

    // The "visible" setting cannot be 0, otherwise the carousel explodes in IE.
    if ($form_state['values']['galleria_jcarousel_visible'] == 0) {
      form_set_error('galleria_jcarousel_visible', t('"Limit of visible thumbnails" must be greater than zero.'));
    }

    $animation =& $form_state['values']['galleria_jcarousel_animation'];
    switch ($animation) {
      case 'slow':
      case 'normal':
      case 'fast':
      break;
      default:
        if (!is_numeric($animation)) {
          form_set_error('galleria_jcarousel_animation', t('"Animation speed" must be "slow", "normal", "fast", or an integer value.'));
        }
        else {
          $animation = intval($animation);
        }
      break;
    }
  }
}
