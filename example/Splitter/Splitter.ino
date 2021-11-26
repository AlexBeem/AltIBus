#include <AltSoftSerial.h>

#define P_RX 8                        // Reception PIN (SoftSerial)
#define P_TX 9                        // Transmition PIN (SoftSerial)

AltSoftSerial iBUS(P_RX, P_TX);     // Software serial port for control the Bluetooth module

void setup()
{
  iBUS.begin(115200); // Initialize the serial port
  Serial.begin(115200);
}

void loop()
{
    // Basic Echo Test
    if(iBUS.available())
    Serial.write(iBUS.read());
}
