#include "rfMenu.hpp"

RFMenu::RFMenu() {
  functions[0] = "RF Function 1";
  functions[1] = "RF Function 2";
  functions[2] = "RF Function 3";
  functions[3] = "RF Function 4";
  functions[4] = "RF Function 5";
}

void RFMenu::displayMenu() {
  StickCP2.Display.clear();
  StickCP2.Display.setTextDatum(datum_t::top_left);

  for (int menuItem = 0; menuItem < RF_MENU_SIZE; menuItem++) {
    StickCP2.Display.drawString(functions[menuItem], 10, menuItem * 25); // Draw Sub Menus
  }
}