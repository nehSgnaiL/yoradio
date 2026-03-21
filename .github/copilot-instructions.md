# Copilot instructions for yoradio

- Keep firmware changes minimal and hardware-safe for ESP32 + V5A boards.
- Prioritize simple operation flows for elderly users (fewer actions, predictable controls).
- Put tunable behavior in `yoRadio/src/core/options.h` when possible.
- Preserve existing architecture: controls in `src/core/controls.cpp`, defaults in `src/core/config.cpp`, localization in `yoRadio/locale/*` and `src/displays/tools/l10n.h`.
- Avoid adding heavy dependencies; use existing Arduino/ESP32 APIs.
- For localization, default to UTF-8-safe text and avoid adding Russian locale assets.
- Keep commits focused and small; do not touch unrelated modules.
