#include "main.hpp"

menuItems menuIndex;
int menuDepth;
int submenuIndex;

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
  if (StickCP2.BtnA.wasClicked() && menuDepth == 0) {
    menuIndex++;
    drawMainMenuItems(menuIndex);
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