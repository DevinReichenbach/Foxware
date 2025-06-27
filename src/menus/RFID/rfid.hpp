#ifndef RFID_HPP
#define RFID_HPP

#include <MFRC522_I2C.h>

#define RST_PIN 2
#define SDA_PIN 32
#define SCL_PIN 33

void initRFID();
void readRFID();

int writeRFID(byte block, byte data[16], byte* keyByte = nullptr); 

#endif // RFID_HPP
