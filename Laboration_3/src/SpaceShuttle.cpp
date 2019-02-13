#include "SpaceShuttle.h"

void SpaceShuttle::drive() {
	std::cout << "SpaceShuttle Wroom wroom\n";
}

void SpaceShuttle::steerLeft(int degrees) {
	std::cout << "SpaceShuttle Steer left " << degrees << "degrees\n";
}

void SpaceShuttle::steerRight(int degrees) {
	std::cout << "SpaceShuttle Steer right " << degrees << "degrees\n";
}