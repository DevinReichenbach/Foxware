#include "rfidMenu.hpp"

const char* RFIDMenu::functionList[] = {
  "Read RFID Tag",
  "Write RFID Tag",
  "RFID Function 3",
  "RFID Function 4",
  "RFID Function 5"
};

RFIDMenu::RFIDMenu() {
  functions = functionList;
  menuSize = sizeof(functionList) / sizeof(functionList[0]);
}

void RFIDMenu::callSelectedFunction() {
  initRFID(); 
  byte block = 8;
  byte data[16] = {
    'W', 'e', 'l', 'c', 'o', 'm', 'e', ' ', 'G', '!', '!'
  };

  if (selectedFunctionIndex == 0) { readRFID(); }
  else if (selectedFunctionIndex == 1) { writeRFID(block, data); }
  else if (selectedFunctionIndex == 2) {}
  else if (selectedFunctionIndex == 3) {}
  else if (selectedFunctionIndex == 4) {}
}