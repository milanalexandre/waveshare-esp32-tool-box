# Waveshare Screen Tools
## Introduction

This project is a list of reusable objects for waveshare screen and for esp32 cards it is based on the code provided by [waveshare](https://www.waveshare.com/wiki/E-Paper_ESP32_Driver_Board). 

Tested with the 2in9_V2
![](img/IMG.jpg)



## Installation
This project uses [platformio](https://platformio.org/)
Pin definition is done in [DEV_Config.h](./src/DEV_Config.h). 


|code|PIN|shield|
| - | - | - |
|BUSY |25| BUSY	
|RST  |26| RST	
|DC   |27| DC	
|CS   |15| CS	
|SCK  |13| SCK	
|MOSI |16| DIN	
|||VCC	
|||GND	

To change the debug mode in you have to delete "-DUSE_DEBUG=1" platformio.ini

## functionality add
- Fix for displaying negative numbers and 0 `Paint_DrawNum(0, 0, -1, &Font12, BLACK, WHITE)`
- add diplay X Y axis `Paint_Drawx_y()`
- add chart line `Paint_DrawChartLine(20, 185, 49,  190, 200, BLACK, 2, DOT_PIXEL_1X1, LINE_STYLE_SOLID )`
- add LINE_STYLE parameter for retangle  `Paint_DrawRectangle(10, 10 , 50, 50, BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY, LINE_STYLE_DOTTED)`
- add rounded rectangle  `Paint_DrawRoundedRectangle(10, 10, 50, 50, 4, BLACK, DOT_PIXEL_1X1, LINE_STYLE_DOTTED)`
