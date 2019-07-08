#pragma once
#include "bs2dGravity.h"
#include <iostream>
	bs2dGravity::bs2dGravity()
	{
		bodys[0] =* new PhysicsBody(750, 500, 0, 0, 20000, olc::Pixel(255, 0, 0));
		bodys[1] =* new PhysicsBody(1700, 500, 0, 2.5, 90, olc::Pixel(0, 123, 200));
		bodys[2] = *new PhysicsBody(100, 500, 0, -4, 220, olc::Pixel(123, 0, 200));
		bodys[3] = *new PhysicsBody(0, 7000000, 6.9, 1, 75, olc::Pixel(123, 244, 0));
		bs2dGravity::sAppName = "2D Newtonian Gravity Simulator";
	}
	bool bs2dGravity::OnUserCreate() 
	{
		// Called once at the start, so create things here
		
		return true;
	}
	bool bs2dGravity::OnUserUpdate(float fElapsedTime) 
	{
		std::cout << bs2dGravity::bodys[0].xV << " __ " << bs2dGravity::bodys[0].yV << "\n";
		//FillRect(0, 0, ScreenWidth(), ScreenHeight(), olc::Pixel(0, 0, 0));
		for (int i = 0; i < bs2dGravity::bodyCount; i++)
		{
			FillCircle(bs2dGravity::bodys[i].xPPrev, bs2dGravity::bodys[i].yPPrev, bs2dGravity::bodys[i].r, olc::Pixel(0, 0, 0));
			//DrawLine(bs2dGravity::bodys[i].xP, bs2dGravity::bodys[i].yP, bs2dGravity::bodys[i].xP + bs2dGravity::bodys[i].xV * 20, bs2dGravity::bodys[i].yP, olc::Pixel(125, 100, 0));
			//DrawLine(bs2dGravity::bodys[i].xP, bs2dGravity::bodys[i].yP, bs2dGravity::bodys[i].xP, bs2dGravity::bodys[i].yP + bs2dGravity::bodys[i].yV * 20, olc::Pixel(15, 245, 0));
		}
		for (int k = 0; k < 1; k++)
		{
			for (int i = 0; i < bs2dGravity::bodyCount; i++)
			{
				bs2dGravity::bodys[i].accelerate(bodys, bodyCount, 0.1);
			}
			for (int i = 0; i < bs2dGravity::bodyCount; i++)
			{
				bs2dGravity::bodys[i].move(0.1);
			}
		}
		for (int i = 0; i < bs2dGravity::bodyCount; i++)
		{
			FillCircle(bs2dGravity::bodys[i].xP, bs2dGravity::bodys[i].yP, bs2dGravity::bodys[i].r, bs2dGravity::bodys[i].c);
			bs2dGravity::bodys[i].xPPrev = bs2dGravity::bodys[i].xP;
			bs2dGravity::bodys[i].yPPrev = bs2dGravity::bodys[i].yP;
		}
		/*// called once per frame, draws random coloured pixels
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
				Draw(x, y, olc::Pixel(rand() % 255, rand() % 255, rand() % 255));
		return true;Z*/
		return true;
	}