#ifndef WIFIMENU_H
#define WIFIMENU_H

#include <M5StickCPlus2.h>
#include "menus/Submenu.hpp"

#define WIFI_MENU_SIZE 5

class WIFIMenu : public Submenu {
  private:
    static const char* functionList[];

  public:
    WIFIMenu();
};

#endif
