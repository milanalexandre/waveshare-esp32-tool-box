#ifndef __EPD_H_ 
#define __EPD_H_ 

// #include "utility/EPD_1in02.h"
// #include "utility/EPD_1in54.h"
// #include "utility/EPD_1in54_V2.h"
// #include "utility/EPD_1in54b.h"
// #include "utility/EPD_1in54b_V2.h"
// #include "utility/EPD_1in54c.h"
// #include "utility/EPD_2in7.h"
// #include "utility/EPD_2in7b.h"
// #include "utility/EPD_2in7b_V2.h"
// #include "utility/EPD_2in9.h"
// #include "utility/EPD_2in9bc.h"
// #include "utility/EPD_2in9b_V3.h"
// #include "utility/EPD_2in9d.h"
// #include "utility/EPD_2in13.h"
// #include "utility/EPD_2in13_V2.h"
// #include "utility/EPD_2in13_V3.h"
// #include "utility/EPD_2in13bc.h"
// #include "utility/EPD_2in13b_V3.h"
// #include "utility/EPD_2in13b_V4.h"
// #include "utility/EPD_2in13d.h"
// #include "utility/EPD_2in66.h"
// #include "utility/EPD_2in66b.h"
// #include "utility/EPD_3in7.h"
// #include "utility/EPD_4in01f.h"
// #include "utility/EPD_4in2.h"
// #include "utility/EPD_4in2bc.h"
// #include "utility/EPD_4in2b_V2.h"
// #include "utility/EPD_5in65f.h"
// #include "utility/EPD_5in83.h"
// #include "utility/EPD_5in83_V2.h"
// #include "utility/EPD_5in83bc.h"
// #include "utility/EPD_5in83b_V2.h"
// #include "utility/EPD_7in5.h"
// #include "utility/EPD_7in5_V2.h"
// #include "utility/EPD_7in5bc.h"
// #include "utility/EPD_7in5b_V2.h"
// #include "utility/EPD_7in5_HD.h"
#include "utility/EPD_2in9_V2.h"
#include "utility/EPD_7in5b_HD.h"

#define EPD_2in9  1
// #define EPD_7in5B_HD 1 

#if EPD_2in9
    #define WIDTH               EPD_2IN9_V2_WIDTH
    #define HEIGHT              EPD_2IN9_V2_HEIGHT
    #define EPD_Init            EPD_2IN9_V2_Init
    #define EPD_Clear           EPD_2IN9_V2_Clear
    #define EPD_Clear           EPD_2IN9_V2_Clear
    #define EPD_Display_Base    EPD_2IN9_V2_Display_Base    
#endif

#if EPD_7in5B_HD
    #define WIDTH               EPD_7IN5B_HD_WIDTH
    #define HEIGHT              EPD_7IN5B_HD_HEIGHT
    #define EPD_Init            EPD_7IN5B_HD_Init
    #define EPD_Clear           EPD_7IN5B_HD_Clear
    #define EPD_Clear           EPD_7IN5B_HD_Clear
    #define EPD_Display_Base    EPD_7IN5B_HD_Display    
#endif
#endif