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
  StickCP2.Display.clear();
  drawMainMenuItems(menuIndex); // Draw first tile on startup
}

void loop() {
  StickCP2.update();

  if (StickCP2.BtnA.wasClicked() && menuDepth == 0) { 
    menuIndex++; // Overloaded operator rolls menu over
    clearDisplay();
    drawMainMenuItems(menuIndex); // Draw new menu tile
  }
    
  if (StickCP2.BtnB.wasClicked()) {
    menuDepth++;
    clearDisplay();
    drawSubMenuItems(menuIndex);
  }

  delay(50);
}