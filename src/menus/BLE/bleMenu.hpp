#ifndef BLEMENU_H
#define BLEMENU_H

#include <M5StickCPlus2.h>
#include "menus/Submenu.hpp"

#define BLE_MENU_SIZE 5

class BLEMenu : public Submenu {
  private:
    const char* functions[BLE_MENU_SIZE];
  public:
    BLEMenu();
    void displayMenu() override;
};

#endif
