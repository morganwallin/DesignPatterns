#pragma once
#include "BakingRecepy.h"

#include <string>

//A Pizza classs derived from the base class BakingRecepy
class Pizza :
	public BakingRecepy
{
public:
	Pizza();
	void bakeIt() override;
};

