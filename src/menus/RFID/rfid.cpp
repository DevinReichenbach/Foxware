#include "rfid.hpp"

MFRC522 mfrc522(0x28, RST_PIN);  // Create RFID Reader Instance
MFRC522::MIFARE_Key key;         // Key for authentication

void initRFID() {
  Wire.begin(SDA_PIN, SCL_PIN);      // Init I2C Bus
  mfrc522.PCD_Init();                // Initialize RFID
}

void readRFID() {
	// Look for new cards
	if ( ! mfrc522.PICC_IsNewCardPresent()) {
		return;
	}

	// Select one of the cards
	if ( ! mfrc522.PICC_ReadCardSerial()) {
		return;
	}

	// Dump debug info about the card; PICC_HaltA() is automatically called
	mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}

int writeRFID(byte block, byte data[16], byte* keyByte) {
  // Use default key if use doesn't give a key
  byte defaultKey[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
  if (keyByte == nullptr) {
    keyByte = defaultKey;
  }

	if ( ! mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
		return -1;
	}
  
  // Check 6 bytes given through arg
  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = keyByte[i]; 
  }

  // Authenticate RFID
  byte status = mfrc522.PCD_Authenticate(
    MFRC522::PICC_CMD_MF_AUTH_KEY_A,
    block, &key, &(mfrc522.uid)
  );

  // Check for successful authentication
  if (status != MFRC522::STATUS_OK) {
    Serial.print("Auth failed: ");
    Serial.println(mfrc522.GetStatusCodeName(status));
    return -1;
  }

  status = mfrc522.MIFARE_Write(block, data, 16);

  // Check if write was successful
  if (status != MFRC522::STATUS_OK) {
    Serial.print("Write Failed!");
    Serial.println(mfrc522.GetStatusCodeName(status));
    return -2;
  }

  Serial.println("Write successful to block 4!");

  mfrc522.PICC_HaltA();       // Halt PICC
  mfrc522.PCD_StopCrypto1();  // Stop encryption

  return 0;
}

