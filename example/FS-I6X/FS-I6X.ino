#include "AltIBus.h"             // SoftIBus library
AltSoftSerial IBuspin; //(8, 9); // "serial" port on which we will be running the IBus connection. 
                                 // Since to read values we only need the Rx, just connect pin D7 and leave D8 open

int ch = 14;                      // число каналов радиоаппаратуры RC

void setup()
{
  IBuspin.begin(115200);//the softserial port has to begin at this baud prior to starting it as the IBus port
  Serial.begin(115200);//hardserial for debigging
  IBus.begin(IBuspin);//start the IBus object
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
