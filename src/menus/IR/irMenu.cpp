#include "irMenu.hpp"

IRMenu::IRMenu() {
  functions[0] = "Send Code";
  functions[1] = "IR Function 2";
  functions[2] = "IR Function 3";
  functions[3] = "IR Function 4";
  functions[4] = "IR Function 5";
}

void IRMenu::displayMenu() {
  StickCP2.Display.clear();
  StickCP2.Display.setTextDatum(datum_t::top_left);

  for (int menuItem = 0; menuItem < IR_MENU_SIZE; menuItem++) {
    StickCP2.Display.drawString(functions[menuItem], 10, menuItem * 25); // Draw Sub Menus
  }
}