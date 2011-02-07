<?php
// $Id $

/**
 * @file
 * Default output for a galleria node.
*/
?>
<?php if ((count($images) > 0) && isset($path)): ?>
  <div class="galleria-content">
      <ul class="gallery">
      <?php foreach($images as $key => $val): ?>
        <li>
          <img src="<?php echo $path . $images[$key]['#item']['filename'] ?>"
               title="<?php echo $images[$key]['#item']['title'] ?>" />
        </li>
      <?php endforeach; ?>
      </ul>
  </div>
<?php endif; ?>