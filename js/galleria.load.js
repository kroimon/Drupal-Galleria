(function ($) {
  Drupal.behaviors.galleria = {
    attach: function(context, settings) {
      jQuery('.galleria-content', context).galleria(Drupal.settings.galleria.opt);
    }
  }
})(jQuery);
