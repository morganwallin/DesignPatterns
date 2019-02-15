#pragma once

#include <iostream>
#include "SoundProducer.h"

class Shouter : public SoundProducer {
public:
	~Shouter() = default;
	Shouter();
	void makeSound();
};