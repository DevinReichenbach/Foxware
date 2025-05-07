#ifndef RFMENU_H
#define RFMENU_H

#include <M5StickCPlus2.h>
#include "menus/Submenu.hpp"

#define RF_MENU_SIZE 5

class RFMenu : public Submenu {
  private:
    const char* functions[RF_MENU_SIZE];
  public:
    RFMenu();
    void displayMenu() override;
};

#endif
