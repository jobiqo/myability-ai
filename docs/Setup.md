# MyAbility AI API Setup Guide

## Submodule: MyAbility AI API (myability_ai_api)

Enable the 'myability_ai_api’ module.
To configure the module and enable the use of OpenAI APIs the user needs to obtain an OpenAI API key and set-up the API key variable by using drush:

```
drush vset myability_ai_api_key {API_KEY}
```

or by pasting the key in the configuration form located in the following drupal path:

```
admin/config/myability_ai/api
```

## Submodule: MyAbility AI Summary Generation (myability_ai_summary_generation)
1. Enable the ‘myability_ai_summary_generation’ module.
2. Visit ‘admin/config/myability_ai/summary_generation’ - this is an overview of all summary generation configuration entities defined on the site.
3. Click the ‘Add Summary Generation Config’ link in the top part of the page.
4. Fill out the configuration form. Choose entity type and bundles for which you want to generate summaries. Choose source and target fields and prepare a prompt with instructions on how the summary should be written. Once ready to test/use, set the status to active.
5. In the settings of the chosen entity type/bundle, set ‘MyAbility AI Summary Formatter’ as an active field formatter. Do this for all the display modes, where you want the users to be able to generate the summaries (e.g. Default, Teaser).
6. Test by visiting a page with a desired entity/bundle with a chosen display mode. Generate a summary by clicking the button rendered in the field markup.

## Submodule: MyAbility AI Text To Speech (myability_ai_tts)
1. Enable the ‘myability_ai_tts’ module.
2. Visit ‘admin/config/myability_ai/text_to_speech’ - this is an overview of all Text To Speech generation configuration entities defined on the site.
3. Click the ‘Add Text To Speech Config’ link in the top part of the page.
4. Fill out the configuration form. Choose entity type and bundles for which you want to generate Text To Speech. Choose source and target field, voice, response format, speed and optionally add instructions for the voice. Once ready to test/use, set the status to active.
5. In the settings of the chosen entity type/bundle, set ‘MyAbility AI Text To Speech Formatter’ as an active field formatter and check the ‘Dummy audio generate button’ checkbox if you wish to use that feature. Do this for all the display modes, where you want the users to be able to generate the summaries (e.g. Default, Teaser).
6. An optional safety limit for maximum input text length in characters can be set in the general Text To Speech settings by visiting a configuration form at ‘admin/config/myability_ai/text_to_speech/settings’.
7. Test by visiting a page with a desired entity/bundle with a chosen display mode. Generate an audio by clicking the button rendered in the field markup.

## Submodule: MyAbility AI Term Extraction (myability_ai_term_extraction)
1. Enable the ‘myability_ai_term_extraction’ module.
2. Visit ‘admin/config/myability_ai/term_extraction’ - this is an overview of all Term extraction configuration entities defined on the site.
3. Click the ‘Add Term Extraction Config’ link in the top part of the page.
4. Fill out the configuration form. Choose entity type and bundles for which you want to generate summaries. Choose source and target fields and prepare a prompt with instructions on how the terms should be extracted. Once ready to test/use, set the status to active.
5. Test by saving an entity with the source field present. The target field should now contain the extracted term references.
