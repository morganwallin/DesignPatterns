#include "Uppgift1.h"
#include "SoundProducer.h"
#include "Whisperer.h"
#include "Shouter.h"
#include "memstat.hpp"

int main()
{
	Uppgift1 uppg1;
	uppg1.setSoundProducer(new Whisperer);
	uppg1.saySomething();
	std::cout << "\n";
	uppg1.setSoundProducer(new Shouter);
	uppg1.saySomething();
	int input;
	std::cin >> input;
    return 0;
}

