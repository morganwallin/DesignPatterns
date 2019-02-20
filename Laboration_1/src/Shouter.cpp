#include "Shouter.h"

Shouter::Shouter() : SoundProducer("Shout"){
}

void Shouter::makeSound() {
	std::cout << getSoundName() << ": " << "THIS IS THE SHOUTER";
}