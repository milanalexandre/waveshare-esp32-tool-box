/* Includes  ------------------------------------------------------------------*/
#include "utility/Debug.h"
#include "utility/converteur.h"
#include "GUI_Paint.h"

#define USE_DEBUG 1

/* Entry point ----------------------------------------------------------------*/
void setup()
{ 
  #if USE_DEBUG
    DEV_Module_Init();
  #else
    GPIO_Config();
  #endif

  EPD_Init();
  EPD_Clear();
  UBYTE *BlackImage;

    UWORD Imagesize = ((WIDTH % 8 == 0)? (WIDTH / 8 ): (WIDTH / 8 + 1)) * HEIGHT;
  if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
      printf("Failed to apply for black memory...\r\n");
      while(1);
  }
  Paint_NewImage(BlackImage, WIDTH, HEIGHT, 0, WHITE);
  Paint_SelectImage(BlackImage);
  Paint_Clear(WHITE);

  #if USE_DEBUG
    Paint_Drawx_y();
  #endif


  Paint_DrawString_EN(20,40,"Hello",&Font8,BLACK,WHITE);
  Paint_DrawString_EN(20,48,"Hello",&Font12,WHITE,BLACK);
  Paint_DrawString_EN(20,60,"Hello",&Font16,WHITE,BLACK);
  Paint_DrawString_EN(20,76,"Hello",&Font20,WHITE,BLACK);
  Paint_DrawString_EN(20,96,"Hello",&Font24,WHITE,BLACK);

  EPD_Display_Base(BlackImage);
}


/* The main loop -------------------------------------------------------------*/
void loop()
{
  //
}
