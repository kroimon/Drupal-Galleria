<?php
/*
 * Implements hook_views_plugins()
 * 
 * This function annnounces the style plugin for galleria views
 */
function galleria_views_plugins() {
  $path = drupal_get_path('module', 'galleria');
  $views_path = drupal_get_path('module', 'views');
  require_once DRUPAL_ROOT . '/' . "./$path/theme.inc";
  
  $data = array(
    'module' => 'galleria', // This just tells our themes are elsewhere.
    'style' => array(
      // Style plugin for the navigation.
      'galleria' => array(
        'title' => t('Galleria'),
        'help' => t('Display the results as a galleria image gallery.'),
        'handler' => 'views_plugin_style_galleria',
        'path' => $path,
        'theme' => 'views_view_galleria',
        'theme file' => 'theme.inc',
        'theme path' => "$path",
        'uses row plugin' => FALSE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
        'even empty' => FALSE,
      ),
    ),
  );
  return $data;
}