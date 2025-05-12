#ifndef RFMENU_H
#define RFMENU_H

#include <M5StickCPlus2.h>
#include "menus/Submenu.hpp"

class RFMenu : public Submenu {
  private:
    static const char* functionList[];

  public:
    RFMenu();
  
  void callSelectedFunction() override;
};
#endif
