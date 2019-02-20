#include "Whisperer.h"

Whisperer::Whisperer() : SoundProducer("Whisper"){
}

void Whisperer::makeSound() {
	std::cout << getSoundName() << ": " << "this is the whisperer";
}