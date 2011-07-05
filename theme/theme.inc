<?php
/**
 * @file theme.inc
 *
 * An array of preprocessors to fill variables for templates and helper
 * functions to make theming easier.
 */

/**
 * Prepares a view to display as a galleria image gallery.
 */
function template_preprocess_views_view_galleria(&$vars) {

  // extract the field name of the image containing field
  $img_field_name = array_keys($vars['view']->field);
  $vars['galleria_image_source'] = $img_field_name[0];

  // TODO: read the views style plugin settings or global
  // galleria settings to find appropriate theme JS and pass
  // that value to galleria_attachments()
  $attachments = galleria_attachments('classic');
  $vars['script_container'] = array(
    '#markup' => '',
    '#attached' => $attachments,
  );

  // read out the image style that was selected in the image field
  // of the view, default to galleria_zoom if none was selected yet
  $image_style = $vars['view']->field[$img_field_name[0]]->options['settings']['image_style'];
  $image_style = (empty($image_style)) ? 'galleria_zoom' : $image_style;

  // prepare image elements ready to render
  foreach ($vars['rows'] as $key => $data) {
    $lang = $data->_field_data['nid']['entity']->language;
    $item = $data->_field_data['nid']['entity']->{$img_field_name[0]}[$lang][0];
    $zoom_url = image_style_url($image_style, $item['uri']);

    $vars['galleria_elements']['#items'][$key] = array(
      '#theme' => 'image_formatter',
      '#item' => $item,
      '#image_style' => $image_style,
      '#path' => array(
         'path' => $zoom_url,
         'options' => array(),
      ),
    );
  }
}
