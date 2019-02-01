#include "Audio.h"

constexpr int kNUMBUFFERS = 2;

void Audio::Initialize()
{
	// Select the preferred device and make current context
	audio_device_ = alcOpenDevice(NULL);

	if (audio_device_)
	{
		audio_context_ = alcCreateContext(audio_device_, NULL);
		alcMakeContextCurrent(audio_context_);
	}

	// Generate Audio Buffers
	alGetError();
	alGenBuffers(kNUMBUFFERS, audio_buffers_);
	//if ((error = alGetError()) != AL_NO_ERROR)
	//{
	//	Display error (method, error) return;
	//}


	// Generate Audio Listener
	alListener3f(AL_POSITION, 0, 0, 0);
	alListener3f(AL_VELOCITY, 0, 0, 0);
	alListener3f(AL_ORIENTATION, 0, 0, -1);
	

	// Generate Audio Source
	alGenSources(1, &audio_source_);

	// Configure Audio Source
	alSourcef (audio_source_, AL_PITCH, 1);
	alSourcef (audio_source_, AL_GAIN,  1);
	alSource3f(audio_source_, AL_POSITION, 0, 0, 0);
	alSource3f(audio_source_, AL_VELOCITY, 0, 0, 0);
	alSourcei (audio_source_, AL_LOOPING, AL_FALSE);

	// Load Buffer with Audio Data
	alSourcei(audio_source_, AL_BUFFER, audio_buffers_[0]);
	
	
	
	
	
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

void Audio::LoadWAVFile()
{
	/*FILE* f = fopen("audio.wav", "fb");
	char xbuffer[5];
	xbuffer[4] = '\0';
	if (fread(xbuffer, sizeof(char), 4, file) != 4 || strcmp(xbuffer, "RIFF") != 0)
		throw "Not a WAV file";
	

	file_read_int32_le(xbuffer, file);

	if (fread(xbuffer, sizeof(char), 4, file) != 4 || strcmp(xbuffer, "WAVE") != 0)
		throw "Not a WAV file";

	if (fread(xbuffer, sizeof(char), 4, file) != 4 || strcmp(xbuffer, "fmt ") != 0)
		throw "Invalid WAV file";

	file_read_int32_le(xbuffer, file);
	short audioFormat = file_read_int16_le(xbuffer, file);
	short channels = file_read_int16_le(xbuffer, file);
	int sampleRate = file_read_int32_le(xbuffer, file);
	int byteRate = file_read_int32_le(xbuffer, file);
	file_read_int16_le(xbuffer, file);
	short bitsPerSample = file_read_int16_le(xbuffer, file);

	if (audioFormat != 16) {
		short extraParams = file_read_int16_le(xbuffer, file);
		file_ignore_bytes(file, extraParams);
	}

	if (fread(xbuffer, sizeof(char), 4, file) != 4 || strcmp(xbuffer, "data") != 0)
		throw "Invalid WAV file";

	int dataChunkSize = file_read_int32_le(xbuffer, file);
	unsigned char* bufferData = file_allocate_and_read_bytes(file, (size_t)dataChunkSize);

	float duration = float(dataChunkSize) / byteRate;
	alBufferData(buffer, GetFormatFromInfo(channels, bitsPerSample), bufferData, dataChunkSize, sampleRate);
	free(bufferData);
	fclose(f);*/
}
