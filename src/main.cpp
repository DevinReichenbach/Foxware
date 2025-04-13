#include "main.hpp"

int menuIndex = 0;

void setup() {
  Serial.begin(9600);
  configureM5();
  bootScreen();
  menuIndex = 0;

  delay(2000);
  StickCP2.Display.clear();

}

void loop() {
  StickCP2.update();

  if (StickCP2.BtnA.isPressed()) { 
    if (menuIndex >= MAX_MENU_ITEMS - 1) { menuIndex = 0; }  // Roll over menu 
    else {  // Draw next tile
      menuIndex++;
    }
    clearDisplay();
  }
  
  drawTile(menuIndex); // Draw new menu tile

  delay(50);
}