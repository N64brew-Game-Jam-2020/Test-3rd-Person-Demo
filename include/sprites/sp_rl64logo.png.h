#ifndef sp_rl64logo_png_h
#define sp_rl64logo_png_h

#include <PR/sp.h>

#define rl64logo_pngTRUEIMAGEH	256
#define rl64logo_pngTRUEIMAGEW	256
#define rl64logo_pngIMAGEH	256
#define rl64logo_pngIMAGEW	256
#define rl64logo_pngBLOCKSIZEW	32
#define rl64logo_pngBLOCKSIZEH	32
#define rl64logo_pngSCALEX	1.0
#define rl64logo_pngSCALEY	1.0
#define rl64logo_pngMODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap rl64logo_png_bitmaps[];
extern Gfx rl64logo_png_dl[];

#define NUM_rl64logo_png_BMS  (sizeof(rl64logo_png_bitmaps)/sizeof(Bitmap))

extern Sprite rl64logo_png_sprite;

#endif 

