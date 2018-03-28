#ifndef _DEMO_DRAWING_INO_
#define _DEMO_DRAWING_INO_


void demoDrawing()
{
  showDemoText(TN_DRAWING);
  unsigned long t = micros();  

  drawBase();

  drawSomething();
  OLEDshow();
  delay(2000);

  demoRect();
}

void drawBase()
{
  myOLED.clr();
  myOLED.drawRect(64,0,127,31,0,1);
  myOLED.drawRect(0,32,63,63,0,1);
  
  // OuterFrame 
  myOLED.drawRect(0,0,127,63,0,0);
  myOLED.drawRect(1,1,126,62,1,0);
  myOLED.drawRect(2,2,125,61,0,0);
}

void drawSomething() {
  myOLED.drawVLine(16, 8,56,0);
  myOLED.drawVLine(32, 8,56,1);
  myOLED.drawVLine(48, 8,56,2);

  myOLED.drawVLine(79, 8,56,0);
  myOLED.drawVLine(95, 8,56,1);
  myOLED.drawVLine(111, 8,56,2);

  myOLED.drawHLine(16, 111, 8, 0);
  myOLED.drawHLine(16, 111, 16, 1);
  myOLED.drawHLine(16, 111, 24, 2);

  myOLED.drawHLine(16, 111, 40, 0);
  myOLED.drawHLine(16, 111, 48, 1);
  myOLED.drawHLine(16, 111, 56, 2);
  
}

void demoRect()
{
  unsigned long t = micros();  
  
  drawBase();

  myOLED.drawRect(16,8,111,55,0,0);
  myOLED.drawRect(32,16,95,47,1,0);
  myOLED.drawRect(44,20,83,43,2,1);
  myOLED.drawRect(46,24,79,39,2,1);

  unsigned long d1, d2;  
  d1 = micros() - t;  
  
  OLEDshow();
  d2 = micros() - t - d1;  
  
  delay(3000);

  myOLED.clr();
  OLEDshow();
}

#endif