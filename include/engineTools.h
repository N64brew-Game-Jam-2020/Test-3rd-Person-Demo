#ifndef _ENGINETOOLS_H
#define _ENGINETOOLS_H

#include "common.h"

extern float lerp(float val_1, float val_2, float time);
extern float lerpRotation(float val_1, float val_2, float time);
extern OSTime getLapTime(void);
//extern int GetFPS_6();
//extern int GetFPS_12();
//extern int GetFPS_24();

#endif //_ENGINETOOLS_H