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
  if (count($galleria_elements) > 0) {
    foreach ($galleria_elements as $key => $element) {
      echo '<div class="field-item">' . print render($element) . '</div>';
    }
  }
  else {
    drupal_set_message('ERROR: No images were found, please check your view results.', 'error');
  }
?>
</div>