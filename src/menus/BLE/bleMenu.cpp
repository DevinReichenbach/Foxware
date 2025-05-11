#include "bleMenu.hpp"

const char* BLEMenu::functionList[] = {
  "BLE Function 1",
  "BLE Function 2",
  "BLE Function 3",
  "BLE Function 4",
  "BLE Function 5"
};

BLEMenu::BLEMenu() {
  functions = functionList;
  menuSize = sizeof(functionList) / sizeof(functionList[0]);
}