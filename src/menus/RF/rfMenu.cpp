#include "rfMenu.hpp"

const char* RFMenu::functionList[] = {
  "RF Function 1",
  "RF Function 2",
  "RF Function 3",
  "RF Function 4",
  "RF Function 5"
};

RFMenu::RFMenu() {
  functions = functionList;
  menuSize = sizeof(functionList) / sizeof(functionList[0]);
}

void RFMenu::callSelectedFunction() {
  if (selectedFunctionIndex == 0) {  }
  else if (selectedFunctionIndex == 1) {}
  else if (selectedFunctionIndex == 2) {}
  else if (selectedFunctionIndex == 3) {}
  else if (selectedFunctionIndex == 4) {}
}