#include "mainMenu.hpp"

const char* menus[MAX_MENU_ITEMS] = {"IR", "BLE", "RF", "RFID", "WIFI"};
const char* menuIcon[MAX_MENU_ITEMS] = {"/ir_icon.png", "/ble_icon.png", "/rf_icon.png", "/rfid_icon.png", "/wifi_icon.png"};

void drawTile(int menuIndex) {
  // Draw Tile
  StickCP2.Display.drawString(menus[menuIndex], StickCP2.Display.width() / 2, 10);
  drawCenteredPNG(menuIcon[menuIndex]);  // Draw PNG image, defined in Utils

}