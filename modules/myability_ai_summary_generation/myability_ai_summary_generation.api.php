<?php

/**
 * @file
 * Hooks provided by the MyAbility AI Summary Generation module.
 */

/**
 * Alter the AJAX commands invoked on successful summary generation.
 *
 * @param array $commands
 *   An array of AJAX commands to be executed.
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state.
 */
function hook_myability_ai_summary_generation_success_ajax_commands(array &$commands, array $form, array &$form_state) {
  // Add a command to show a message.
  $commands[] = ajax_command_alert(t('Summary generation was successful!'));
}
