#ifndef WATCHY_7_SEG_H
#define WATCHY_7_SEG_H
#include <math.h>
#include <Watchy.h>
#include "wifisettings.h"
#include "Dusk2Dawn.h"
#include "moonPhaser.h"
#include "Seven_Segment10pt7b.h"
#include "DSEG7_Classic_Regular_15.h"
#include "DSEG7_Classic_Bold_25.h"
#include "DSEG7_Classic_Regular_39.h"
#include "icons.h"
#include "settings.h"

class Watchy7SEG : public Watchy{
    using Watchy::Watchy;
    public:
        Watchy7SEG(const watchySettings &watchySettings);

        void drawWatchFace();
        void drawTime();
        void drawDate();
        void drawSteps();
//        void drawWeather();
//        void drawEva();
        void drawBattery();
//        void drawLine();
        void drawFiel();
        void drawMoon();

        void drawSun();
        virtual void handleButtonPress();

        void connectWiFi();
        void overrideMenu(uint64_t wakeupBit);
        void syncNtpNow();
    private:
        const char *lastSSID;
};

#endif
