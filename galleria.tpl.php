<?php
// $Id$

/**
 * @file
 * Default output for a galleria node.
 */
?>
<div id="galleria-content">
  <?php print $gallery; ?>
    <script type="text/javascript">
      <!--//--><![CDATA[//><!--
      $('ul.gallery img').css('display', 'none');
      //--><!]]>
    </script>
  <div class="galleria-nav">
    <?php print $next_prev_links; ?>
  </div>
</div>
