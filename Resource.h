#pragma once
#include "SDL.h"
#include <cstdlib>

static int flag;

static bool checkCollision(SDL_Rect* A, SDL_Rect* B)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Get sides of A
	leftA = A->x;
	rightA = A->x + A->w;
	topA = A->y;
	bottomA = A->y + A->h;

	//Get sides of B
	leftB = B->x;
	rightB = B->x + B->w;
	topB = B->y;
	bottomB = B->y + B->h;

	//No collision
	if (bottomA <= topB) {return false;}
	if (topA >= bottomB) {return false;}
	if (rightA <= leftB) {return false;}
	if (leftA >= rightB) {return false;}

	//There has been a collision
	return true;
}

static bool delay(int n)		//Independent Delay
{
	int time = (SDL_GetTicks() / 100) % n;		//sets delay by number after % (i.e. n*100 ms)

	if (time == 0 && flag == 1)
	{
		flag = 0;
		return true;
	}
	else if (time > 0)
	{
		flag = 1;
	}
	return false;
}
