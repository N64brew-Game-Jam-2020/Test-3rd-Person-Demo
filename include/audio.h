#ifndef AUDIO_H_   /* Include guard */
#define AUDIO_H_
#include "common.h"
void initAudio(void);
void PlayAmbientLoop(u8 track, int volume);
void PlayAmbientLoopLocal(u8 track, int handle, int volume, int range, Vector3 position);
void PlaySfx(u8 track);
void PlaySfx_Footstep(u8 track);
void PlaySfxVolume(u8 track, int volume);
void Play3dSfx(u8 track, int volume, int range, Vector3 position);

#endif // AUDIO_H_