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

- Support images from non public directories
- Solve further issues from the module page on drupal.org/project/galleria

HOWTO install galleria
----------------------

1. Download the Galleria Javascript library from http://galleria.aino.se/download/ and
   extract the galleria folder into your /sites/all/libraries/ directory.

2. Download and save the galleria module folder into your /sites/all/modules/ directory and 
   enable the Galleria module.

HOWTO use Galleria
------------------

a) Using Galleria with an image/nodereference field in a node:

    1. Create your gallery content type or alter an existing one.
    
    2. Add an image/nodereference field to your content type. If you choose a node reference field,
       make sure you reference a content type that has got an image field.
    
    3. Go to the Manage Display page of your content type. On your image/nodereference field in the 
       FORMAT column, choose "Galleria" as formatter in the select box. Next click on the button on 
       the right of the select box and choose your image style presets for the main image ("Zoomed $
       image style") and the preview thumbnails. If you downloaded additional themes for galleria you
       are further able to choose the theme you want to use here.
       
    4. Upload some images, add titles if you want and view the node. You should now be able see the images
       in the galleria display widget.

b) Using Galleria in a view of image fields

    1. Create a view of nodes with an image field. On the "FIELDS" panel in views set the display to "Fields"
       and add only the single target field (which has to be of type image!).
    
    2. On the "FORMAT" Panel choose Galleria as your views display format.
   
    3. Have a look at your view, it should get rendered as a galleria now.
   
Adding additional themes
------------------------

Galleria supports several additional themes which can be bought and downloaded at http://galleria.aino.se/themes/.
In order to add an additional theme just download it and copy the theme folder into your
/sites/all/libraries/galleria/themes/ folder.

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