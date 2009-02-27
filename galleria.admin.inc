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

  $form['galleria_thumb_opacity'] = array(
    '#type' => 'textfield',
    '#title' => t('Opacity of thumbnails'),
    '#size' => 15,
    '#default_value' => variable_get('galleria_thumb_opacity', 0.3),
    '#description' => t('Value from 0 .. 1'),
  );

  $form['galleria_show_page_warning'] = array(
    '#type' => 'checkbox',
    '#title' => t('Galleria node warning'),
    '#default_value' => variable_get('galleria_show_page_warning', 1),
    '#description' => t('Show warning when galleria node is not by itself on a page.'),
  );

  return system_settings_form($form);
}
