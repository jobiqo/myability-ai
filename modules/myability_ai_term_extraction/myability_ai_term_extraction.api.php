<?php

/**
 * @file
 * API documentation for the MyAbility AI Term Extraction module.
 */

function hook_myability_ai_term_extraction_source_text_alter(string &$source_text, object $entity, MyabilityAITermExtractionConfig $config) {
  // Alter the source text before term extraction.
  // For example, remove any HTML tags.
  $source_text = strip_tags($source_text);
}
