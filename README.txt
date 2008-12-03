// $Id$

Galleria
---------------------

This module allows users to create image galleries using the
Galleria jQuery plugin, found on the site:

http://devkick.com/lab/galleria/

It is an administrator's module, and the target audience is site builders who
want to provide a beautiful jQuery image gallery for their clients. There is
no reason why the functionality cannot be opened to end users, but it's not
a direction that I will be supporting. It would require a lot more checks
to ensure the users were behaving themselves!

Status
---------------------

A release is coming soon! Just polishing the code for a client's site,
and thereafter I'll create one. Please don't deploy on production sites yet,
unless you know exactly what you're doing and can cope with any changes I'm
liable to make in the near future.

How it works
---------------------

Galleria relies on the core upload.module to attach images to a node. It then
removes all the default node display content and replaces it with a Galleria
gallery.

1.  Choose the node type that you want converted into Gallerias. All nodes of
    this type will be converted. You'd usually make a type called "galleria".
2.  On that node's "edit content type" page, you'll have an option
    "Enable Galleria" under the "Workflow settings".
3.  On the same page, enable file uploads (Attachments).
4.  Create a new Galleria node, and attach the images using the upload files
    function.
5.  View the node, and voila, you have a Galleria!

Thickbox support
---------------------

I am adding the functionality that will allow the entire Galleria to appear
inside a Thickbox (similar to Lightbox).

Customisation
---------------------

There is a preprocess hook and a template file for all your customisation needs.
You can style the galleria by overriding the CSS.

Similar modules
---------------------

BornFree (http://drupal.org/project/bornfree) also implements the Galleria
plugin. The reasons I chose to go my own way:

- BornFree uses blocks to display images / gallerias.
- BornFree relies on image and image_attach to get these images from nodes.
- Galleria uses the core Upload module to attach a bunch of images to a node.
- Galleria uses Drupal theme layer properly (i.e. preprocess function and
  a template file). BornFree does not.
