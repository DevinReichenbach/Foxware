#include "bootScreen.hpp"

float scale = 2.5f;
float center_width = (StickCP2.Display.width() / 2);
float center_height = (StickCP2.Display.height() / 2);

void bootScreen() {
  const char* filePath = "/FoxArtGrBor.png";

  drawCenteredPNG(filePath);  // Draw PNG image, defined in Utils

  StickCP2.Display.drawString("Foxware", StickCP2.Display.width() / 2, 10);
}