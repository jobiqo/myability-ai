<?php

/**
 * @file
 * Contains the MyabilityAITermExtractionConfig class.
 */

/**
 * Defines the MyabilityAITermExtractionConfig entity.
 */
class MyabilityAITermExtractionConfig {

  /**
   * The ID of the configuration.
   *
   * @var int
   */
  public ?int $id = NULL;

  /**
   * The source field.
   *
   * @var string
   */
  public ?string $source_field = NULL;

  /**
   * The target field.
   *
   * @var string
   */
  public ?string $target_field = NULL;

  /**
   * The prompt.
   *
   * @var string
   */
  public ?string $prompt = NULL;

  /**
   * The status.
   *
   * @var int
   */
  public ?int $status = NULL;

  /**
   * The entity type for which the configuration is defined.
   *
   * @var string
   */
  public ?string $entity_type = NULL;

  /**
   * The bundles for which the configuration should be applied.
   *
   * @var array
   */
  public array $bundles = [];

  /**
   * Loads a MyabilityAITermExtractionConfig entity by ID.
   *
   * @param int $id
   *   The ID of the configuration to load.
   *
   * @return MyabilityAITermExtractionConfig|false
   *   The loaded configuration entity or FALSE if not found.
   */
  public static function load(int $id): ?MyabilityAITermExtractionConfig {
    $result = db_select('myability_ai_term_extraction_config', 'c')
      ->fields('c')
      ->condition('id', $id)
      ->execute()
      ->fetchAssoc();

    if ($result) {
      $config = new self();
      $config->id = $result['id'];
      $config->source_field = $result['source_field'];
      $config->target_field = $result['target_field'];
      $config->prompt = $result['prompt'];
      $config->status = $result['status'];
      $config->entity_type = $result['entity_type'];
      $config->bundles = db_select('myability_ai_term_extraction_config_bundle', 'b')
        ->fields('b', ['bundle'])
        ->condition('config_id', $id)
        ->execute()
        ->fetchCol();
      return $config;
    }
    return FALSE;
  }

  /**
   * Saves the MyabilityAITermExtractionConfig entity.
   *
   * @return int
   *   The ID of the saved configuration.
   */
  public function save(): int {
    if (isset($this->id)) {
      // Update existing configuration.
      $message = 'Updated term extraction configuration %id.';
      db_update('myability_ai_term_extraction_config')
        ->fields([
          'source_field' => $this->source_field,
          'target_field' => $this->target_field,
          'prompt' => $this->prompt,
          'status' => $this->status,
          'entity_type' => $this->entity_type,
        ])
        ->condition('id', $this->id)
        ->execute();
    }
    else {
      // Insert new configuration.
      $message = 'Created term extraction configuration %id.';
      $this->id = db_insert('myability_ai_term_extraction_config')
        ->fields([
          'source_field' => $this->source_field,
          'target_field' => $this->target_field,
          'prompt' => $this->prompt,
          'status' => $this->status,
          'entity_type' => $this->entity_type,
        ])
        ->execute();
    }

    // Update bundles.
    db_delete('myability_ai_term_extraction_config_bundle')
      ->condition('config_id', $this->id)
      ->execute();

    foreach ($this->bundles as $bundle) {
      db_insert('myability_ai_term_extraction_config_bundle')
        ->fields([
          'config_id' => $this->id,
          'bundle' => $bundle,
        ])
        ->execute();
    }

    watchdog('myability_ai_term_extraction', $message, ['%id' => $this->id]);

    return $this->id;
  }

  /**
   * Deletes the MyabilityAITermExtractionConfig entity.
   */
  public function delete(): void {
    db_delete('myability_ai_term_extraction_config')
      ->condition('id', $this->id)
      ->execute();

    db_delete('myability_ai_term_extraction_config_bundle')
      ->condition('config_id', $this->id)
      ->execute();

    watchdog('myability_ai_term_extraction', 'Deleted term extraction configuration %id.', ['%id' => $this->id]);
  }

}
