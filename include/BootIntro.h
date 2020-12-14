#ifndef BOOTINTRO_H_   /* Include guard */
#define BOOTINTRO_H_

#include "common.h"

//back ground color
extern uint32_t BGC_R;
extern uint32_t BGC_G;
extern uint32_t BGC_B;
static char fullScreenFadeAlpha = 255;

void DrawFade(char fade_alpha);
void Render64x64Tile(char gfx[], short lut[], u8 x, u8 y);
void DrawSlide(u8 slideIndex);
void DrawStartPrompt();

#endif // BOOTINTRO_H_