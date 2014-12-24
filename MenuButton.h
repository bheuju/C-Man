/* ====================== Menu Button ====================== 
Creates buttons for menu and handles them
----------------------------------------------------------- 

============================================================ */

#pragma once
#include "GameObject.h"
#include "Vector2D.h"

class MenuButton : public GameObject
{
public:
	MenuButton(const LoaderParams* pParams, void (*callback)());

	virtual void draw();
	virtual void update();
	virtual void clean();

private:
	void (*mCallback)();

	bool mReleased;

	enum buttonState
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};
};
