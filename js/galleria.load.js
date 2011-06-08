(function ($) {
  Drupal.behaviors.galleria = {
    attach: function(context, settings) {
      Galleria.loadTheme(Drupal.settings.galleria.themepath);
	  jQuery('.galleria-content', context).galleria(Drupal.settings.galleria.opt);
    }
  }
})(jQuery);
