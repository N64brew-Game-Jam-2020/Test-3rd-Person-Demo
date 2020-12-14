#ifndef MAIN_H
#define MAIN_H

#ifdef _LANGUAGE_C

#include "common.h"

#include "gametitle.h"
#include "level01.h"


#define ENABLE  1
#define DISABLE 0
#define NULL    0
#define STATIC_SEGMENT	1	// Segment number for LOD model
//#define GFX_DL_BUF_SIZE	0x3000	// Buffer size for display list
//#define GFX_DL_BUF_SIZE	0x6000	// Buffer size for display list
//#define CAR_VERTS 726
//#define STAGE_VERTS 780
//#define MAX_TRAIL 20
//#define MAX_EXPLOSION 40

// The stage number and structure  
extern volatile int stage;
//Controller structure
extern NUContData ContTriger[NU_CONT_MAXCONTROLLERS];
// pause from main.c
extern int Pause;



//extern void gamemain(int);
//extern void gametitle(int);
static u8 GetStage();

extern void loadLevel(unsigned int Index);
extern void initLevels(void);



typedef struct{
    u16	button;			/* A,B,C,Z,L,R,START,PAD ,button 	*/
    s8	stick_x;		/* The range of the practical use  -61 <= stick X <= 61	*/
    s8	stick_y;		/* The range of the practical use  -63 <= stick Y <= 63	*/
} ContTrace;

#endif /* _LANGUAGE_C */
#endif /* MAIN_H */
