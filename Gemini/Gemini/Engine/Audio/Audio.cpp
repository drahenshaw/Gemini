#include "Audio.h"

void Audio::Initialize()
{
	if (alcIsExtensionPresent(NULL, "ALC_ENUMERATION_EXT") == AL_TRUE)
	{	
		// Enumeration Extension Found 
		
		const ALCchar * default_audio_device_name;
		
		
		default_audio_device_name = alcGetString(NULL, ALC_DEFAULT_DEVICE_SPECIFIER);

		ALCdevice * device;
		device = alcOpenDevice(NULL);

		default_audio_device_name = alcGetString(device, ALC_DEVICE_SPECIFIER);
		// actualDeviceName contains the name of the open device 

		ALuint buffers[10];
		ALenum error_state;

		alGetError();
		alGenBuffers(1, buffers);
		error_state = alGetError();


	}

}
