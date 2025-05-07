#include "rfidMenu.hpp"

RFIDMenu::RFIDMenu() {
  functions[0] = "RFID Function 1";
  functions[1] = "RFID Function 2";
  functions[2] = "RFID Function 3";
  functions[3] = "RFID Function 4";
  functions[4] = "RFID Function 5";
}

void RFIDMenu::displayMenu() {
  StickCP2.Display.clear();
  StickCP2.Display.setTextDatum(datum_t::top_left);

  for (int menuItem = 0; menuItem < RFID_MENU_SIZE; menuItem++) {
    StickCP2.Display.drawString(functions[menuItem], 10, menuItem * 25); // Draw Sub Menus
  }
}