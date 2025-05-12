#ifndef RFIDMENU_H
#define RFIDMENU_H

#include <M5StickCPlus2.h>
#include "menus/Submenu.hpp"

class RFIDMenu : public Submenu {
  private:
    static const char* functionList[];

  public:
    RFIDMenu();

  void callSelectedFunction() override;
};

#endif
