/********************************************************************************************

                       EEPROM-Cleaner v1.1

                       Copyright (c) 2017 Helmut Stult (schinfo)

 ********************************************************************************************/

#include <EEPROM.h>
#include <ESP8266WiFi.h>

#define minByte 4096 // change it for more or less Bytes (Default = 4096)
#define maxByte 1200 // change it for more or less Bytes (Default = 1200)
#define startByte 33 // change it for more or less Bytes (Default = 33)

unsigned long ok = 0;
unsigned long nok = 0;
unsigned long tok = 0;


void setup()
{
  Serial.begin(115200);
  EEPROM.begin(minByte);

  delay(100);

  Serial.println("**************************************************************************");
  Serial.println("");
  Serial.print("             Write a ""0"" from ");
  Serial.print(minByte);
  Serial.print(" to first ");
  Serial.print(maxByte);
  Serial.print(" bytes of the EEPROM");
  Serial.println("");
  Serial.println("");
  Serial.println("**************************************************************************");
  Serial.println("");

  Serial.println("             testing EEPROM for written bytes");
  Serial.println("");

  for (int i = startByte; i < maxByte; ++i)
  {
    if (EEPROM.read(i) == 255) {
      ++ok;
    } else {
      ++nok;
    }
  }
  
  Serial.print("                 empty bytes:   ");
  Serial.println(ok);
  Serial.print("             not empty bytes:   ");
  Serial.println(nok);
  Serial.println("");
  Serial.println("**************************************************************************");
  Serial.println("");

  Serial.println("**************************************************************************");
  Serial.println("");
  Serial.println("             Start clearing EEPROM... - Please wait!!!");
  Serial.println("");
  Serial.println("**************************************************************************");

  delay(3000);

  // write a 0 to first maxByte bytes of the EEPROM
  for (int i = startByte; i < maxByte; ++i) {
    EEPROM.write(i, -1);
  }

  EEPROM.commit();

  delay(2000);

  Serial.println("");
  Serial.println("             testing EEPROM for clearing");
  Serial.println("");

  String test;
  for (int i = startByte; i < maxByte; ++i)
  {
    if (EEPROM.read(i) == 255) {
      ++tok;
    }
    test += char(EEPROM.read(i));
  }
  Serial.println("**************************************************************************");
  Serial.println("");
  if (tok = maxByte - startByte) {
    Serial.println("             EEPROM killed correctly");
  } else
    Serial.println("             EEPROM not killed - ERROR !!!");

  Serial.println("");
  Serial.println("**************************************************************************");
  Serial.println("");
  Serial.println("             Ready - You can remove your ESP8266 / LoLin");
  Serial.println("");
  Serial.println("**************************************************************************");
}

void loop()
{
}
