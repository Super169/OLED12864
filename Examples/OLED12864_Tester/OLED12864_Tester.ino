#define __PROG_TYPES_COMPAT__

#if defined( ESP8266 )
  #include <pgmspace.h>
#else
  #include <avr/pgmspace.h>
#endif

 // About changes of PROGMEM
//   1.6.0: https://github.com/arduino/Arduino/wiki/1.6-Frequently-Asked-Questions
//   1.6.5: http://forum.arduino.cc/index.php?topic=339011.0

#include <Wire.h>
#include "OLED12864.h"

#include "udf.c"
#include "msg.c"

const char msg_welcomeHeader[] PROGMEM = "Welcome OLED12864";
const char msg_welcomeMsg[] PROGMEM = "This is a tesing for OLED12864 Library, it will demonstrate most common features in OLED12864 library.";

char sram_welcomeMsg[] = "This is a tesing for OLED12864 Library, it will demonstrate most common features in OLED12864 library.";

const char font_demo_small[] PROGMEM = "Small: 6x8: Abc";
const char font_demo_large[] PROGMEM = "Large: 8x16: Abc";

static const char msg_1[] PROGMEM = "[1] A long message is memory consumption, it's suggested to put them in flash memory instead of SRAM";
static const char msg_2[] PROGMEM = "[2] By using the flash, a long message can be stored for display.";
static const char msg_3[] PROGMEM = "[3] Another dummy long long long long long text in Flash, it can be much longer than the one in SRAM.  As the flash memory can have 32KB while SRAM only have 2KB,  it's recommended to use flash instead of SRAM for static text.  Good luck!";

static const char * textmsg[] = {msg_1, msg_2, msg_3};
// const char const * textmsg[] PROGMEM  = {msg_1, msg_2, msg_3};

static const char tname_0[] PROGMEM = "Demonstration on";
static const char tname_1[] PROGMEM = "Embeded Fonts";
static const char tname_2[] PROGMEM = "User Defined Font";
static const char tname_3[] PROGMEM = "Scrolling Display";
static const char tname_4[] PROGMEM = "Bitmap Display";
static const char tname_5[] PROGMEM = "Simple Drawing";
static const char tname_6[] PROGMEM = "Plotter";
static const char tname_7[] PROGMEM = "Numeric Display";
static const char tname_8[] PROGMEM = "Mixed Display";
static const char tname_9[] PROGMEM = "DirectDraw";

static const char * tname[] = {tname_0, tname_1, tname_2, tname_3, tname_4, tname_5, tname_6, tname_7, tname_8, tname_9};

#define TN_HEADER   0
#define TN_FONT     1
#define TN_UDF      2
#define TN_TEXT     3
#define TN_BITMAP   4
#define TN_DRAWING  5
#define TN_PLOTTER  6
#define TN_NUMERIC  7
#define TN_MIXTEXT  8
#define TN_DIRECTDRAW  9


boolean enableBuffer = true;
boolean directDraw = false;

//  OLED_1306i2c - 0.96" OLED
//  OLED_1106i2c - 1.3" OLED
OLED12864 myOLED(OLED_1306i2c, enableBuffer, directDraw);


void setup()
{
  
  Serial.begin(115200);
  delay(1000);
  Serial.println();
  Serial.println();
  Serial.println("OLED12864 Tester");

  randomSeed(analogRead(0));  
  
  checkMemory();

  myOLED.begin();
  Serial.println();
  Serial.println("Let's go");

  welcome();
  
  // checkMemory();

}

void checkMemory() {
//  Serial.print("## memory: ");
//  Serial.println(myUtil::availableMemory());
}

void loop()
{
  Serial.println();
  Serial.println("loop started");
  
  myOLED.setDirectDraw(directDraw);
  myOLED.clr();
  myOLED.show();

  demoFont();
  
  demoUDF();
  
  demoText();

  demoNumeric();      

  demoBitmap();   
  
  demoDrawing();      // TODO: Error after running this demo with ESP8266

  demoPlotter();      // problem in ESP8266 // Error after running, cannot reset

  // demoDirectDraw();   // problem in ESP8266  // Error after running, cannot reset

  checkMemory();

  Serial.println();
  Serial.println("loop completed");
  Serial.println();
  Serial.println("Wait for next round");
  delay(5000);

}

void welcome() 
{
  myOLED.clr();
  OLEDshow();
  myOLED.setFont(OLED_font6x8);
  myOLED.printFlashMsg(0,0, msg_welcomeHeader);
  myOLED.printFlashMsg(0,3, msg_welcomeMsg);
  OLEDshow();
  delay(3000);
}

void showDemoText(uint8_t tcode)
{
  Serial.print("showDemoText - ");
  Serial.print(tcode);
  Serial.println();
  myOLED.clr();
  OLEDshow();
  myOLED.setFont(OLED_font6x8);
  myOLED.printFlashMsg(0,1, tname[TN_HEADER]);
  myOLED.printFlashMsg(0,4, tname[tcode]);
  OLEDshow();
  delay(1000);
  myOLED.clr();
  OLEDshow();
}

void OLEDshow() {
  if (!directDraw) myOLED.show();
}



#include "demoBitmap.ino"
#include "demoDirectDraw.ino"
#include "demoDrawing.ino"
#include "demoFont.ino"
#include "demoNumeric.ino"
#include "demoPlotter.ino"
#include "demoText.ino"
#include "demoUDF.ino"
