/********************************************************************************************

                       EEPROM-Cleaner v1.0

                       Copyright (c) 2017 Helmut Stult (schinfo)

 ********************************************************************************************/

#include <EEPROM.h>
#include <ESP8266WiFi.h>

#define maxByte 1000 // change it for more or less Bytes (Default = 1000)

unsigned long ok = 0;

void setup()
{
  Serial.begin(115200);
  EEPROM.begin(512);

  delay(100);

  Serial.println("**************************************************************************");
  Serial.println("");
  Serial.print("             Write a ""0"" to first ");
  Serial.print(maxByte);
  Serial.print(" bytes of the EEPROM");
  Serial.println("");
  Serial.println("");
  Serial.println("             Start clearing EEPROM... - Please wait!!!");
  Serial.println("");
  Serial.println("**************************************************************************");
  Serial.println("");


  // write a 0 to first maxByte bytes of the EEPROM
  for (int i = 0; i < maxByte; ++i) {
    EEPROM.write(i, -1);
  }

  EEPROM.commit();

  delay(2000);

  Serial.println("             testing EEPROM for clearing");
  Serial.println("");

  String test;
  for (int i = 0; i < maxByte; ++i)
  {
    if (EEPROM.read(i) == 255) {
      ++ok;
    }
    test += char(EEPROM.read(i));
  }
  Serial.println("**************************************************************************");
  Serial.println("");
  if (ok = maxByte - 1) {
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
