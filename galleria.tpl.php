<?php
// $Id$

/**
 * @file
 * Default output for a galleria node.
 */

?>
<div id="galleria-content">
  <?php print $gallery; ?>
  <div class="galleria-nav">
    <a onclick="$.galleria.prev(); return false;" href="#"><< previous</a>
    |
    <a onclick="$.galleria.next(); return false;" href="#">next >></a>
  </div>
</div>
<div>
<a href="#TB_inline?height=700&width=600&inlineId=galleria-content" class="thickbox">Show hidden modal content.</a>
</div>
