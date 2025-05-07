#ifndef IRMENU_H
#define IRMENU_H

#include <M5StickCPlus2.h>
#include "menus/Submenu.hpp"

#define IR_MENU_SIZE 5

class IRMenu : public Submenu {
  private:
    const char* functions[IR_MENU_SIZE];
  public:
    IRMenu();
    void displayMenu() override;
};

#endif
