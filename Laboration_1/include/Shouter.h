#pragma once

#include <iostream>
#include "SoundProducer.h"

class Shouter : public SoundProducer {
public:
	~Shouter() {};
	Shouter();
	void makeSound();
};