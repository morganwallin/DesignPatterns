#pragma once
#include "BakingRecepy.h"

//A SockerKaka classs derived from the base class BakingRecepy
class Sockerkaka :
	public BakingRecepy
{
public:
	Sockerkaka();
	void bakeIt() override;
};

