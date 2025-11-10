#ifndef SETTINGS_H
#define SETTINGS_H

// Wifi passwords and weather api key
#include "secrets.h"

//Weather Settings
#define CITY_ID "" // Keep empty to use lat long
#define OPENWEATHERMAP_URL "http://api.openweathermap.org/data/2.5/weather?id=" //open weather api
#define TEMP_UNIT "metric" //metric = Celsius , imperial = Fahrenheit
#define TEMP_LANG "en"
#define WEATHER_UPDATE_INTERVAL 30 //must be greater than 5, measured in minutes
//NTP Settings
#define NTP_SERVER "pool.ntp.org"

#define GMT_OFFSET_HOURS 2
#define GMT_OFFSET_SEC (3600 * GMT_OFFSET_HOURS) //New York is UTC -5

// Find it with some online service. Used by both weather and dusk/dawn
#define CITY_LATITUDE 47.010452
#define CITY_LONGITUDE 28.86381

#define TO_STRING(x) #x


// Background white or black
#define DARKMODE false
// 24h or AM/PM
#define HOUR_SET true

#endif