#include "Uppgift1.h"

Uppgift1::Uppgift1()
	: soundProducer(), Talker()
{
	
}

Uppgift1::~Uppgift1() {
	delete soundProducer;
}

void Uppgift1::setSoundProducer(SoundProducer* sp) {
	if (soundProducer != nullptr) {
		delete soundProducer;
	}
	soundProducer = sp;
}

void Uppgift1::saySomething() {
	soundProducer->makeSound();
}