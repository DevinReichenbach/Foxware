#ifndef IRMENU_H
#define IRMENU_H

#include <M5StickCPlus2.h>
#include "menus/Submenu.hpp"
#include "ir.hpp"

class IRMenu : public Submenu {
  private:
    static const char* functionList[];

  public:
    IRMenu();

  void callSelectedFunction() override;
};

#endif
