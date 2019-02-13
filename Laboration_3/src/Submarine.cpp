#include "Submarine.h"


void Submarine::drive() {
	std::cout << "Submarine Wroom wroom \n";
}

void Submarine::steerLeft(int degrees) {
	std::cout << "Submarine Steer left " << degrees << "degrees\n";
}

void Submarine::steerRight(int degrees) {
	std::cout << "Submarine Steer right " << degrees << "degrees\n";
}