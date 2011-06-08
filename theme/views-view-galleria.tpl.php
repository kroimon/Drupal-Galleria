<?php
/**
 * @file
 * Print the wrapper markup for Galleria views.
 *
 * @ingroup views_templates
 */
$field_data_key = 'field_data_' . $galleria_image_source . '_node_values';
print render($script_container);
?>
<div class="galleria-content clearfix">
  <?php foreach ($rows as $key => $row) : ?>
    <div class="field-item">
      <img src="<?php print file_create_url($row->{$field_data_key}[0]['uri']); ?>" 
           title="<?php $row->{$field_data_key}[0]['title']; ?>" 
           alt="<?php $row->{$field_data_key}[0]['alt']; ?>" 
      />
    </div>
  <?php endforeach; ?>
</div>