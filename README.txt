// $Id$

Galleria
---------------------

This module allows users to create image galleries using the Galleria jQuery plugin, found on the site:

http://devkick.com/lab/galleria/

It is an administrator's module, and the target audience is site builders who want to provide a beautiful jQuery image gallery for their clients.

How it works
---------------------

Galleria relies on the core upload.module. You attach your images to a node, and when you display it, the module replaces the attachment list with a Galleria.

1.  Choose the node type that you want converted into Gallerias. All nodes of this type will be converted. You'd usually make a type called "galleria".
2.  On that node's "edit content type" page, you'll have an option "Enable Galleria" under the "Workflow settings".
3.  On the same page, enable file uploads (Attachments).
4.  Create a new Galleria node, and attach the images using the upload files function.
5.  View the node, and voila, you have a Galleria!

Thickbox support
---------------------

You can have your Galleria open inside a thickbox. Just use the theme function:

theme('galleria_thickbox_link', $nid, $width, $height, $text);

This will give you an anchor link to the Galleria with node id "$nid". Clicking the link opens a thickbox containing the Galleria. This is done by requesting an iFrame from the module.

Note that the file thickbox-compressed.js that is included in the module has a one-line change (dynamic path to the loadingAnimation.gif file), so don't replace it without preserving this change.

Customisation
---------------------

There is a preprocess hook and a template file for all your customisation needs. You can style the galleria by overriding the CSS.

Similar modules
---------------------

BornFree (http://drupal.org/project/bornfree) also implements the Galleria
plugin. The reasons I chose to go my own way:

- BornFree uses blocks to display images / gallerias.
- BornFree relies on image and image_attach to get these images from nodes.
- Galleria uses the core Upload module to attach a bunch of images to a node.
- Galleria uses Drupal theme layer properly (i.e. preprocess function and
  a template file). BornFree does not.

