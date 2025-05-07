#include "bleMenu.hpp"

BLEMenu::BLEMenu() {
  functions[0] = "BLE Function 1";
  functions[1] = "BLE Function 2";
  functions[2] = "BLE Function 3";
  functions[3] = "BLE Function 4";
  functions[4] = "BLE Function 5";
}

void BLEMenu::displayMenu() {
  StickCP2.Display.clear();
  StickCP2.Display.setTextDatum(datum_t::top_left);

  for (int menuItem = 0; menuItem < BLE_MENU_SIZE; menuItem++) {
    StickCP2.Display.drawString(functions[menuItem], 10, menuItem * 25); // Draw Sub Menus
  }
}