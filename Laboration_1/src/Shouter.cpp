#include "Shouter.h"

Shouter::Shouter() {
	setSoundName("Shout");
}

void Shouter::makeSound() {
	std::cout << getSoundName() << ": " << "THIS IS THE SHOUTER";
}