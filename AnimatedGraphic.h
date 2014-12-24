#pragma once
#include "SDL.h"

class AnimatedGraphic
{
public:
	void animX()
	{
		mX = 128 * int ((SDL_GetTicks() / 100) % 6);
	}

	void animY()
	{
		//mY = 
	}

private:
	int mX, mY;

};

