#include "mainMenu.hpp"

const char* menus[MAX_MENU_ITEMS] = {"IR", "BLE", "RF", "RFID", "WIFI"};
const char* menuIcon[MAX_MENU_ITEMS] = {"/ir_icon.png", "/ble_icon.png", "/rf_icon.png", "/rfid_icon.png", "/wifi_icon.png"};

Submenu* ir_menu;
Submenu* ble_menu;
Submenu* rfid_menu;
Submenu* rf_menu;
Submenu* wifi_menu;

int submenuIndex;

void initMenus() {
  ir_menu = new IRMenu();
  ble_menu = new BLEMenu();
  rf_menu = new RFMenu();
  rfid_menu = new RFIDMenu();
  wifi_menu = new WIFIMenu();

  submenuIndex = 0;

  StickCP2.Display.clear();
  drawMainMenuItems(0); // Draw initial tile
}

// Draw Main menu items
void drawMainMenuItems(int menuIndex) {
  StickCP2.Display.clear();
  StickCP2.Display.setTextDatum(datum_t::middle_center);
  StickCP2.Display.drawString(menus[menuIndex], StickCP2.Display.width() / 2, 10);
  drawCenteredPNG(menuIcon[menuIndex]);  // Draw PNG image
}

// Draw functions of selected menu, return size of submenu
int displaySubmenus(int mainMenuIndex, int coloredFunctionIndex) {
  if (mainMenuIndex == IR) { ir_menu->displayMenu(coloredFunctionIndex); return ir_menu->getSubmenuSize(); }
  if (mainMenuIndex == BLE) { ble_menu->displayMenu(coloredFunctionIndex); return ble_menu->getSubmenuSize(); }
  if (mainMenuIndex == RF) { rf_menu->displayMenu(coloredFunctionIndex); return rf_menu->getSubmenuSize(); }
  if (mainMenuIndex == RFID) { rfid_menu->displayMenu(coloredFunctionIndex); return rfid_menu->getSubmenuSize(); }
  if (mainMenuIndex == WIFI) { wifi_menu->displayMenu(coloredFunctionIndex); return wifi_menu->getSubmenuSize(); }
}