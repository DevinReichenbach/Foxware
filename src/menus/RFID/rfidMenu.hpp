#ifndef RFIDMENU_H
#define RFIDMENU_H

#include <M5StickCPlus2.h>
#include "menus/Submenu.hpp"

#define RFID_MENU_SIZE 5

class RFIDMenu : public Submenu {
  private:
    const char* functions[RFID_MENU_SIZE];
  public:
    RFIDMenu();
    void displayMenu() override;
};

#endif
