#pragma once

#include "SoundProducer.h"
#include "Talker.h"
#include "Whisperer.h"
#include "Shouter.h"
#include <iostream>

class Uppgift1: public Talker {
private:
	SoundProducer* soundProducer;
public:
	Uppgift1();
	~Uppgift1();
	void setSoundProducer(SoundProducer* sp);
	void saySomething();
};