# Waveshare Screen Tools

## Introduction

This project provides a collection of reusable objects for Waveshare screens and ESP32 cards. It is based on the code provided by [Waveshare](https://www.waveshare.com/wiki/E-Paper_ESP32_Driver_Board) and has been tested with the: 
 - `2in9_V2`
 - `7in5b_HD`

![Example Image](img/IMG.jpg)

## Installation

This project uses [PlatformIO](https://platformio.org/). Pin definitions can be found in [DEV_Config.h](./src/DEV_Config.h).

| Code | PIN | Shield  |
| ---  | --- | ---     |
| BUSY | 25  | BUSY    |
| RST  | 26  | RST     |
| DC   | 27  | DC      |
| CS   | 15  | CS      |
| SCK  | 13  | SCK     |
| MOSI | 16  | DIN     |
|      |     | VCC     |
|      |     | GND     |

To disable debug mode, remove the "-DUSE_DEBUG=1" line from platformio.ini.

## Functionality Added

- Fixed an issue with displaying negative numbers and 0: `Paint_DrawNum(0, 0, -1, &Font12, BLACK, WHITE)`.
- Added a function to display the X and Y axes: `Paint_Drawx_y()`.
- Added a function to draw a chart line: `Paint_DrawChartLine(20, 185, 49, 190, 200, BLACK, 2, DOT_PIXEL_1X1, LINE_STYLE_SOLID)`.
- Added a parameter to specify the line style for rectangles: `Paint_DrawRectangle(10, 10, 50, 50, BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY, LINE_STYLE_DOTTED)`.
- Added a function to draw rounded rectangles: `Paint_DrawRoundedRectangle(10, 10, 50, 50, 4, BLACK, DOT_PIXEL_1X1, LINE_STYLE_DOTTED)`.
