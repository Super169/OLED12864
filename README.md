# OLED12864

Arduino ESP8266 project for OLED12864 display (based on SSD1306 & SH1106).

The project comes from [PlatformIO.SSD12864].
The old one is a sample project for ESP8266 migration of my utilities, which has been used in [GRBLController] project.

By the time I received this OLED years ago, there does not have a i2c library available, and the seller suggest me to develop my own library, and I have used this one on my own projects.

Although there are many alternative on OLED12864 nowadays, which can support more chips.  However, as my project may focus on a particular display (said SSD1306 OLED 12864), I'd prefer to keep this one on my own projects.


## Installation

This is a Visual Studio Code project with PlatformIO IDE.
This is a library project only, it can't be executed in PlatformIO, it should be included in other project.

- Install [Visual Studio Code]
- Install the PlatformIO IDE extension
- Open your project
- Put this library under the lib folder
- Start using the library in your project

## Hardware

- OLED 12864 display with SSD1306 or SH1106 chip

## Pin Assignment

| Arduino | ESP8266 | Usage |
| ------ | ------ | ------ |
| A5 | GPIO-5 | SCL |
| A4| GPIO-4 | SDA |

[PlatformIO.SSD12864]: <https://github.com/Super169/PlatformIO.SSD12864.git>
[GRBLController]: <https://github.com/Super169/GRBLController.git>
[Visual Studio Code]: <https://code.visualstudio.com/>
