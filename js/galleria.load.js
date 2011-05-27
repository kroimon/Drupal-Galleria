(function ($) {

  Drupal.behaviors.galleria = {
    attach: function(context, settings) {
	    var opt = {
		    transition:'fadeslide',
		    overlay_opacity:0.85,
		    show_imagenav:true,
		    clicknext:true,
		    queue:false,
		    preload:3,
		    show_counter:true,
		    //autoplay:10000,
		    max_scale_ratio: 1,
		    //min_scale_ratio: 1,
		    show_info:true
	    };
	    jQuery('.galleria-content', context).galleria(opt);
    }
  }
})(jQuery);
