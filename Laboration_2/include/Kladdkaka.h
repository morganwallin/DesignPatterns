#pragma once
#include "BakingRecepy.h"

//A Kladdkaka classs derived from the base class BakingRecepy
class Kladdkaka :
	public BakingRecepy
{
public:
	Kladdkaka();
	void bakeIt() override;
};

