#ifndef _DEMO_BITMAP_INO_
#define _DEMO_BITMAP_INO_

void demoBitmap() 
{
  // Display BMP as font
  showDemoText(TN_BITMAP);

  myOLED.setFont(BMP12864, false);

  myOLED.print(0,0, "0");
  OLEDshow();
  delay(2000);
  
  myOLED.clr();
  OLEDshow();
  myOLED.print(0,0, "1");
  OLEDshow();
  delay(2000);
}

#endif
