#ifndef _DEMO_FONT_INO_
#define _DEMO_FONT_INO_

void demoFont() 
{
  Serial.println("demoFont");
  showDemoText(TN_FONT);

  myOLED.setFont(OLED_font6x8);
  myOLED.printFlashMsg(0,0, tname[TN_FONT]);

  myOLED.setFont(OLED_font6x8);
  myOLED.printFlashMsg(0, 2, (char *) font_demo_small);
  myOLED.print(0, 5, "1234");

  myOLED.setFont(OLED_font8x16);
  myOLED.printFlashMsg(0, 3, (char *) font_demo_large);

  myOLED.setFont(OLED_fontNum);
  myOLED.print(0, 6, "1234");

  myOLED.setFont(OLED_fontBigNum);
  myOLED.setInverse(true);
  myOLED.print(64, 5, "1234");
  myOLED.setInverse(false);

  OLEDshow();
  delay(3000);
}

#endif