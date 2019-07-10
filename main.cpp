#pragma once
#define OLC_PGE_APPLICATION
#include "bs2dGravity.h"
#include <Windows.h>
int main()
{
	
	bs2dGravity demo;
	if (demo.Construct(1500, 1080, 1, 1))
	{
		demo.Start();
	}
	return 0;
}