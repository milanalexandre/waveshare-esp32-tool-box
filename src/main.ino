/* Includes  ------------------------------------------------------------------*/
#include "utility/Debug.h"
#include "utility/converteur.h"
#include "GUI_Paint.h"


/* Entry point ----------------------------------------------------------------*/
void setup()
{
  DEV_Module_Init();
  EPD_Init();
  EPD_Clear();
  delay(500);
  UBYTE *BlackImage;

    UWORD Imagesize = ((WIDTH % 8 == 0)? (WIDTH / 8 ): (WIDTH / 8 + 1)) * HEIGHT;
  if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
      printf("Failed to apply for black memory...\r\n");
      while(1);
  }
  Paint_NewImage(BlackImage, WIDTH, HEIGHT, 0, WHITE);
  Paint_SelectImage(BlackImage);
  Paint_Clear(WHITE);


  Paint_DrawString_EN(20,100,"Hello",&Font12,BLACK,WHITE);
  Paint_DrawString_EN(20,120,"Hello",&Font16,WHITE,BLACK);
  Paint_DrawString_EN(20,140,"Hello",&Font20,WHITE,BLACK);
  Paint_DrawString_EN(20,160,"Hello",&Font24,WHITE,BLACK);

  Paint_DrawLine(10,10,40,10,BLACK,DOT_PIXEL_2X2,LINE_STYLE_SOLID);  //X
  Paint_DrawLine(36,7 ,40,10,BLACK,DOT_PIXEL_2X2,LINE_STYLE_SOLID);  //X
  Paint_DrawLine(36,13,40,10,BLACK,DOT_PIXEL_2X2,LINE_STYLE_SOLID);  //X

  Paint_DrawLine(10,10,10,40,BLACK,DOT_PIXEL_2X2,LINE_STYLE_SOLID);  //Y
  Paint_DrawLine(7 ,36,10,40,BLACK,DOT_PIXEL_2X2,LINE_STYLE_SOLID);  //Y
  Paint_DrawLine(13,36,10,40,BLACK,DOT_PIXEL_2X2,LINE_STYLE_SOLID);  //Y
  Paint_DrawString_EN(0,0,"0",&Font12  ,BLACK,WHITE);//X
  Paint_DrawString_EN(40,10,"X",&Font12,BLACK,WHITE);//X
  Paint_DrawString_EN(10,40,"Y",&Font12,BLACK,WHITE);//Y
  EPD_Display_Base(BlackImage);
}


/* The main loop -------------------------------------------------------------*/
void loop()
{
  //
}
