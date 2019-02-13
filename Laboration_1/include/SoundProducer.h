#pragma once
#include <string>


class SoundProducer {
private:
	std::string soundName;

public:
	SoundProducer();
	SoundProducer(std::string nameOfSound);
	virtual ~SoundProducer();
	virtual void makeSound()=0;
	std::string getSoundName();
	void setSoundName(std::string pmSoundName);
};