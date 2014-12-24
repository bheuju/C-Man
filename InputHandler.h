/* ==================== Input Handler ===================== 
This class handles all the inputs used in the game
(mouse, keyboard)
-------------------------------------------------------- 
Uses singleton
======================================================== */

#pragma once
#include "SDL.h"
#include <vector>
#include "Vector2D.h"

enum mouseButtons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (pInstance == 0)
		{
			pInstance = new InputHandler;
		}
		return pInstance;
	}

	~InputHandler();

	void update();

	//Keyboard Handling Functions
	void onKeyDown();
	void onKeyUp();
	bool isKeyDown(SDL_Scancode key);

	//Mouse Handling Functions
	void onMouseButtonDown();
	void onMouseButtonUp();
	void onMouseMotion();
	void resetMouseButtons();
	bool getMouseButtonState(int buttonNumber)
	{
		return mMouseButtonStates[buttonNumber];
	}
	Vector2D* getMousePosition()
	{
		return mMousePosition;
	}

	//Getters Setters
	void setPressed(bool press)
	{
		keyPress = true;
	}
	bool getPressed()
	{
		return keyPress;
	}
	
private:
	InputHandler();
	static InputHandler* pInstance;

	SDL_Event event;
	bool keyPress;

	const Uint8* mKeyState;
	std::vector<bool> mMouseButtonStates;
	Vector2D* mMousePosition;
};

