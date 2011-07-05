<?php
/**
 * @file
 * Default output for a galleria node.
*/
?>
<div class="galleria-content clearfix">
  <?php foreach ($items as $item): ?>
    <div class="field-item"><?php print render($item); ?></div>
  <?php endforeach; ?>
</div>
