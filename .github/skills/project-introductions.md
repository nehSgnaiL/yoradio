# Project introduction

`yoradio` is an ESP32 internet radio firmware project with display, playlist, web config, and hardware control support.

## Key areas
- `yoRadio/src/core/controls.cpp`: button/encoder behavior.
- `yoRadio/src/core/config.cpp`: persisted defaults (volume, EQ, UX settings).
- `yoRadio/src/core/options.h`: compile-time tunable constants.
- `yoRadio/src/main.cpp`: boot flow and battery-related runtime checks.
- `yoRadio/src/displays/tools/l10n.h` + `yoRadio/locale/*.h`: display localization.

## Goal for this refactor
Optimize for V5A accessibility:
- deterministic hardware controls,
- clear default volume,
- low-battery reminder behavior,
- Chinese language support with reduced unused locale footprint.
