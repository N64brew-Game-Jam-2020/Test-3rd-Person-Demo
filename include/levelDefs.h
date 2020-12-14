#ifndef _LEVELDEFS_H
#define _LEVELDEFS_H

typedef enum LEVELS_t
{
    LEVEL_MAINMENU = 0u,
    LEVEL_01,
    LVLS_SIZE
}LEVELS;

typedef struct
{
    void (*levelInit)(void);
    void (*levelGfx)(unsigned int pendingGfx);
}Level;

Level* lvls[LVLS_SIZE];

//void loadLevel(unsigned int Index);
//void initLevels(void);

//#include "level01.h"
//#include "gametitle.h"


#endif
