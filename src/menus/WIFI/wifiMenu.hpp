#ifndef WIFIMENU_H
#define WIFIMENU_H

#include <M5StickCPlus2.h>
#include "menus/Submenu.hpp"

#define WIFI_MENU_SIZE 5

class WIFIMenu : public Submenu {
  private:
    const char* functions[WIFI_MENU_SIZE];
  public:
    WIFIMenu();
    void displayMenu() override;
};

#endif
