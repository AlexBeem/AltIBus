#include "AltIBus.h"             // AltIBus library
AltSoftSerial IBuspin; //(8, 9);     // "serial" port on which we will be running the IBus connection. 
                                 // Since to read values we only need the Rx, just connect pin D8 and leave D9 open

int ch = 10;                      // число каналов радиоаппаратуры FlySky FS-I6S

void setup()
{
  IBuspin.begin(115200);  // the softserial port has to begin at this baud prior to starting it as the IBus port
  Serial.begin(115200);   // hardserial for debigging
  IBus.begin(IBuspin);    // start the IBus object
}

void loop()
{
  static uint16_t inibus;
  IBus.loop();
  for (int i = 0; i < ch; i++)
  {
    inibus = IBus.readChannel(i);
    if (i < ch - 1)
    {
      Serial.print(inibus);
      Serial.print("\t");
    } else {
      Serial.println(inibus);
    }
  }
}
