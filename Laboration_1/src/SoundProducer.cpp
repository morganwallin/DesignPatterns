#include "SoundProducer.h"
#include <string>

SoundProducer::SoundProducer() {}

SoundProducer::SoundProducer(std::string nameOfSound) {
	soundName = nameOfSound;
}

std::string SoundProducer::getSoundName() {
	return soundName;
}

void SoundProducer::setSoundName(std::string pmSoundName) {
	soundName = pmSoundName;
}