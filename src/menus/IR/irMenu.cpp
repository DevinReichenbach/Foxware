#include "irMenu.hpp"

const char* IRMenu::functionList[] = {
  "TV Killer",
  "IR Function 2",
  "IR Function 3",
  "IR Function 4",
  "IR Function 5"
};

IRMenu::IRMenu() {
  functions = functionList;
  menuSize = sizeof(functionList) / sizeof(functionList[0]);
}

void IRMenu::callSelectedFunction() {
  if (selectedFunctionIndex == 0) { universalTVOff(); }
  else if (selectedFunctionIndex == 1) {}
  else if (selectedFunctionIndex == 2) {}
  else if (selectedFunctionIndex == 3) {}
  else if (selectedFunctionIndex == 4) {}
}