#include "main.hpp"

menuItems menuIndex;
int menuDepth;

void setup() {
  Serial.begin(9600);
  configureM5();
  bootScreen();

  menuIndex = IR;
  menuDepth = 0;

  delay(2000);
  initMenus();
}

void loop() {
  StickCP2.update();

  // Next Button
  if (StickCP2.BtnA.wasClicked()) {
    menuIndex++;
    if (menuDepth == 0) {
      drawMainMenuItems(menuIndex);
    } else if (menuDepth == 1) {
      colorSubmenus(menuIndex);
    }
  }
  // Back Button
  if (StickCP2.BtnPWR.wasClicked() && menuDepth > 0) {
    menuDepth--;
    drawMainMenuItems(menuIndex);
  }
  // Forward Button
  if (StickCP2.BtnB.wasClicked() && menuDepth == 0) {
    menuDepth++;
    displaySubmenus(menuIndex);
  }
  
  delay(50);
}