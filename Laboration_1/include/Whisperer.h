#pragma once

#include "SoundProducer.h"
#include <iostream>

class Whisperer : public SoundProducer {
public: 
	Whisperer();
	~Whisperer() {};
	void makeSound();
};