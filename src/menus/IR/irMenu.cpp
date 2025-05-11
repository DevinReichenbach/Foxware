#include "irMenu.hpp"

const char* IRMenu::functionList[] = {
  "Send Code",
  "IR Function 2",
  "IR Function 3",
  "IR Function 4",
  "IR Function 5"
};

IRMenu::IRMenu() {
  functions = functionList;
  menuSize = sizeof(functionList) / sizeof(functionList[0]);
}