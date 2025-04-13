#ifndef UTILS_HPP
#define UTILS_HPP

  #include <Arduino.h>     
  #include <M5StickCPlus2.h>     
  #include <SPIFFS.h>             

  File readPNG(const char* filePath);
  void drawCenteredPNG(const char* filePath, float scale = 2.0f);
  void clearDisplay();

#endif // UTILS_HPP