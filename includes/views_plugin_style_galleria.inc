<?php

/**
  * Implements views_plugin_style().
  */
class views_plugin_style_galleria extends views_plugin_style {
  //TODO: add settings widgets for image styles and theme selection
  // maybe add all galleria option settings
  /**
   * Set default options
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['back_next_buttons'] = 0;

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['back_next_buttons'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display back and next buttons when the mouse is over the area.'),
      '#default_value' => $this->options['back_next_buttons'],
    );
  }
}
