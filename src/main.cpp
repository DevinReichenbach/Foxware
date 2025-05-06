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

  submenuIndex = 0;

  delay(2000);
  StickCP2.Display.clear();
  drawMainMenuItems(menuIndex); // Draw first tile on startup
}

void loop() {
  StickCP2.update();
  // Main Mode Selector
  if (StickCP2.BtnA.wasClicked() && menuDepth == 0) { 
    menuIndex++; // Overloaded operator rolls menu over
    clearDisplay();
    drawMainMenuItems(menuIndex); // Draw new menu tile
  }
  // Submenu generator
  if (StickCP2.BtnB.wasClicked()) {
    menuDepth++;
    clearDisplay();
    drawSubMenuItems(menuIndex);
    changeSelectedItemColor(submenuIndex, menuIndex); // Make first submenu label colored
  }

  // Step back up menu
  if (StickCP2.BtnPWR.wasClicked() && menuDepth > 0) {
    menuDepth--; 
    clearDisplay();
    drawMainMenuItems(menuIndex);
  }

  // Submenu selectors
  if (StickCP2.BtnA.wasClicked() && menuDepth == 1) {
    if (submenuIndex >= MAX_MENU_ITEMS - 1) { submenuIndex = 0; }
    else { submenuIndex++; }

    changeSelectedItemColor(submenuIndex, menuIndex);
  }

  delay(50);
}