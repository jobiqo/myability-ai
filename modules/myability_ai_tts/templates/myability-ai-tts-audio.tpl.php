<?php

/**
 * @file
 * Template for rendering an audio element.
 *
 * Available variables:
 * - $file_url: The URL of the audio file.
 * - $file_mime: The MIME type of the audio file.
 * - $html_id: The HTML ID for the audio element.
 * - $label: The label for the audio element.
 */
?>
<audio controls id="<?php print check_plain($html_id); ?>" aria-label="<?php print check_plain($label); ?>">
  <source src="<?php print check_plain($file_url); ?>" type="<?php print check_plain($file_mime); ?>">
  <?php print t('Your browser does not support the audio element.'); ?>
</audio>
