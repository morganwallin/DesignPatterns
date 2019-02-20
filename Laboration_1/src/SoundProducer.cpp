#include "SoundProducer.h"
#include <string>

SoundProducer::SoundProducer() {}

SoundProducer::SoundProducer(std::string nameOfSound) {
	soundName = nameOfSound;
}

std::string SoundProducer::getSoundName() {
	return soundName;
}