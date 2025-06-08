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
  String protocol, address, command;

  int target_row = 1;
  String* cols = readCSVRow(powerCodesCSV, target_row); // Initial Read

  while (cols[0] != "") {
    cols = readCSVRow(powerCodesCSV, target_row);

    protocol = cols[3]; address = cols[4]; command = cols[5];

    // Send NEC Code if given
    if (protocol == "NEC") {
      uint8_t addr = (uint8_t)convertStringToHex(address, 1);
      uint8_t cmd = (uint8_t)convertStringToHex(command, 1);

      irsend.sendNEC(convertCSVEntryToNEC(addr, cmd), 32);
    } else if (protocol == "NECext") {       
      uint16_t addr = convertStringToHex(address, 2);  // Extract first two bytes       
      uint16_t cmd = convertStringToHex(command, 2);

      irsend.sendNEC(convertCSVEntryToNECExt(addr, cmd), 32);
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
 * @brief Structure address and command for NECext protocol
 * @param address 
 * @param command 
 * @return uint32_t 
 */
uint32_t convertCSVEntryToNECExt(uint16_t address, uint8_t command) {
  uint8_t revCmd = reverse8(command);
  uint16_t revAddr = reverse16(address);

  uint32_t necExtCode = ((uint32_t) revAddr << 16) |  // Reverse address store in top 2 bytes
                         ((uint32_t)revCmd << 8) |    // Reverse cmd in 3rd byte
                         (uint32_t)(~revCmd & 0xFF);  // Inverted cmd in last byte

  return necExtCode;
}
/**
 * @brief Reverse address and command then structure for NEC
 * @param address 
 * @param command 
 * @return uint32_t 
 */
uint32_t convertCSVEntryToNEC(uint8_t address, uint8_t command) {
  uint8_t revAddr = reverse8(address);
  uint8_t revCmd = reverse8(command);

  uint32_t necCode = ((uint32_t)revAddr << 24) |                // Put 8-bit reversed address in 1st byte
                     ((uint32_t)(~revAddr & 0xFF) << 16) |      // Put 8-bit inverted reversed address in 2nd byte
                     ((uint32_t)revCmd << 8) |                  // 8-bit reversed command in 3rd byte
                     (uint32_t)(~revCmd & 0xFF);                // 8-bit inverted reversed command in 4th byte

  return necCode;
}

/**
 * @brief Reverse byte
 * @param byte 
 * @return uint8_t 
 */
uint8_t reverse8(uint8_t byte) {
  byte = (byte & 0xF0) >> 4 | (byte & 0x0F) << 4;
  byte = (byte & 0xCC) >> 2 | (byte & 0x33) << 2;
  byte = (byte & 0xAA) >> 1 | (byte & 0x55) << 1;
  return byte;
}

/**
 * @brief Reverse 16-bit word
 * @param word 
 * @return uint16_t 
 */
uint16_t reverse16(uint16_t word) {
  return (uint16_t)(reverse8(word & 0xFF) << 8) | reverse8(word >> 8);
}

/**
 * @brief Read CSV entry at a given starting row, assuming an entry is 6 rows long
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