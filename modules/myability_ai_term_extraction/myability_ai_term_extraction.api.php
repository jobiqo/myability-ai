<?php

/**
 * @file
 * API documentation for the MyAbility AI Term Extraction module.
 */

/**
 * Alter the source text before term extraction.
 *
 * @param string $source_text
 *   Reference to the source text that will be used for term extraction.
 * @param object $entity
 *   The entity from which the source text is derived (e.g., node, user).
 * @param \MyabilityAITermExtractionConfig $config
 *   Configuration object for term extraction.
 *
 * @return void
 */
function hook_myability_ai_term_extraction_source_text_alter(string &$source_text, object $entity, MyabilityAITermExtractionConfig $config): void {
  $source_text = strip_tags($source_text);
}

/**
 * Alter the decision to perform term extraction on an entity.
 *
 * @param bool $should_extract
 *   Reference to a boolean indicating whether extraction should be performed.
 * @param object $entity
 *   The entity for which term extraction is being considered.
 * @param string $type
 *   The type of the entity (e.g., 'node', 'user').
 * @param MyabilityAITermExtractionConfig $config
 *   Configuration object for term extraction.
 *
 * @return void
 */
function hook_myability_ai_term_extraction_should_extract_alter(bool &$should_extract, object $entity, string $type, MyabilityAITermExtractionConfig $config): void {
  if ($type === 'node') {
    $should_extract = FALSE;
  }
}
