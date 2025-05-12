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

void BLEMenu::callSelectedFunction() {
  if (selectedFunctionIndex == 0) { }
  else if (selectedFunctionIndex == 1) {}
  else if (selectedFunctionIndex == 2) {}
  else if (selectedFunctionIndex == 3) {}
  else if (selectedFunctionIndex == 4) {}
}