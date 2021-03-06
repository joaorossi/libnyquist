/*
Copyright (c) 2015, Dimitri Diakopoulos All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

// This file implements a simple sound file player based on RtAudio for testing / example purposes.

#ifndef AUDIO_DEVICE_H
#define AUDIO_DEVICE_H

#include "Common.h"
#include "RingBuffer.h"
#include "rtaudio/RtAudio.h"

namespace nqr
{

	const uint32_t FRAME_SIZE = 512;
	const int32_t CHANNELS = 2;
	const int32_t BUFFER_LENGTH = FRAME_SIZE * CHANNELS;

	struct AudioDeviceInfo
	{
		uint32_t id;
		uint32_t numChannels;
		uint32_t sampleRate;
		uint32_t frameSize;
		bool isPlaying = false;
	};

	class AudioDevice
	{
		NO_MOVE(AudioDevice);
		std::unique_ptr<RtAudio> rtaudio;
	public:
    
		AudioDeviceInfo info;
    
		AudioDevice(int numChannels, int sampleRate, int deviceId = -1);
		~AudioDevice();
    
		bool Open(const int deviceId);
		bool Play(const std::vector<float> & data);

		bool Record(const uint32_t lengthInSamples, std::vector<float> & recordingBuffer);
        
		static void ListAudioDevices();
	};
    
} // end namespace nqr

#endif
