/* Includes  ------------------------------------------------------------------*/
#include "utility/Debug.h"
#include "utility/converteur.h"
#include "utility/draw/GUI_Paint.h"

// #define USE_DEBUG 1  // set in platformio.ini

/* Entry point ----------------------------------------------------------------*/
UBYTE *BlackImage;

void setup()
{ 
  #if USE_DEBUG
    DEV_Module_Init();
  #else
    GPIO_Config();
  #endif

  EPD_Init();
  EPD_Clear();

    UWORD Imagesize = ((WIDTH % 8 == 0)? (WIDTH / 8 ): (WIDTH / 8 + 1)) * HEIGHT;
  if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
      printf("Failed to apply for black memory...\r\n");
      while(1);
  }
}

/* The main loop -------------------------------------------------------------*/
void loop()
{
  page1();
  delay(5000);
  page2();
  delay(5000);
  page3();
  delay(5000);
}


void page1()
{
  Paint_NewImage(BlackImage, WIDTH, HEIGHT, 0, WHITE);
  Paint_SelectImage(BlackImage);
  Paint_Clear(WHITE);

  #if USE_DEBUG
    // Paint_SetScale(4);
    Paint_Drawx_y();
    // Paint_SetScale(2);
  #endif

  //TXT
  Paint_DrawString_EN(20,40,"Hello",&Font8,BLACK,WHITE);
  Paint_DrawString_EN(20,48,"Hello",&Font12,WHITE,BLACK);
  Paint_DrawString_EN(20,60,"Hello",&Font16,WHITE,BLACK);
  Paint_DrawString_EN(20,76,"Hello",&Font20,WHITE,BLACK);
  Paint_DrawString_EN(20,96,"Hello",&Font24,WHITE,BLACK);


  //Rounded Rectangle
  Paint_DrawRoundedRectangle(10, 126, 59,  175, 20, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);  //out 
  Paint_DrawRoundedRectangle(34, 150, 35,  151, 24, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);  //in 
  
  Paint_DrawRoundedRectangle(69, 126, 118, 175, 20, BLACK, DOT_PIXEL_1X1, LINE_STYLE_DOTTED); //out
  Paint_DrawRoundedRectangle(93, 150, 94,  151, 24, BLACK, DOT_PIXEL_1X1, LINE_STYLE_DOTTED); //in

  // Chart
  Paint_DrawChartLine(0,  175, 20,  185, 200, BLACK, 1, DOT_PIXEL_1X1, LINE_STYLE_SOLID );
  Paint_DrawChartLine(20, 185, 49,  190, 200, BLACK, 2, DOT_PIXEL_1X1, LINE_STYLE_SOLID );
  Paint_DrawChartLine(49, 190, 64,  190, 200, BLACK, 3, DOT_PIXEL_1X1, LINE_STYLE_SOLID );

  Paint_DrawChartLine(64, 190, 79,  190, 200, BLACK, 4, DOT_PIXEL_1X1, LINE_STYLE_DOTTED );
  Paint_DrawChartLine(79, 190, 128, 175, 200, BLACK, 3, DOT_PIXEL_1X1, LINE_STYLE_DOTTED );

  chart(10, 210 , 100, 290, BLACK);



  EPD_Display_Base(BlackImage);
}

void page2()
{
  Paint_NewImage(BlackImage, WIDTH, HEIGHT, 270, WHITE);

  Paint_SelectImage(BlackImage);
  Paint_Clear(WHITE);
  #if USE_DEBUG
    Paint_Drawx_y();
  #endif
  chart(20, 20 , 210, 110, BLACK);
  EPD_Display_Base(BlackImage);
}


void page3()
{
  Paint_NewImage(BlackImage, WIDTH, HEIGHT, 270, WHITE);

  Paint_SelectImage(BlackImage);
  Paint_Clear(WHITE);
  #if USE_DEBUG
    Paint_Drawx_y();
  #endif

  Paint_DrawString_EN(70,70,"123",&Font24,BLACK,WHITE);
  Paint_SetRotate(ROTATE_90);
  Paint_DrawString_EN(70,70,"123",&Font24,BLACK,WHITE);

  Paint_DrawString_EN(20,30,"ABc 1",&Font16,WHITE,BLACK);
  Paint_SetMirroring(MIRROR_VERTICAL);
  Paint_DrawString_EN(20,30,"ABc 2",&Font16,WHITE,BLACK);
  Paint_SetMirroring(MIRROR_HORIZONTAL);
  Paint_DrawString_EN(20,30,"ABc 3",&Font16,WHITE,BLACK);
  Paint_SetMirroring(MIRROR_ORIGIN);
  Paint_DrawString_EN(20,30,"ABc 4",&Font16,WHITE,BLACK);

  EPD_Display_Base(BlackImage);
}
