#pragma once
#include "PhysicsBody.h"
	PhysicsBody::PhysicsBody(double xPos, double yPos, double xVel, double yVel, double mas, olc::Pixel col)
	{
		PhysicsBody::c = col;
		PhysicsBody::m = mas;
		PhysicsBody::r = pow((m / 3.14),1.0/3.0) * 1.3;
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
	void PhysicsBody::accelerate(std::vector<PhysicsBody>* objects, int length, double dT)
	{
		for (int i = 0; i < length; i++)
		{
			if (&(*objects)[i] != this)
			{
				double preproc = pow(xP - (*objects)[i].xP, 2) + pow(yP - (*objects)[i].yP, 2);
				PhysicsBody::xV -= 1.00 * dT * (*objects)[i].m * (xP - (*objects)[i].xP) / (sqrt(preproc) * preproc);
				PhysicsBody::yV -= 1.00 * dT * (*objects)[i].m * (yP - (*objects)[i].yP) / (sqrt(preproc) * preproc);
			}
		}
	}
	void PhysicsBody::move(double dT)
	{
		PhysicsBody::xP += dT * xV;
		PhysicsBody::yP += dT * yV;
	}
	int PhysicsBody::collisionCombine(std::vector<PhysicsBody>& objects)
	{
		int myIndex = -1;
		for (int i = 0; i < objects.size(); i++)
		{
			
			if (&(objects)[i] != this)
			{
				if (sqrt(pow(xP - (objects)[i].xP, 2) + pow(yP - (objects)[i].yP, 2)) < PhysicsBody::r + (objects)[i].r)
				{
					if (PhysicsBody::m >= (objects)[i].m)
					{
						double oldM = PhysicsBody::m;
						PhysicsBody::m += (objects)[i].m;
						PhysicsBody::r = pow((m / 3.14), 1.0 / 3.0) * 1.3;
						PhysicsBody::xV =(((objects)[i]).xV * ((objects)[i]).m +oldM * PhysicsBody::xV )/ PhysicsBody::m;
						PhysicsBody::yV = (((objects)[i]).yV * ((objects)[i]).m + oldM * PhysicsBody::yV) / PhysicsBody::m;
						return i;
						//(objects).erase((objects).begin() + i);
						
						

					}
					else
					{
				
						if (myIndex >= 0)
						{
							return myIndex;
						}
						for (int j = i + 1; j < objects.size(); j++)
						{
							if (&(objects)[j] == this)
								return j;
						}

						
						
					}
				}
			}
			else
			{
				myIndex = i;
			}
		}
		return -1;
	}
