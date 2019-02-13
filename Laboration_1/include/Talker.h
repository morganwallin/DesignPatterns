#pragma once
#include <iostream>
#include <string>

class Talker {
private:
public:
	Talker() {};
	virtual ~Talker() {};
	virtual void saySomething()=0;
};