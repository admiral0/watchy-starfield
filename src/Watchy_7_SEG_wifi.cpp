#include "Watchy_7_SEG.h"

void Watchy7SEG::connectWiFi() {
    WIFI_CONFIGURED = true;
    if (lastSSID) {
        for ( const wifiSettings &setting : WIFI_SETTINGS ) {
            if (lastSSID == setting.ssid) {
                if(WL_CONNECT_FAILED == WiFi.begin(setting.ssid, setting.password)) {
                    WIFI_CONFIGURED = false;
                }
            }
        }
    }
    if (WIFI_CONFIGURED == false) {
        int results = WiFi.scanNetworks();
        for (int i = 0; i < results; i++) {
            auto result = static_cast<wifi_ap_record_t *>(WiFiClass::getScanInfoByIndex(i));
            for (const wifiSettings &setting : WIFI_SETTINGS) {
                if (strcmp(setting.ssid, reinterpret_cast<char *>(result->ssid)) == 0) {
                    if (WL_CONNECTED == WiFi.begin(setting.ssid, setting.password)) {
                        WIFI_CONFIGURED = true;
                        lastSSID = setting.ssid;
                        goto CLEANUP;
                    }
                }
            }
        }
    }
    CLEANUP:
    WiFi.scanDelete();
}