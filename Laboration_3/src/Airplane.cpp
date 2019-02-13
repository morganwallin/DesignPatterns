#include "Airplane.h"

void Airplane::drive() {
	std::cout << "Airplane Wroom wroom \n";
}

void Airplane::steerLeft(int degrees) {
	std::cout << "Airplane Steer left " << degrees << "degrees\n";
}

void Airplane::steerRight(int degrees) {
	std::cout << "Airplane Steer right " << degrees << "degrees\n";
}