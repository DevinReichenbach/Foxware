#include "main.hpp"

menuItems menuIndex;
int menuDepth;
int subMenuIndex;

void setup() {
  Serial.begin(9600);
  configureM5();
  bootScreen();

  menuIndex = IR;
  menuDepth = 0;
  subMenuIndex = 0; // Track index to color selected function on screen

  delay(2000);
  initMenus();
}

void loop() {
  StickCP2.update();

  // Next Button
  if (StickCP2.BtnA.wasClicked()) {
    if (menuDepth == 0) {
      menuIndex++;
      drawMainMenuItems(menuIndex);
    } else if (menuDepth == 1) {
      subMenuIndex++;
      if (displaySubmenus(menuIndex, subMenuIndex) == subMenuIndex) { subMenuIndex = 0; displaySubmenus(menuIndex, subMenuIndex); } // Re-draw after reset
    }
  }
  // Back Button
  if (StickCP2.BtnPWR.wasClicked() && menuDepth > 0) {
    menuDepth--;
    drawMainMenuItems(menuIndex);
  }

  // Select Button
  if (StickCP2.BtnB.wasClicked()) {
    if (menuDepth == 0) {
      menuDepth++;
      subMenuIndex = 0; // Reset submenu index when entering new menu
      displaySubmenus(menuIndex, subMenuIndex); // First function is selected
    } else if (menuDepth == 1) {
      callSubMenuFunction(menuIndex);
    }
  }
  
  delay(50);
}