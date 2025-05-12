#include "ir.hpp"

IRsend irsend(IrLed); // Define IrSend

void sendCustomCode(int code) {
  irsend.sendNEC(code);
}