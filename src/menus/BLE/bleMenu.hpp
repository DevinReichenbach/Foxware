#ifndef BLEMENU_H
#define BLEMENU_H

#include <M5StickCPlus2.h>
#include "menus/Submenu.hpp"

class BLEMenu : public Submenu {
  private:
    static const char* functionList[];

  public:
    BLEMenu();
};

#endif
