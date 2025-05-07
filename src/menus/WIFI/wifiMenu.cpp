#include "WIFIMenu.hpp"

WIFIMenu::WIFIMenu() {
  functions[0] = "WIFI Function 1";
  functions[1] = "WIFI Function 2";
  functions[2] = "WIFI Function 3";
  functions[3] = "WIFI Function 4";
  functions[4] = "WIFI Function 5";
}

void WIFIMenu::displayMenu() {
  StickCP2.Display.clear();
  StickCP2.Display.setTextDatum(datum_t::top_left);

  for (int menuItem = 0; menuItem < WIFI_MENU_SIZE; menuItem++) {
    StickCP2.Display.drawString(functions[menuItem], 10, menuItem * 25); // Draw Sub Menus
  }
}