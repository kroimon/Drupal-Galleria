MISSING Features FROM D6
------------------------
- No jCarousel support
- No Lightbox2 support (missing dep)
- No administer settings page
- No administer permission
- No galleria messages
- Also note that images within a private dir will not be processed yet
- File extensions are no longer checked in the module code because the extensions
  can be narrowed down in the field form of the image field (see 'Allowed file extensions' textfield)

TODO's
------
- Use JS library includes like jquery_plugin or drupal_add_library
- Support images from non public directories

HOWTO Install Galleria
---------------------

1. Install and enable Galleria. Make sure the Image module is installed and enabled (Core module in drupal 7).

2. Create your gallery content type or alter an existing one.

3. Add an image field to your content type.

4. Go to the Manage Display page of your content type. On your image field in the FORMAT column,
   choose "Galleria" as formatter in the select box. Next click on the button on the right of the 
   select box and choose your image style presets for the main image ("Zoomed image style") and the 
   preview thumbnails.
   
5. Upload some images, add titles if you want and view the node. You should now see the images in the
   galleria display widget.

Image style presets support
---------------------------

Galleria provides 2 default image styles: galleria_zoom and galleria_thumb, feel free to adapt them to 
your needs or create your own. To activate a preset follow the instruction in point #4 (see above).

Titles/Descriptions on images
-----------------------------

If you want to display a caption above your images within the Galleria check the "Enable Title field" 
on the create/edit form of your image field (reachable on "Manage Fields" page of your content type.
After you uploaded an image you can now enter the caption/title on the corresponding image right under
the file upload widget.

Limit file formats
------------------

If you want to limit the possible image formats you can do so by entering the desired file extensions
in the "Allowed file extensions" textfield on the create/edit form of your image field.

Custom theming
--------------

There are preprocess hooks and template files for all your customisation needs. To change the general size of the entire
Galleria just adapt the class .galleria-content in the file galleria/galleria.container.css. You can style the galleria by overriding the 
CSS in the file galleria.classic.css within the galleria/js/themes/classic folder. There is no need to edit anything 
beyond that.