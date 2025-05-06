<?php

/**
 * @file
 * Hooks provided by the MyAbility AI Text To Speech module.
 */

/**
 * Alter the AJAX commands invoked on successful Text To Speech generation.
 *
 * @param array $commands
 *   An array of AJAX commands to be executed.
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state.
 */
function hook_myability_ai_tts_success_ajax_commands(array &$commands, array $form, array &$form_state) {
  // Add a command to show a message.
  $commands[] = ajax_command_alert(t('Audio generation was successful!'));
}
