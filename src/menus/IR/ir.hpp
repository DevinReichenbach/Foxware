#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <Arduino.h>
#include <SPIFFS.h> 

#define POWER_CODE_COLUMNS 6

const uint_fast8_t IR_PIN = 19; // For StickCPlus2
const uint_fast8_t LED_PIN = 10;

const uint_fast8_t NEC_CODES_LENGTH = 11; 
const uint16_t NEC_CODES[NEC_CODES_LENGTH] = {10, 0, 31, 224, 149, 23, 15, 28, 8, 21, 18};

void initializeIR();
void universalTVOff();

uint32_t convertStringToHex(String entry, int nBytes);
uint32_t convertCSVEntryToNEC(uint8_t address, uint8_t command);

String* readCSVRow(File &csvFile, int targetRow);