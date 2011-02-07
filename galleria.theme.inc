<?php
// $Id $

/**
 * @file
 * Galleria theme functions.
 */
 
/**
 * Returns HTML for a Galleria image field formatter image element.
 *
 * @param $variables
 *   An associative array containing:
 *   - item: An array of image data.
 *   - image_style: An optional image style.
 *   - path: An array containing the link 'path' and link 'options'.
 *
 * @ingroup themeable
 */
function theme_galleria_image_formatter_item($variables) {
  $item = $variables['item'];
  $node = $variables['node'];
  
  $image = array(
    'path' => $item['uri'],
    'alt' => $item['alt'],
    'title' => $item['title'],
    'style_name' => $variables['galleria_zoom_style'],
  );
  
  // If the title is empty use alt or the node title in that order.
  if (empty($image['title'])) {
    if (!empty($image['alt'])) {
      $image['title'] = $image['alt'];
    }
    elseif (!empty($node->title)) {
      $image['title'] = $node->title;
    }
  }

  return theme('galleria_imagefield', array('image' => $image, 'path' => $path, 'title' => $image['title'],));
}

/**
 * Returns HTML for an image using a specific Colorbox image style.
 *
 * @param $variables
 *   An associative array containing:
 *   - style_name: The name of the style to be used to alter the original image.
 *   - path: The path of the image file relative to the Drupal files directory.
 *     This function does not work with images outside the files directory nor
 *     with remotely hosted images.
 *   - alt: The alternative text for text-based browsers.
 *   - title: The title text is displayed when the image is hovered in some
 *     popular browsers.
 *   - gid: Gallery id.
 *   - attributes: Associative array of attributes to be placed in the img tag.
 *   - getsize: If set to TRUE, the image's dimension are fetched and added as
 *     width/height attributes.
 *
 * @ingroup themeable
 */
function theme_galleria_imagefield($variables) { 

  if (!empty($variables['image']['style_name'])) {
    $image = theme('image_style', $variables['image']);
  }
  else {
    $image = theme('image', $variables['image']);
  }

  return $image;
}

/**
 * Preprocess variables for the galleria-insert-image.tpl.php file.
 * 
 * @param $variables
 *   An associative array containing:
 *   - item: The complete item being inserted.
*/
function template_preprocess_galleria_insert_image(&$variables) {
  $variables['file'] = file_load($variables['fid']);
  $variables['image_path'] = image_style_url($variables['style_name'], $variables['file']->uri);
}

/**
 * Preprocess variables for the galleria-container.tpl.php file.
 * 
 * @param $variables
 *   An associative array containing:
 *   - images: array of image data containing all images of the node
 */
function template_preprocess_galleria_container(&$variables) {
  // get the path of the public files dir
  $basepath = '/' . variable_get('file_public_path', '/sites/default/files') . '/';
 
  // get the subdir if image files are stored in one
  $filepath = substr($variables['images'][0]['#item']['uri'], 9);
  $lastpos = strrpos($filepath, '/');
  $filepath = substr($filepath, 0, $lastpos);
  $path = $basepath;
  
  // don't add a 2nd trailing slash if no subdir was configured 
  $path .= (!empty($filepath)) ? $filepath . '/' : '';
  $variables['path'] = $path;
}