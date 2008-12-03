// $Id$

Similar modules: BornFree

Differences:
- BornFree uses blocks to display images
- BornFree relies on image and image_attach to get these images

- Galleria uses the core Upload module to attach a bunch of images to a node
- It will then override the node's default display and replace the node body
  with a Galleria. Each attached image will be shown as thumbnail.
- Galleria uses Drupal theme layer properly (i.e. preprocess functions and
  a template file).
