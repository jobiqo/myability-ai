(function ($) {

  "use strict";

  /**
   * Trigger playback for audio element.
   */
  $.fn.playAudio = function() {
    $(this)[0].play();
    // Set focus to the audio element so that the user can control the playback.
    $(this).focus();
  }

})(jQuery);
