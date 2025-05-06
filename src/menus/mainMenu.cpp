#include "mainMenu.hpp"

const char* menus[MAX_MENU_ITEMS] = {"IR", "BLE", "RF", "RFID", "WIFI"};
const char* menuIcon[MAX_MENU_ITEMS] = {"/ir_icon.png", "/ble_icon.png", "/rf_icon.png", "/rfid_icon.png", "/wifi_icon.png"};

const char* IRMenu[IR_MENU_SIZE] = {"Send Code", "IR Function 2", "IR Function 3", "IR Function 4", "IR Function 5"};
const char* BLEMenu[BLE_MENU_SIZE] = {"BLE Function 1","BLE Function 2","BLE Function 3","BLE Function 4","BLE Function 5"};
const char* RFMenu[RF_MENU_SIZE] = {"RF Function 1","RF Function 2","RF Function 3","RF Function 4","RF Function 5"};
const char* RFIDMenu[RFID_MENU_SIZE] = {"RFID Function 1","RFID Function 2","RFID Function 3","RFID Function 4","RFID Function 5"};
const char* WIFIMenu[WIFI_MENU_SIZE] = {"WIFI Function 1","WIFI Function 2","WIFI Function 3","WIFI Function 4","WIFI Function 5"};

const char** submenus[MAX_MENU_ITEMS] = {IRMenu, BLEMenu, RFMenu, RFIDMenu, WIFIMenu};

// Draw Main menu items
void drawMainMenuItems(int menuIndex) {
  StickCP2.Display.setTextDatum(datum_t::middle_center);
  StickCP2.Display.drawString(menus[menuIndex], StickCP2.Display.width() / 2, 10);
  drawCenteredPNG(menuIcon[menuIndex]);  // Draw PNG image, defined in Utils
}

// Draw Sub menus
void drawSubMenuItems(int selectorIndex) {
  StickCP2.Display.setTextDatum(datum_t::top_left);

  changeSelectedItemColor(0, selectorIndex);

  // TODO: Make length dynamic
  for (int menuItem = 0; menuItem < IR_MENU_SIZE; menuItem++) {
    StickCP2.Display.drawString(submenus[selectorIndex][menuItem], 10, menuItem * 25); // Draw Sub Menus
  }
}

void changeSelectedItemColor(int subFuncIndex, int menuIndex) {
  StickCP2.Display.setTextColor(WHITE);
  StickCP2.Display.drawString(submenus[menuIndex][subFuncIndex], 10, subFuncIndex * 25); // Color selected Index

  int previousIndex = subFuncIndex - 1;

  if (subFuncIndex == 0 ) { previousIndex = MAX_MENU_ITEMS - 1; }  

  StickCP2.Display.setTextColor(ORANGE);
  StickCP2.Display.drawString(submenus[menuIndex][previousIndex], 10, (previousIndex) * 25); // Recolor previous Index
}