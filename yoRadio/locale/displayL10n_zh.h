#ifndef dsp_full_loc
#define dsp_full_loc
#include <pgmspace.h>
/*************************************************************************************
    HOWTO:
    Copy this file to yoRadio/locale/displayL10n_custom.h
    and modify it
*************************************************************************************/
const char mon[] PROGMEM = "周一";
const char tue[] PROGMEM = "周二";
const char wed[] PROGMEM = "周三";
const char thu[] PROGMEM = "周四";
const char fri[] PROGMEM = "周五";
const char sat[] PROGMEM = "周六";
const char sun[] PROGMEM = "周日";

const char monf[] PROGMEM = "星期一";
const char tuef[] PROGMEM = "星期二";
const char wedf[] PROGMEM = "星期三";
const char thuf[] PROGMEM = "星期四";
const char frif[] PROGMEM = "星期五";
const char satf[] PROGMEM = "星期六";
const char sunf[] PROGMEM = "星期日";

const char jan[] PROGMEM = "一月";
const char feb[] PROGMEM = "二月";
const char mar[] PROGMEM = "三月";
const char apr[] PROGMEM = "四月";
const char may[] PROGMEM = "五月";
const char jun[] PROGMEM = "六月";
const char jul[] PROGMEM = "七月";
const char aug[] PROGMEM = "八月";
const char sep[] PROGMEM = "九月";
const char oct[] PROGMEM = "十月";
const char nov[] PROGMEM = "十一月";
const char dec[] PROGMEM = "十二月";

const char wn_N[]      PROGMEM = "北";
const char wn_NNE[]    PROGMEM = "东北偏北";
const char wn_NE[]     PROGMEM = "东北";
const char wn_ENE[]    PROGMEM = "东北偏东";
const char wn_E[]      PROGMEM = "东";
const char wn_ESE[]    PROGMEM = "东南偏东";
const char wn_SE[]     PROGMEM = "东南";
const char wn_SSE[]    PROGMEM = "东南偏南";
const char wn_S[]      PROGMEM = "南";
const char wn_SSW[]    PROGMEM = "西南偏南";
const char wn_SW[]     PROGMEM = "西南";
const char wn_WSW[]    PROGMEM = "西南偏西";
const char wn_W[]      PROGMEM = "西";
const char wn_WNW[]    PROGMEM = "西北偏西";
const char wn_NW[]     PROGMEM = "西北";
const char wn_NNW[]    PROGMEM = "西北偏北";

const char* const dow[]     PROGMEM = { sun, mon, tue, wed, thu, fri, sat };
const char* const dowf[]    PROGMEM = { sunf, monf, tuef, wedf, thuf, frif, satf };
const char* const mnths[]   PROGMEM = { jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
const char* const wind[]    PROGMEM = { wn_N, wn_NNE, wn_NE, wn_ENE, wn_E, wn_ESE, wn_SE, wn_SSE, wn_S, wn_SSW, wn_SW, wn_WSW, wn_W, wn_WNW, wn_NW, wn_NNW, wn_N };

const char    const_PlReady[]    PROGMEM = "[ready]";
const char  const_PlStopped[]    PROGMEM = "[stopped]";
const char  const_PlConnect[]    PROGMEM = "[connecting]";
const char  const_DlgVolume[]    PROGMEM = "音量";
const char    const_DlgLost[]    PROGMEM = "* LOST *";
const char  const_DlgUpdate[]    PROGMEM = "* UPDATING *";
const char const_DlgNextion[]    PROGMEM = "* NEXTION *";
const char const_getWeather[]    PROGMEM = ""; // intentionally empty in zh locale: weather line is fully formatted by weatherFmt
const char  const_waitForSD[]    PROGMEM = "索引SD";

const char        apNameTxt[]    PROGMEM = "AP名称";
const char        apPassTxt[]    PROGMEM = "密码";
const char       bootstrFmt[]    PROGMEM = "正在连接 %s";
const char        apSettFmt[]    PROGMEM = "设置页面: HTTP://%s/";
#if EXT_WEATHER
const char       weatherFmt[]    PROGMEM = "%s, %.1f\011C \007 体感: %.1f\011C \007 气压: %d hPa \007 湿度: %s%% \007 风速: %.1f m/s [%s]";
#else
const char       weatherFmt[]    PROGMEM = "%s, %.1f\011C \007 气压: %d hPa \007 湿度: %s%%";
#endif
const char     weatherUnits[]    PROGMEM = "metric";   /* standard, metric, imperial */
const char      weatherLang[]    PROGMEM = "zh_cn";    /* https://openweathermap.org/current#multi */

#endif
