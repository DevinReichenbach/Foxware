#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

  #include <Arduino.h>
  #include <M5StickCPlus2.h>
  #include <iterator>
  #include "../config/utils.hpp"

  #include "menus/IR/irMenu.hpp"
  #include "menus/BLE/bleMenu.hpp"
  #include "menus/RF/rfMenu.hpp"
  #include "menus/WIFI/wifiMenu.hpp"
  #include "menus/RFID/rfidMenu.hpp"

  #define MAX_MENU_ITEMS 5

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

  void initMenus();
  void drawMainMenuItems(int menuIndex);
  void displaySubmenus(int index);
  void colorSubmenus(int index);
  
  #endif