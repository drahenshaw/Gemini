#ifndef GEMINI_AUDIO
#define GEMINI_AUDIO

#include "al.h"
#include "alc.h"
#include <stdio.h>

constexpr int kNUMBUFFERS = 2;

class Audio
{
public:
	
	void Initialize();
	void LoadWAVFile();

private:
	ALCdevice  * audio_device_;
	ALCcontext * audio_context_;
	ALuint audio_buffers_[kNUMBUFFERS];
	ALuint audio_source_;

};


#endif
