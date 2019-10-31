#pragma once
#include "bs2dGravity.h"
	bs2dGravity::bs2dGravity()
	{
		ShowCursor(FALSE);
		bodys.resize(1);
		bodys[0] =* new PhysicsBody(750, 500, 0, 0, 2000000, olc::Pixel(255, 0, 0));
		//bodys[1] =* new PhysicsBody(850, 500, 0, sqrt(200000/100), 30, olc::Pixel(0, 123, 200));
		//bodys[2] = *new PhysicsBody(250, 500, 0, sqrt(200000 /500) * .314 * 1.5, 13, olc::Pixel(123, 0, 200));
		//bodys[3] = *new PhysicsBody(1050, 500, 0, sqrt(200000 / 300), 20, olc::Pixel(123, 170, 0));
		//bodys[4] = *new PhysicsBody(1250, 500, 0, sqrt(200000 / 500) * -.314 * 1.5, 13, olc::Pixel(123, 255, 15));
		bs2dGravity::sAppName = "2D Newtonian Gravity Simulator - onelonecoder.com";
	}
	bool bs2dGravity::OnUserCreate() 
	{
		// Called once at the start, so create things here
		
		return true;
	}
	bool bs2dGravity::OnUserUpdate(float fElapsedTime) 
	{
		//std::cout << bs2dGravity::createVelAngParam << "\n";
		//FillRect(0, 0, ScreenWidth(), ScreenHeight(), olc::Pixel(0, 0, 0));
		for (int i = 0; i < bs2dGravity::bodys.size(); i++)
		{
			FillCircle(bs2dGravity::bodys[i].xPPrev, bs2dGravity::bodys[i].yPPrev, bs2dGravity::bodys[i].r, olc::Pixel(0, 0, 0));
			//FillCircle(bs2dGravity::bodys[i].xPPrev, bs2dGravity::bodys[i].yPPrev, 2, olc::Pixel(255, 255, 255));
			//DrawLine(bs2dGravity::bodys[i].xP, bs2dGravity::bodys[i].yP, bs2dGravity::bodys[i].xP + bs2dGravity::bodys[i].xV * 20, bs2dGravity::bodys[i].yP, olc::Pixel(125, 100, 0));
			//DrawLine(bs2dGravity::bodys[i].xP, bs2dGravity::bodys[i].yP, bs2dGravity::bodys[i].xP, bs2dGravity::bodys[i].yP + bs2dGravity::bodys[i].yV * 20, olc::Pixel(15, 245, 0));
		}
		for (int k = 0; k < 1; k++)
		{
			
			for (int i = 0; i < bs2dGravity::bodys.size(); i++)
			{
				std::cout << bs2dGravity::bodys[0].m << "\n";
				bs2dGravity::bodys[i].accelerate(&bodys, bodys.size(), .1);
			}
			for (int i = 0; i < bs2dGravity::bodys.size(); i++)
			{
				bs2dGravity::bodys[i].move(.1);
			}
		}
		for (int i = 0; i < bs2dGravity::bodys.size(); i++)
		{
			//FillCircle(bs2dGravity::bodys[i].xP - bs2dGravity::bodys[i].xV, bs2dGravity::bodys[i].yP - bs2dGravity::bodys[i].yV, 1, olc::Pixel(255,255,255));
			FillCircle(bs2dGravity::bodys[i].xP, bs2dGravity::bodys[i].yP, bs2dGravity::bodys[i].r, bs2dGravity::bodys[i].c);
			bs2dGravity::bodys[i].xPPrev = bs2dGravity::bodys[i].xP;
			bs2dGravity::bodys[i].yPPrev = bs2dGravity::bodys[i].yP;
		}
		bs2dGravity::prevCreateVelAngParam = bs2dGravity::createVelAngParam;
		bs2dGravity::prevCreateVelMagParam = bs2dGravity::createVelMagParam;
		if (GetMouse(0).bPressed)
		{
			bodys.resize(bodys.size() + 1);
			bodys[bodys.size() - 1] = *new PhysicsBody(GetMouseX(), GetMouseY(), cos(bs2dGravity::createVelAngParam) * bs2dGravity::createVelMagParam, sin(bs2dGravity::createVelAngParam) * bs2dGravity::createVelMagParam, bs2dGravity::createMassParam, olc::Pixel((double)rand() / RAND_MAX * 255, (double)rand() / RAND_MAX * 255, (double)rand() / RAND_MAX * 255));
		}
		if (GetKey(olc::UP).bHeld || GetKey(olc::W).bHeld)
		{
			bs2dGravity::createVelMagParam += 12 * fElapsedTime;
		}
		if (GetKey(olc::DOWN).bHeld || GetKey(olc::S).bHeld)
		{
			bs2dGravity::createVelMagParam -= 12 * fElapsedTime;
		}
		if (GetKey(olc::LEFT).bHeld || GetKey(olc::A).bHeld)
		{
			bs2dGravity::createVelAngParam -= 3.14 * fElapsedTime;
		}
		if (GetKey(olc::RIGHT).bHeld || GetKey(olc::D).bHeld)
		{
			bs2dGravity::createVelAngParam += 3.14 * fElapsedTime;
		}
		if (GetKey(olc::C).bPressed)
		{
			bs2dGravity::bodys.resize(0);
			FillRect(0, 0, ScreenWidth(), ScreenHeight(), olc::Pixel(0, 0, 0));
		}
		bs2dGravity::prevCreateMassParam = bs2dGravity::createMassParam;
		//if(GetKey(olc::SCROLL).bPressed)
		if (bs2dGravity::createMassParam > 50)
			bs2dGravity::createMassParam += GetMouseWheel() * (createMassParam / 1000.0);
		else
			bs2dGravity::createMassParam = 51;
		DrawLine(bs2dGravity::prevMouseX, bs2dGravity::prevMouseY, bs2dGravity::prevMouseX + cos(bs2dGravity::prevCreateVelAngParam) * bs2dGravity::prevCreateVelMagParam * 20, bs2dGravity::prevMouseY + sin(bs2dGravity::prevCreateVelAngParam) * bs2dGravity::prevCreateVelMagParam * 20,olc::Pixel(0,0,0));
		DrawCircle(bs2dGravity::prevMouseX, bs2dGravity::prevMouseY, pow((bs2dGravity::prevCreateMassParam / 3.14), 1.0 / 3.0) * 1.3, olc::Pixel(0,0,0));
		bs2dGravity::prevMouseX = GetMouseX();
		bs2dGravity::prevMouseY = GetMouseY();
		DrawCircle(bs2dGravity::prevMouseX, bs2dGravity::prevMouseY, pow((bs2dGravity::createMassParam / 3.14), 1.0 / 3.0) * 1.3, olc::Pixel(255,255,255));
		DrawLine(bs2dGravity::prevMouseX, bs2dGravity::prevMouseY, bs2dGravity::prevMouseX + cos(bs2dGravity::createVelAngParam) * bs2dGravity::createVelMagParam * 20, bs2dGravity::prevMouseY + sin(bs2dGravity::createVelAngParam) * bs2dGravity::createVelMagParam * 20, olc::Pixel(255, 255, 255));
		/*// called once per frame, draws random coloured pixels
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
				Draw(x, y, olc::Pixel(rand() % 255, rand() % 255, rand() % 255));
		return true;Z*/
		for (int i = 0; i < bs2dGravity::bodys.size(); i++)
		{
			int temp = bs2dGravity::bodys[i].collisionCombine(bs2dGravity::bodys);
			if (temp >= 0)
			{
				FillCircle(bs2dGravity::bodys[temp].xP, bs2dGravity::bodys[temp].yP, bs2dGravity::bodys[temp].r, olc::Pixel(0, 0, 0));
				bs2dGravity::bodys.erase(bs2dGravity::bodys.begin() + temp);
			}
		}
		return true;
	}
