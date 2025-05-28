#include "ir.hpp"
#include <vector>

IRsend irsend(IR_PIN); // Define IrSend

void initializeIR() {
  irsend.begin();
  pinMode(LED_PIN, OUTPUT);
}

/**
 * @brief 1st Main IR Function
 */
void universalTVOff() {
  File powerCodesCSV = SPIFFS.open("/power_codes.csv", "r"); // Open CSV with power codes

  int target_row = 1;
  String* cols = readCSVRow(powerCodesCSV, target_row); // Initial Read

  while (cols[0] != "") {
    cols = readCSVRow(powerCodesCSV, target_row);
    // Send NEC Code if given
    if (cols[3] == "NEC") {
      uint8_t addr = (uint8_t)convertStringToHex(cols[4], 1);
      uint8_t cmd = (uint8_t)convertStringToHex(cols[5], 1);

      irsend.sendNEC(convertCSVEntryToNEC(addr, cmd), 32);
    }
    target_row++;
  }

  powerCodesCSV.close();
}

/**
 * @brief convert hex string to int, typecast desired size based on nBytes parameter
 * 
 * @param entry Hex String
 * @param nBytes The number of bytes to return and mask (0xFFFF)
 * @return uint32_t by default, typecast to desired amount of nBytes given Ex. uint8_t --> nBytes = 1 or uint16_t --> nBytes = 2
 */
uint32_t convertStringToHex(String entry, int nBytes = 0) {
  entry.trim();
  entry.replace(" ", "");
  uint32_t retEntry = (uint32_t)strtoul(entry.c_str(), NULL, 16);

  uint8_t shift = 0; // Return entire Hex Val if nBytes not given
  uint32_t mask = 0xFFFFFFFF;

  if (nBytes == 1) {
    shift = 24;
    mask = 0xFF;
  } else if (nBytes == 2) {
    shift = 16;
    mask = 0xFFFF;
  }

  return (retEntry >> shift) & mask;
}

/**
 * @brief Reverse address and command then structure for NEC
 * 
 * @param address 
 * @param command 
 * @return uint32_t 
 */
uint32_t convertCSVEntryToNEC(uint8_t address, uint8_t command) {
  // Reverse bits for address and command
  uint8_t revAddr = 0;
  uint8_t revCmd = 0;
  for (int i = 0; i < 8; i++) {
    revAddr |= ((address >> i) & 1) << (7 - i);
    revCmd |= ((command >> i) & 1) << (7 - i);
  }

  // Construct 32-bit NEC code: [revAddr][~revAddr][revCmd][~revCmd]
  uint32_t necCode = ((uint32_t)revAddr << 24) |
                     ((uint32_t)(~revAddr & 0xFF) << 16) |
                     ((uint32_t)revCmd << 8) |
                     (uint32_t)(~revCmd & 0xFF);

  return necCode;
}
/**
 * @brief Read CSV entry at a given starting row, assuming an entry is 6 rows long
 * 
 * @param csvFile 
 * @param targetRow Row to start reading from 
 * @return String* 
 */
String* readCSVRow(File &csvFile, int targetRow) {
  static String columns[POWER_CODE_COLUMNS];
  // Make array empty
  for (int i = 0; i < POWER_CODE_COLUMNS; i++) {
    columns[i] = "";
  }

  csvFile.seek(0);  // Move to beginning of file

  int currentRow = 0;
  String line;

  while (csvFile.available()) {
    line = csvFile.readStringUntil('\n');  // Read entire line
    line.trim(); // Remove spaces
    if (line.length() == 0) continue; // Skip empty lines

    if (currentRow == targetRow) {
      int start = 0;
      int commaIndex;
      int col = 0;

      // Get each argument from comma separated line
      while ((commaIndex = line.indexOf(',', start)) != -1 && col < POWER_CODE_COLUMNS - 1) {
        columns[col++] = line.substring(start, commaIndex);
        columns[col - 1].trim();
        start = commaIndex + 1;
      }

      // Last column
      columns[col++] = line.substring(start);
      columns[col - 1].trim();

      // In case fewer columns, clear remaining
      for (; col < POWER_CODE_COLUMNS; col++) {
        columns[col] = "";
      }

      return columns;
    }
    currentRow++;
  }

  return columns;   // If row not found, return array with empty strings
}