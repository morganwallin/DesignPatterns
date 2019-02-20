#pragma once
#include <string>


class SoundProducer {
private:
	std::string soundName;

public:
	SoundProducer();
	explicit SoundProducer(std::string nameOfSound);
	virtual ~SoundProducer() = default;
	virtual void makeSound()=0;
	std::string getSoundName();
};