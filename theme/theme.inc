<?php
// $Id:$

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
  $vars['galleria_image_source'] = $vars['view']->field['field_imagetest']->field_info['field_name'];
  
  // TODO: read the views style plugin settings or global 
  // galleria settings to find appropriate theme JS and pass
  // that value to galleria_includes()
  $includes = galleria_includes('classic');
  $vars['script_container'] = array(
    '#markup' => '',
    '#attached' => $includes,
  );
}