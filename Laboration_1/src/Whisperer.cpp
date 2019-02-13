#include "Whisperer.h"

Whisperer::Whisperer() {
	setSoundName("Whisper");
}

void Whisperer::makeSound() {
	std::cout << getSoundName() << ": ";
}