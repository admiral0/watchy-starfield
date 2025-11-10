#include "Watchy_7_SEG.h"
#include "settings.h"

watchySettings settings{
    CITY_ID,
    TO_STRING(CITY_LATITUDE),
    TO_STRING(CITY_LONGITUDE),
    OPENWEATHERMAP_APIKEY,
    OPENWEATHERMAP_URL,
    TEMP_UNIT,
    TEMP_LANG,
    WEATHER_UPDATE_INTERVAL,
    NTP_SERVER,
    GMT_OFFSET_SEC,
    true,
};
Watchy7SEG watchy(settings);


void setup(){
    watchy.init();

}

void loop(){}
