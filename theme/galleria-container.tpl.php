<?php
/**
 * @file
 * Default output for a galleria node.
*/
?>
<div class="galleria-content clearfix" id="galleria-<?php print $id; ?>">
  <?php foreach ($items as $item): ?>
    <div class="field-item"><?php print render($item); ?></div>
  <?php endforeach; ?>
</div>
