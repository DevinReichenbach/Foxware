#include "rfidMenu.hpp"

const char* RFIDMenu::functionList[] = {
  "RFID Function 1",
  "RFID Function 2",
  "RFID Function 3",
  "RFID Function 4",
  "RFID Function 5"
};

RFIDMenu::RFIDMenu() {
  functions = functionList;
  menuSize = sizeof(functionList) / sizeof(functionList[0]);
}

void RFIDMenu::callSelectedFunction() {
  if (selectedFunctionIndex == 0) {  }
  else if (selectedFunctionIndex == 1) {}
  else if (selectedFunctionIndex == 2) {}
  else if (selectedFunctionIndex == 3) {}
  else if (selectedFunctionIndex == 4) {}
}