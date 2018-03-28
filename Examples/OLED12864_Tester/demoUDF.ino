#ifndef _DEMO_UDF_INO_
#define _DEMO_UDF_INO_

void demoUDF() 
{
  showDemoText(TN_UDF);
  char msg[6] = {0x10, 0x11, 0x12, 0x13, 0x14, 0x00};
  myOLED.setFont(OLED_font6x8);
  myOLED.printFlashMsg(0,0, tname[TN_UDF]);
  myOLED.setFont(CN16x16, false);
  for (int i=2; i < 7; i += 2) myOLED.print((i-2) * 10, i, msg);
  OLEDshow();
  delay(3000);
}

#endif