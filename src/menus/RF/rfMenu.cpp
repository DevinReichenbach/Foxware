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