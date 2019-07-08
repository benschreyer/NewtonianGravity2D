#pragma once
#include "PhysicsBody.h"
	PhysicsBody::PhysicsBody(double xPos, double yPos, double xVel, double yVel, double mas, olc::Pixel col)
	{
		PhysicsBody::c = col;
		PhysicsBody::m = mas;
		PhysicsBody::r = sqrt((m / 3.14)) * 1.3;
		PhysicsBody::xPPrev = 0;
		PhysicsBody::yPPrev = 0;
		PhysicsBody::xP = xPos;
		PhysicsBody::yP = yPos;
		PhysicsBody::xV = xVel;
		PhysicsBody::yV = yVel;
	}
	PhysicsBody::PhysicsBody()
	{
		;
	}
	void PhysicsBody::accelerate(PhysicsBody* objects, int length, double dT)
	{
		for (int i = 0; i < length; i++)
		{
			if (objects + i != this)
			{
				double preproc = pow((xP - ((objects + i)->xP)), 2) + pow((yP - ((objects + i)->yP)), 2);
				PhysicsBody::xV -= 1.00 * dT * (((objects + i)->m) * (xP - ((objects + i)->xP)))/ (sqrt(preproc) * preproc);
				PhysicsBody::yV -= 1.00 * dT * (((objects + i)->m) * (yP - ((objects + i)->yP))) / (sqrt(preproc) * preproc);
			}
		}
	}
	void PhysicsBody::move(double dT)
	{
		PhysicsBody::xP += dT * xV;
		PhysicsBody::yP += dT * yV;
	}