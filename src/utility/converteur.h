#ifndef __EPD_H_ 
#define __EPD_H_ 

// #include "screen/EPD_1in02.h"
// #include "screen/EPD_1in54.h"
// #include "screen/EPD_1in54_V2.h"
// #include "screen/EPD_1in54b.h"
// #include "screen/EPD_1in54b_V2.h"
// #include "screen/EPD_1in54c.h"
// #include "screen/EPD_2in7.h"
// #include "screen/EPD_2in7b.h"
// #include "screen/EPD_2in7b_V2.h"
// #include "screen/EPD_2in9.h"
// #include "screen/EPD_2in9bc.h"
// #include "screen/EPD_2in9b_V3.h"
// #include "screen/EPD_2in9d.h"
// #include "screen/EPD_2in13.h"
// #include "screen/EPD_2in13_V2.h"
// #include "screen/EPD_2in13_V3.h"
// #include "screen/EPD_2in13bc.h"
// #include "screen/EPD_2in13b_V3.h"
// #include "screen/EPD_2in13b_V4.h"
// #include "screen/EPD_2in13d.h"
// #include "screen/EPD_2in66.h"
// #include "screen/EPD_2in66b.h"
// #include "screen/EPD_3in7.h"
// #include "screen/EPD_4in01f.h"
// #include "screen/EPD_4in2.h"
// #include "screen/EPD_4in2bc.h"
// #include "screen/EPD_4in2b_V2.h"
// #include "screen/EPD_5in65f.h"
// #include "screen/EPD_5in83.h"
// #include "screen/EPD_5in83_V2.h"
// #include "screen/EPD_5in83bc.h"
// #include "screen/EPD_5in83b_V2.h"
// #include "screen/EPD_7in5.h"
// #include "screen/EPD_7in5_V2.h"
// #include "screen/EPD_7in5bc.h"
// #include "screen/EPD_7in5b_V2.h"
// #include "screen/EPD_7in5_HD.h"
#include "screen/EPD_2in9_V2.h"
#include "screen/EPD_7in5b_HD.h"

#define EPD_2in9  1
// #define EPD_7in5B_HD 1 

#if EPD_2in9
    #define WIDTH               EPD_2IN9_V2_WIDTH
    #define HEIGHT              EPD_2IN9_V2_HEIGHT
    #define EPD_Init            EPD_2IN9_V2_Init
    #define EPD_Clear           EPD_2IN9_V2_Clear
    #define EPD_Display_Base    EPD_2IN9_V2_Display_Base
    #define EPD_Display_Partial EPD_2IN9_V2_Display_Partial
    #define EPD_Sleep           EPD_2IN9_V2_Sleep


#endif

#if EPD_7in5B_HD
    #define WIDTH               EPD_7IN5B_HD_WIDTH
    #define HEIGHT              EPD_7IN5B_HD_HEIGHT
    #define EPD_Init            EPD_7IN5B_HD_Init
    #define EPD_Clear           EPD_7IN5B_HD_Clear
    #define EPD_Display_Base    EPD_7IN5B_HD_Display
    #define EPD_Sleep           EPD_7IN5B_HD_Sleep
    // #define EPD_Display_Partial EPD_7IN5B_HD_Display_Partial
#endif
#endif