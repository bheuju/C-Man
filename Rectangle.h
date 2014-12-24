#pragma once
#include "GameObject.h"
#include <SDL.h>

class Rectangle : public GameObject
{
public:
	Rectangle (int xx, int yy, int ww, int hh);
	Rectangle (int xx, int yy, int ww, int hh, std::string id);

	virtual void draw();
	virtual void update();
	virtual void clean();

protected:
	SDL_Rect rect1;

};

