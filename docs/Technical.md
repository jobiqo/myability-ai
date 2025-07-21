# Myability AI technical documentation

The module integrates multiple AI powered generative features for Drupal websites:
1. Summary generation from long text fields - MyAbility AI Summary Generation submodule
2. Text to Speech audio generation from text fields - MyAbility AI Text To Speech submodule
3. Taxonomy Term extraction from text fields - MyAbility AI Term Extraction submodule

In addition to the above, the module integrates with OpenAI APIs to provide the AI features using MyAbility AI API submodule.

## Submodule: MyAbility AI API (myability_ai_api)
This submodule integrates MyAbility AI features with the OpenAI APIs to generate text/audio output. There are two main API functions connecting to chat and audio endpoints:
```php
myability_ai_api_send_chat_request(
  string $prompt,
  float $temperature = 0.2,
  string $model = 'gpt-4o',
  bool $as_json = TRUE
): string
```
```php
myability_ai_api_send_tts_request(
  string $text,
  string $voice = 'alloy',
  string $response_format = 'mp3',
  float $speed = 1.0,
  string $instructions = ''
): string
```

## Submodule: MyAbility AI Summary Generation (myability_ai_summary_generation)
Summary generation is happening in the front-end on demand, meaning that the user is presented with a button to request the summary generation. After successful generation any subsequent request will show the previously generated text.
This is done by implementing a Drupal field formatter, which renders a generation form for empty field value or the text if the value exists already.

### Summary generation requires configuration of 2 components:
1. Summary Generation Config - this is a configuration entity that defines the source and target fields, entity type and bundles for which the summary generation should be available, as well as the prompt with instructions on how the summary should be generated.
2. Summary Generation Formatter - this is a field formatter that renders the summary generation button and the generated text. It can be used for any text type field.

## Submodule: MyAbility AI Text To Speech (myability_ai_tts)
Text To Speech generation is happening in the front-end on demand, meaning that the user is presented with a button to request the audio generation. After successful generation any subsequent request will show the previously generated audio file in the form of native HTML audio player.
This is done by implementing a Drupal field formatter, which by default renders a generation form for empty field value or the audio player if the audio file exists already.

### Text To Speech generation requires configuration of 2 components:
1. Text To Speech Config - this is a configuration entity that defines the source and target fields, entity type and bundles for which the Text To Speech generation should be available, as well as the voice, response format, speed and instructions for the audio generation.
2. Text To Speech Formatter - this is a field formatter that renders the generate button/audio player. It can be used for file type fields, which are used to store audio files. It has one setting called “Dummy audio generate button”. If selected, it renders a “dummy” audio player when the audio has not been generated yet. Upon clicking this player the audio is generated and will start playing automatically once ready.

## Submodule: MyAbility AI Term Extraction (myability_ai_term_extraction)
Taxonomy term extraction uses source field text along with a supplied list of taxonomy terms allowed for the target field to find matching terms and store them on the parent entity. This is happening in the background every time the entity of chosen type/bundle is saved. Other modules can alter the process by implementing the following hooks:
- hook_myability_ai_term_extraction_source_text_alter: Alter the source text, possibly with other data from the parent entity
- hook_myability_ai_term_extraction_should_extract_alter: Alter the extraction decision strategy (whether the extraction should be triggered for a given case). By default the extraction happens if the target field is empty or the source field value has changed

### Term extraction requires configuration of 1 component:
1. Term Extraction Config - this is a configuration entity that defines the source and target fields, entity type and bundles for which the term extraction should be available, as well as the prompt with instructions on how the terms should be extracted.
