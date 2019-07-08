#pragma once
#include "PhysicsBody.h"
#include "olcPixelGameEngine.h"
class bs2dGravity : public olc::PixelGameEngine
{ 
public:
	bs2dGravity();
public:
	int bodyCount = 4;
	PhysicsBody bodys[4];
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
}; 
