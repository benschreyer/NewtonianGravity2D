#pragma once
#include "PhysicsBody.h"
#include <vector> 
#include <iostream>
#include <math.h>
#include "olcPixelGameEngine.h"
#include <WinUser.h>
class bs2dGravity : public olc::PixelGameEngine
{ 
public:
	bs2dGravity();
public:
	std::vector<PhysicsBody> bodys;
	int prevMouseX = 0;
	int prevMouseY = 0;
	int prevCreateMassParam = 100;
	double prevCreateVelMagParam = 0;
	double prevCreateVelAngParam = 0;
	int createMassParam = 100;
	double createVelMagParam = 0;
	double createVelAngParam = 0; 
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
}; 
