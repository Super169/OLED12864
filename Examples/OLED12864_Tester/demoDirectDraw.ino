#ifndef _DEMO_DIRECTDRAW_INO_
#define _DEMO_DIRECTDRAW_INO_

//
// This feature is not recommended for drawing, if directDraw is enabled, it can save memory for buffering, but it keep updating the screen for any byte updated
// as a result, the screen will keep flashing, and the program is running much slower
// In this sample, it just draw the whole bar on screen (not the delat), but you can find it getting slower when the bar getting long.
// Since the bar comtain number of bytes to update, and the screen will be updated directly for every byte.
// But if we only update the delta only, it can be very fast, as the screen only updated once everytime.
// 
// So, if you can control the delta for update, directDraw is good, otherwise, it's not recommended to use it in drawing.
// But for text output, the system can handle it well, you can use it if needed.
// Sometimes you may want to slow down the drawing to demonstrate the details, for example if directDraw is on for demoDrawing & demoPlotter, it can show how the graph is draw.
//

unsigned long dd_time1, dd_time2, dd_time3;

void demoDirectDraw()
{
  showDemoText(TN_DIRECTDRAW);
  dd_time1 = dd_time2 = dd_time3 = 0;

  myOLED.clr();
  myOLED.setFont(OLED_font6x8);
  myOLED.print(0,0,"DirectDraw ON");
  myOLED.show();
  delay(1000);

  myOLED.setDirectDraw(true);
  drawPlotter();
  delay(2000);

  myOLED.setDirectDraw(false);
  myOLED.clr();
  myOLED.print(0,3,"DirectDraw OFF");
  myOLED.show();
  delay(1000);
  
  myOLED.setDirectDraw(false);
  drawPlotter();
  myOLED.show();
  delay(1000);

  ddDemo01();
  ddShowTime();
  delay(1000);

  ddDemo02();
  ddShowTime();
  delay(1000);

  ddDemo03();
  ddShowTime();
  delay(2000);

  // Restore directDraw setting as for demo
  myOLED.setDirectDraw(directDraw);
}

void ddDemo01() {
  myOLED.setDirectDraw(false);
  myOLED.clr();
  myOLED.print(0,0,"DirectDraw - OFF");
  myOLED.drawRect(0,16,127,23, OLED_MODE_DRAW, OLED_STYLE_EMPTY);
  myOLED.show();
  dd_time1 = millis();
  for (int i = 0; i < 127; i++) {
    myOLED.drawRect(1,18,i,21, OLED_MODE_DRAW, OLED_STYLE_FILL);
    myOLED.show(2);
  }
  dd_time1 = millis() - dd_time1;
}

void ddDemo02() {
  myOLED.setDirectDraw(true);
  myOLED.clr();
  myOLED.print(0,0,"DirectDraw - Full");
  myOLED.drawRect(0,16,127,23, OLED_MODE_DRAW, OLED_STYLE_EMPTY);
  dd_time2 = millis();
  for (int i = 0; i < 127; i++) {
    myOLED.drawRect(1,18,i,21, OLED_MODE_DRAW, OLED_STYLE_FILL);
  }
  dd_time2 = millis() - dd_time2;
}

void ddDemo03() {
  myOLED.setDirectDraw(true);
  myOLED.clr();
  myOLED.print(0,0,"DirectDraw - Delta");
  myOLED.drawRect(0,16,127,23, OLED_MODE_DRAW, OLED_STYLE_EMPTY);
  dd_time3 = millis();
  for (int i = 0; i < 127; i++) {
    myOLED.drawRect(i,18,i,21, OLED_MODE_DRAW, OLED_STYLE_FILL);
  }
  dd_time3 = millis() - dd_time3;
}

void ddShowTime() {
  if (dd_time1) {
    myOLED.print(0,4,"OFF:");
    myOLED.printNum(42,4,dd_time1, 10, 8);
  }
  if (dd_time2) {
    myOLED.print(0,5,"Full:");
    myOLED.printNum(42,5,dd_time2, 10, 8);
  }
  if (dd_time3) {
    myOLED.print(0,6,"Delta:");
    myOLED.printNum(42,6,dd_time3, 10, 8);
  }
  myOLED.show();
}

#endif