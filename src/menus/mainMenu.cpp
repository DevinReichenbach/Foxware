#include "mainMenu.hpp"

const char* menus[MAX_MENU_ITEMS] = {"IR", "BLE", "RF", "RFID", "WIFI"};
const char* menuIcon[MAX_MENU_ITEMS] = {"/ir_icon.png", "/ble_icon.png", "/rf_icon.png", "/rfid_icon.png", "/wifi_icon.png"};

const char* IRMenu[IR_MENU_SIZE] = {"Send Code", "IR Function 2", "IR Function 3", "IR Function 4", "IR Function 5"};
const char* BLEMenu[BLE_MENU_SIZE] = {""};
const char* RFMenu[RF_MENU_SIZE] = {""};
const char* RFIDMenu[RFID_MENU_SIZE] = {""};
const char* WIFIMenu[WIFI_MENU_SIZE] = {""};

// Draw Main menu items
void drawMainMenuItems(int menuIndex) {
  StickCP2.Display.setTextDatum(datum_t::middle_center);
  StickCP2.Display.drawString(menus[menuIndex], StickCP2.Display.width() / 2, 10);
  drawCenteredPNG(menuIcon[menuIndex]);  // Draw PNG image, defined in Utils
}

// Draw Sub menus
void drawSubMenuItems(int selectorIndex) {
  StickCP2.Display.setTextDatum(datum_t::top_left);
  for (int menuItem = 0; menuItem < IR_MENU_SIZE; menuItem++) {
    StickCP2.Display.drawString(IRMenu[menuItem], 10, menuItem * 25); // Draw Sub Menus
  }
}