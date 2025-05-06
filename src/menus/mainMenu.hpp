#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

  #include <Arduino.h>
  #include <M5StickCPlus2.h>
  #include <iterator>
  #include "../config/utils.hpp"

  #define MAX_MENU_ITEMS 5

  #define IR_MENU_SIZE 5
  #define BLE_MENU_SIZE 5
  #define RF_MENU_SIZE 5
  #define RFID_MENU_SIZE 5
  #define WIFI_MENU_SIZE 5

  enum menuItems {
    IR,
    BLE,
    RF,
    RFID,
    WIFI
  };

  // Allow menuItems++ to work
  inline menuItems& operator++(menuItems& currentItem, int)  // <--- note -- must be a reference
  {
	  const int i = static_cast<int>(currentItem)+1;
	  currentItem = static_cast<menuItems>((i) % MAX_MENU_ITEMS);
	  return currentItem;
  }

  void drawMainMenuItems(int menuIndex);
  void drawSubMenuItems(int selectorIndex);
  void changeSelectedItemColor(int subFuncIndex, int menuIndex);
  
  #endif