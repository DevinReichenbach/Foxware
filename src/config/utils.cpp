#include "utils.hpp"

File readPNG(const char* filePath) {
  // Start SPIFFS
  if (!SPIFFS.begin(true)) {
    Serial.println("SPIFFS Mount Failed");
    return File();  // Return an invalid file
  }

  // Open PNG file
  File png = SPIFFS.open(filePath, "r");
  if (!png || png.isDirectory()) {
    Serial.println("Failed to open file");
    return File();  // Return an invalid file
  }

  return png;
}


void drawCenteredPNG(const char* filePath, float scale) {
  uint32_t img_dimension = 44;

  // Position with scale
  uint32_t scaled_x = (StickCP2.Display.width() - img_dimension * scale) / 2;
  uint32_t scaled_y = (StickCP2.Display.height() - img_dimension * scale) / 2;
  

  File png = readPNG(filePath);                 // Read PNG
  StickCP2.Display.drawPng(&png,                // Draw PNG image
                           scaled_x, scaled_y,
                           0, 0, 0, 0, 
                           scale, scale, 
                           datum_t::top_left);
  png.close();
}


void clearDisplay() {
  StickCP2.Display.clear();
}