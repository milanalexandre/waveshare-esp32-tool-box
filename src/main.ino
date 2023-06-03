/* Includes  ------------------------------------------------------------------*/
#include "utility/Debug.h"
#include "utility/converteur.h"
#include "utility/draw/GUI_Paint.h"
#include "image.h"

// #define USE_DEBUG 1  // set in platformio.ini

/* Entry point ----------------------------------------------------------------*/
UBYTE *BlackImage;
#if EPD_7in5B_HD
  UBYTE *RYImage;
#endif


int data[] = {58, 280, 214, 372, 20, 287, 132, 150};
int size = 8;

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
  #if EPD_7in5B_HD
    if ((RYImage = (UBYTE *)malloc(Imagesize)) == NULL) {
      printf("Failed to apply for red memory...\r\n");
      while(1);
    }
  #endif
  page1();
  delay(5000);
  page2();
  delay(5000);
  page3();
  delay(5000);
  page4(0);
  delay(1000);
  page4(90);
  delay(1000);
  page4(180);
  delay(1000);
  page4(270);
  delay(1000);

  Paint_NewImage(BlackImage, WIDTH, HEIGHT, 270, WHITE);
  Paint_SelectImage(BlackImage);
  Paint_Clear(WHITE);

  
}

/* The main loop -------------------------------------------------------------*/

unsigned long time_now_s;
PAINT_TIME sPaint_time;
  int x   = 0;
  int y   = 0;
  int pvX = 0;
  int pvY = 0;
  int dX  = 1;
  int dY  = 1;
  int step  = 0;

#if EPD_2in9
void loop()
{
  time_now_s = (millis()) / 1000;
  sPaint_time.Day   = time_now_s / 60 / 60 / 24;
  sPaint_time.Hour  = time_now_s / 60 / 60 / 24;
  sPaint_time.Min   = time_now_s / 60 % 60;
  sPaint_time.Sec   = time_now_s % 60;
  step ++;
  if (step == 5) {
    step =0;
    Paint_ClearWindows(pvX, pvY, pvX + Font20.Width * 7, pvY + Font20.Height, WHITE);

    Paint_DrawTime(x, y, &sPaint_time, &Font20, WHITE, BLACK);
    EPD_Display_Partial(BlackImage);
    pvY = y;
    pvX = x;
  }
  
  x= x+dX;
  y= y+dY;

  if ((x +Font20.Width * 7)>HEIGHT || (x)<=0 ){ //296
    dX = (dX==1)?-1:1;
    x = x+dX+dX;
  }
  if ((y +Font20.Height)>WIDTH || (y)<=0){ //129
    dY = (dY==1)?-1:1;
    y = y+dY+dY;
  }
}
#endif

#if EPD_7in5B_HD
void loop(){}
#endif


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

  Paint_Chart(10, 210, 100, 290, data, size, BLACK);

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
  Paint_Chart(20, 20 , 210, 110, data, size, BLACK);
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

void page4(uint16_t Rotate) {
  Paint_NewImage(BlackImage, WIDTH, HEIGHT, Rotate, WHITE);
  Paint_SelectImage(BlackImage);
  Paint_Clear(WHITE);
  Paint_Drawx_y();
  Paint_DrawImage(IMAGE_DATA, 4, 88, 120, 120);
  
  EPD_Display_Base(BlackImage);
}