#include "Watchy_7_SEG.h"

void Watchy7SEG::handleButtonPress()
{
    uint64_t wakeupBit = esp_sleep_get_ext1_wakeup_status();
    if (guiState == WATCHFACE_STATE)
    {

        // I'll fix that later - don't like default setup - only menu
        if (wakeupBit & UP_BTN_MASK)
        {
            // NO OP
            return;
        }
        if (wakeupBit & DOWN_BTN_MASK)
        {
            // NO OP
            return;
        }
        if (wakeupBit & BACK_BTN_MASK)
        {
            // NO OP
            return;
        }
        if (wakeupBit & MENU_BTN_MASK)
        {
            Watchy::showMenu(menuIndex, false);
            return;
        }
    }
    else {this->overrideMenu(wakeupBit);}
    return;
}

void Watchy7SEG::overrideMenu(uint64_t wakeupBit) {
    // Override ntp sync
    if (guiState == MAIN_MENU_STATE && wakeupBit & MENU_BTN_MASK && menuIndex == 5) {
        syncNtpNow();
        return;
    }

    Watchy::handleButtonPress();
}


