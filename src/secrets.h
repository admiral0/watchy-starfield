#ifndef WATCHY_STARFIELD_SECRETS_H
#define WATCHY_STARFIELD_SECRETS_H

#include "wifisettings.h"

#define OPENWEATHERMAP_APIKEY ""  // Get your own :)

// Order matters - connection will be tried in order
const wifiSettings WIFI_SETTINGS[] = {
    {"some_ssid", "some_pass"},
    {"some_other_ssid", "some_pass"}
};

#endif //WATCHY_STARFIELD_SECRETS_H