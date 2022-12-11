
#include "GUI_Paint.h"
#include "GUI_Chart.h"


// IN DEV 

#define temp_size 1400
///////////////////////////////////// debug data 
int temp_start = 0;
char temps[temp_size+1];
///////////////////////////////////// debug data 


/// @brief try make chart
/// @param minX     X min chart
/// @param minY     Y min chart
/// @param maxX     X Max chatt
/// @param maxY     Y Max chatt
/// @param color    color
void chart(int minX, int minY, int maxX, int maxY, int color) {
    

    ///////////////////////////////////// debug data 
    temp_start = 5;
    temps[0]  = 10;
    temps[1]  = 10;
    temps[2]  = 10;
    temps[3]  = 10;
    temps[4]  = 10;
    temps[5]  = 10;
    ///////////////////////////////////// debug data 


    int max, min;
    min_max(min, max);

    chart_print_back_ground(min, max, minX, minY, maxX, maxY);
    // chart_print_data(min, max, minX, maxX, minY, maxY);
}

void min_max(int &min, int &max )
{
    min = 100;
    max = 0;
    for (int i =0  ; i<=temp_start; i++) {
        if (temps[i] > max) { 
            max = temps[i];
        } 
        if (temps[i]<min) {
            min = temps[i];
        } 
    }
}



void chart_print_back_ground(int min, int max, int minX, int minY, int maxX, int maxY){
    // help ligne
    Paint_DrawRectangle(minX, minY+1                   , maxX, map(1, 0, 4, minY, maxY), BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY, LINE_STYLE_DOTTED);
    Paint_DrawRectangle(minX, map(1, 0, 2, minY, maxY) , maxX, map(3, 0, 4, minY, maxY), BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY, LINE_STYLE_DOTTED);


  // X Y axe 
    Paint_DrawRectangle(minX,maxY, maxX,minY, BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY, LINE_STYLE_SOLID);


  //clean 
    Paint_DrawLine(   minX+1, minY, maxX,minY, WHITE, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
    Paint_DrawLine(   maxX  , minY, maxX,maxY, WHITE, DOT_PIXEL_1X1, LINE_STYLE_SOLID);

  //txt
    int txtX = maxX>minX ? maxX: minX;
    Paint_DrawNum(txtX, ((maxY>minY ? minY: minY-12)), max                   ,&Font12, BLACK, WHITE);
    Paint_DrawNum(txtX, map(1, 0, 4, minY, maxY)-6   , map(3, 0, 4, min, max),&Font12, BLACK, WHITE);
    Paint_DrawNum(txtX, map(1, 0, 2, minY, maxY)-6   , map(1, 0, 2, min, max),&Font12, BLACK, WHITE);
    Paint_DrawNum(txtX, map(3, 0, 4, minY, maxY)-6   , map(1, 0, 4, min, max),&Font12, BLACK, WHITE);
    Paint_DrawNum(txtX, ((maxY>minY ? maxY-12: maxY)), min                   ,&Font12, BLACK, WHITE);

}