#pragma once
#include <iostream>
#include <string>

class Talker {
private:
public:
	Talker() {};
	virtual ~Talker() = default;
	virtual void saySomething()=0;
};