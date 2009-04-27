// $Id$

var options = {
  onImage : function(image, caption, thumb) {
    // let's add some image effects for demonstration purposes
    // fade in the image & caption
    if(!($.browser.mozilla && navigator.appVersion.indexOf("Win")!=-1) ) { // FF/Win fades large images terribly slow
      image.css('display','none').fadeIn(500);
    }
    caption.css('display','none').fadeIn(500);

    // fetch the thumbnail container
    var _li = thumb.parents('li');

    // if there is only one thumbnail, hide it and
    // turn off the clickNext action on the displayed image
    if (_li.siblings('li').length == 0) {
      _li.css('display','none');
      $.galleria.clickNext = false;
    }
    else {
      // fade out inactive thumbnail
      _li.siblings().children('img.selected').fadeTo(500, Drupal.settings.thumb_opacity);

      // fade in active thumbnail
      thumb.fadeTo('fast',1).addClass('selected');

      // add a title for the clickable image
      image.attr('title','Next image >>');

      $('.galleria-nav').show();
    }
  },

  onThumb : function(thumb) {
    // thumbnail effects goes here
    // fetch the thumbnail container
    var _li = thumb.parents('li');

    // if thumbnail is active, fade all the way.
    var _fadeTo = _li.is('.active') ? 1 : Drupal.settings.thumb_opacity;

    // fade in the thumbnail when finished loading
    thumb.css({display:'none',opacity:_fadeTo}).fadeIn(1500);

    // hover effects
    thumb.hover(
      function() { thumb.fadeTo('fast', 1); },
      function() { _li.not('.active').children('img').fadeTo('fast', Drupal.settings.thumb_opacity); } // don't fade out if the parent is active
    )
  },

  history : false
};

// run Galleria in Drupal.behaviors
Drupal.behaviors.initGalleria = function(context) {
  // init on plain gallerias
  $('ul.gallery').galleria(options);

  // when the ajax call is complete, load galleria - used when viewing in a lightbox!
  $('body').bind("ajaxComplete", function() {
    // check that a lightbox with a loaded image list exists
    if ($('#lightbox ul.gallery').length > 0) {
      $('#lightbox ul.gallery').galleria(options);
    }
  });
};
