#ifndef _DEMO_TEXT_INO_
#define _DEMO_TEXT_INO_

void demoText()
{
  showDemoText(TN_TEXT);
  myOLED.setFont(OLED_font6x8);
  myOLED.printFlashMsg(0,0, tname[TN_TEXT]);

//  char num[] = "12345";
//  Comment out this long text to save memory
//  char msg[] = "Testing on printing a very long text which require multiple scrolling and sometime it takes time to scroll the screen.";
//  char msg[] = "A dummy long long long long text ....";

  myOLED.setFont(OLED_font6x8);
  for (int i = 0; i < 3; i++)
    myOLED.printFlashMsg(textmsg[i]);

  myOLED.setFont(OLED_font8x16);
  for (int i = 0; i < 3; i++)
    myOLED.printFlashMsg(textmsg[i]);
  OLEDshow();
  delay(3000);

}

#endif