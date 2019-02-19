#pragma once
#include "BakingRecepy.h"

//A Scones classs derived from the base class BakingRecepy
class Scones :
	public BakingRecepy
{
public:
	Scones();
	void bakeIt() override;
};

