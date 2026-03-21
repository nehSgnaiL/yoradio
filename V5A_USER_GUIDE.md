# V5A 收音机用户手册 / V5A Radio User Guide

This guide covers the V5A hardware variant of ёRadio — a simplified internet radio for elderly and visually-impaired Chinese users.

---

## 目录 / Contents

- [Hardware / 硬件](#hardware--硬件)
- [Controls / 操作按键](#controls--操作按键)
- [Flashing / 烧录固件](#flashing--烧录固件)
- [Configuration / 配置](#configuration--配置)
- [Playlist / 电台列表](#playlist--电台列表)
- [Web Interface / 网页界面](#web-interface--网页界面)
- [Tuning Defaults / 可调参数](#tuning-defaults--可调参数)

---

## Hardware / 硬件

| Component | Detail |
|-----------|--------|
| MCU | ESP32 |
| Display | ST7789 240×240 TFT (VSPI: SCLK=18, MOSI=19, CS=22) |
| Audio | I2S DAC |
| Buttons | BTN_UP (volume +), BTN_DOWN (volume −) |
| Encoder | Rotate = prev/next station |

---

## Controls / 操作按键

| Button / 按键 | Action / 功能 |
|--------------|--------------|
| BTN_UP (上键) | Volume +10 / 音量加 10 |
| BTN_DOWN (下键) | Volume −10 / 音量减 10 |
| BTN_CENTER (中键) | Disabled / 禁用 |
| Encoder rotate left (旋钮左转) | Previous station / 上一个电台 |
| Encoder rotate right (旋钮右转) | Next station / 下一个电台 |
| Encoder button (旋钮按键) | Disabled / 禁用 |

Default volume: **170** (range 0–254).

---

## Flashing / 烧录固件

1. Install [Arduino IDE](https://www.arduino.cc/en/software) or [PlatformIO](https://platformio.org/).
2. Add ESP32 board support (Espressif ESP32 Arduino core ≥ 2.x).
3. Install dependencies listed in the main [README](README.md#dependencies).
4. Open `yoRadio/yoRadio.ino`.
5. Select board **ESP32 Dev Module**, partition scheme **Huge APP (3MB No OTA)** or larger.
6. Upload sketch.
7. Upload SPIFFS data folder (`yoRadio/data/`) with **ESP32 Sketch Data Upload** tool.

---

## Configuration / 配置

All V5A-specific tuning knobs live in **`yoRadio/V5Aconfig.h`**.  
Edit that file before compiling — no other files need touching.

| Macro | Default | Description |
|-------|---------|-------------|
| `V5A_DEFAULT_VOLUME` | `170` | Start-up volume |
| `V5A_BUTTON_VOLUME_STEP` | `10` | Volume step per button press |
| `V5A_SPI_CLK` | `18` | ST7789 SCLK pin |
| `V5A_SPI_MOSI` | `19` | ST7789 MOSI pin |
| `V5A_SPI_SS` | `22` | ST7789 CS pin |
| `V5A_USE_VSPI` | `true` | Use VSPI hardware bus |
| `V5A_USE_CHINESE_FONT` | `true` | Enable U8g2 GB2312 font rendering |
| `V5A_DEFAULT_TZ_HOUR` | `8` | Timezone offset (CST = UTC+8) |

---

## Playlist / 电台列表

- Playlist file: `yoRadio/data/data/playlist.csv`
- Format: `<URL>,<Station Name>`
- Station names may contain Chinese UTF-8 characters — they are displayed using the embedded GB2312 font.

Example:
```
http://example.com/stream,中央人民广播电台
http://example.com/stream2,音乐之声
```

Upload the updated playlist via the web interface or re-flash SPIFFS.

---

## Web Interface / 网页界面

1. On first boot the radio creates a Wi-Fi hotspot. Connect and enter your Wi-Fi credentials.
2. Once connected, open a browser to the radio's IP address.
3. The web player and settings pages are localised in Chinese (`data/www/i18n.js`).

---

## Tuning Defaults / 可调参数

General options (timezone, flip/invert screen, etc.) are set in `yoRadio/src/core/options.h` via the macros above; V5A ships with:

- `flipscreen = true`
- `invertdisplay = true`
- `timezone = UTC+8` (CST)
