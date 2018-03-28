#ifndef _DEMO_NUMERIC_INO_
#define _DEMO_NUMERIC_INO_

void demoNumeric()
{
  showDemoText(TN_NUMERIC);

  myOLED.setFont(OLED_font6x8);
  myOLED.printFlashMsg(0,0, tname[TN_NUMERIC]);
  
  myOLED.print(0, 2, (long) random(0,1000000), 0, false);
  myOLED.print(64, 2, (int) random(0,32767), 5, true);
  myOLED.println(0, 3, "1.2345: (2) : (5,8)");
  myOLED.printFloat(1.2345,2);
  myOLED.print(" : ");
  myOLED.printFloat(1.2345, 5, 8);
  myOLED.println(0, 6, "Display HEX 0xF");
  myOLED.printHex(0,7, 0xF, 0, false);
  myOLED.print(":");
  myOLED.printHex(0xF, 2, false);
  myOLED.print(":");
  myOLED.printHex(0xF, 2, true);
  myOLED.print(":");
  myOLED.printHex(0xF, 3, false);
  myOLED.print(":");
  myOLED.printHex(0xF, 3, true);
  myOLED.print(":");
  myOLED.printHex(0xF, 4, true);

  // to verify the buffer
  OLEDshow();
  delay(3000);
  
}

#endif