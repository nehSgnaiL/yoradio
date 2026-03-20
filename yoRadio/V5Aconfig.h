#ifndef V5Aconfig_h
#define V5Aconfig_h

/*        V5A TUNING               */
#ifndef V5A_DEFAULT_VOLUME
  #define V5A_DEFAULT_VOLUME    170
#endif
#ifndef V5A_BUTTON_VOLUME_STEP
  #define V5A_BUTTON_VOLUME_STEP 10
#endif

/*        V5A SPI BUS SELECTION                               */
/*  V5A uses VSPI pins for the ST7789 display:               */
/*    SCLK=18, MOSI=19, CS=22  (VSPI native pins on ESP32)  */
#ifndef V5A_SPI_CLK
  #define V5A_SPI_CLK   18
#endif
#ifndef V5A_SPI_MOSI
  #define V5A_SPI_MOSI  19
#endif
#ifndef V5A_SPI_SS
  #define V5A_SPI_SS    22
#endif
/* Use VSPI hardware bus instead of HSPI so pins 18/19 work  */
#ifndef V5A_USE_VSPI
  #define V5A_USE_VSPI  true
#endif

/*        CHINESE FONT SUPPORT                               */
/*  Enable U8g2 Chinese font rendering for station names     */
#ifndef V5A_USE_CHINESE_FONT
  #define V5A_USE_CHINESE_FONT true
#endif

/*        CHINA LOCALE DEFAULTS                              */
/*  Default timezone offset for China Standard Time (CST)   */
#ifndef V5A_DEFAULT_TZ_HOUR
  #define V5A_DEFAULT_TZ_HOUR   8
#endif

/*        BATTERY                  */
#ifndef BAT_OWR
  #define BAT_OWR               255   // keep system power enabled when battery is connected
#endif
#ifndef BAT_LOW_ADC
  #define BAT_LOW_ADC           255   // ADC pin for battery low check
#endif
#ifndef BAT_LOW_LEVEL
  #define BAT_LOW_LEVEL         1200  // raw ADC low battery threshold
#endif
#ifndef BAT_BEEP_PIN
  #define BAT_BEEP_PIN          255   // optional buzzer pin for low-battery reminder
#endif
#ifndef BAT_BEEP_FREQ
  #define BAT_BEEP_FREQ         2200
#endif
#ifndef BAT_BEEP_CHANNEL
  #define BAT_BEEP_CHANNEL      7
#endif
#ifndef BAT_BEEP_RESOLUTION
  #define BAT_BEEP_RESOLUTION   8
#endif
#ifndef BAT_BEEP_PULSE_MS
  #define BAT_BEEP_PULSE_MS     120
#endif
#ifndef BAT_BEEP_STAGES
  #define BAT_BEEP_STAGES       3     // "beep beep beep" low-battery reminder sequence
#endif
#ifndef BAT_BEEP_INTERVAL_MS
  #define BAT_BEEP_INTERVAL_MS  60000
#endif
#ifndef BAT_ADC_READ_INTERVAL_MS
  #define BAT_ADC_READ_INTERVAL_MS 1000
#endif
#ifndef BAT_ADC_MIN_VALID
  #define BAT_ADC_MIN_VALID     1     // filter out zero/invalid ADC reads
#endif

#endif
