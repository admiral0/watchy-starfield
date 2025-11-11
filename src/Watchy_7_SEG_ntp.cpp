#include "Watchy_7_SEG.h"

// Overridden ntp to use our own wifi setup
void Watchy7SEG::syncNtpNow() {
    display.setFullWindow();
    display.fillScreen(GxEPD_BLACK);
    display.setFont(&FreeMonoBold9pt7b);
    display.setTextColor(GxEPD_WHITE);
    display.setCursor(0, 30);
    display.println("Syncing NTP... ");
    display.print("GMT offset (h): ");
    display.println(GMT_OFFSET_HOURS);
    display.display(false); // full refresh
    connectWiFi();
    if (WIFI_CONFIGURED) {
        if (syncNTP()) {
            display.println("NTP Sync Success\n");
            display.println("Current Time Is:");

            RTC.read(currentTime);

            display.print(tmYearToCalendar(currentTime.Year));
            display.print("/");
            display.print(currentTime.Month);
            display.print("/");
            display.print(currentTime.Day);
            display.print(" - ");

            if (currentTime.Hour < 10) {
                display.print("0");
            }
            display.print(currentTime.Hour);
            display.print(":");
            if (currentTime.Minute < 10) {
                display.print("0");
            }
            display.println(currentTime.Minute);
        } else {
            display.println("NTP Sync Failed");
        }
    } else {
        display.println("WiFi Not Configured/Connection Failed");
    }
    display.display(true); // full refresh
    delay(3000);
    showMenu(menuIndex, false);
}
