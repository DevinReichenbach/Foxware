#include "WIFIMenu.hpp"

const char* WIFIMenu::functionList[] = {
  "WIFI Function 1",
  "WIFI Function 2",
  "WIFI Function 3",
  "WIFI Function 4",
  "WIFI Function 5"
};

WIFIMenu::WIFIMenu() {
  functions = functionList;
  menuSize = sizeof(functionList) / sizeof(functionList[0]);
}