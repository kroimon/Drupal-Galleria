<?php
/**
 * @file
 * Print the wrapper markup for Galleria views.
 *
 * @ingroup views_templates
 */
print render($script_container);
?>
<div class="galleria-content clearfix">
<?php 
  foreach ($rows as $key => $row) {
    if (property_exists($row->_field_data['nid']['entity'], $galleria_image_source)) {
      $lang = $row->_field_data['nid']['entity']->language;
      $img_data = $row->_field_data['nid']['entity']->{$galleria_image_source}[$lang][0];
      echo '
      <div class="field-item">
        <img src="' . file_create_url($img_data['uri']) . '" 
             title="' . $img_data['title'] . '" 
             alt="' . $img_data['alt'] . '" 
        />
      </div>';
    }
    else {
      drupal_set_message('Error: The provided data for this views does not contain the selected image field.', 'error');
      break;
    }
  }
?>
</div>