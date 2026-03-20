## Project instructions for GitHub Copilot

- Target device: V5A and yoRadio firmware for elderly & sightless Chinese users with simplified controls.
- Keep control logic simple and deterministic:
  - `BTN_UP`: volume +10
  - `BTN_DOWN`: volume -10
  - `BTN_CENTER`: disabled
  - Encoder left/right: previous/next station
  - Encoder button: disabled
- Keep adjustable defaults in `/yoRadio/V5Aconfig.h` where possible.
- Default volume is `170` (`V5A_DEFAULT_VOLUME`).
- Prefer UTF-8 safe handling for playlist/station text (Chinese text must pass through without conversion loss).
- Update all the markdown files of this repository in time.
