#pragma once
#include <math.h> 
#include <vector> 
#include "olcPixelGameEngine.h"
class bs2dGravity;
class PhysicsBody 
{
public:
	double xP; //1000km per dot
	double yP;
	double xPPrev; //1000km per dot
	double yPPrev;
	double xV; //1000km/s per dot
	double yV;
	double m; //1000
	double r;
	olc::Pixel c;
	PhysicsBody(double xPos, double yPos, double xVel, double yVel, double mas,olc::Pixel col);
	PhysicsBody();
	void accelerate(std::vector<PhysicsBody>* objects, int length,double dT);
	void move(double dT);
	PhysicsBody* collisionCombine(std::vector<PhysicsBody>& objects);
};