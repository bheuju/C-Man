#include "InputHandler.h"
#include "Game.h"

InputHandler* InputHandler::pInstance = 0;

InputHandler::InputHandler()
{
	mKeyState = 0;
	for (int i = 0; i < 3; i++)
	{
		mMouseButtonStates.push_back(false);
	}
	mMousePosition = new Vector2D(0, 0);
	keyPress = false;
}

void InputHandler::update()
{
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			Game::Instance()->quit();
			break;

		case SDL_KEYDOWN:
			onKeyDown();
			break;

		case SDL_KEYUP:
			keyPress = false;
			onKeyUp();
			break;

		case SDL_MOUSEBUTTONDOWN:
			onMouseButtonDown();
			break;

		case SDL_MOUSEBUTTONUP:
			onMouseButtonUp();
			break;

		case SDL_MOUSEMOTION:
			onMouseMotion();
			break;

		default:
			break;
		}
	}
}

void InputHandler::onKeyDown()
{
	mKeyState = SDL_GetKeyboardState(0);
	//std::cout<<"Key is pressed\n";
}

void InputHandler::onKeyUp()
{
	mKeyState = SDL_GetKeyboardState(0);
	//std::cout<<"Key is released\n";
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if (mKeyState != 0)
	{
		if (mKeyState[key] == 1)
		{
			return true;
		}
	}
	return false;
}

void InputHandler::onMouseButtonDown()
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		mMouseButtonStates[LEFT] = true;
	}
	if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		mMouseButtonStates[MIDDLE] = true;
	}
	if (event.button.button == SDL_BUTTON_RIGHT)
	{
		mMouseButtonStates[RIGHT] = true;
	}
}

void InputHandler::onMouseButtonUp()
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		mMouseButtonStates[LEFT] = false;
	}
	if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		mMouseButtonStates[MIDDLE] = false;
	}
	if (event.button.button == SDL_BUTTON_RIGHT)
	{
		mMouseButtonStates[RIGHT] = false;
	}
}

void InputHandler::onMouseMotion()
{
	mMousePosition->setX(event.motion.x);
	mMousePosition->setY(event.motion.y);
}

void InputHandler::resetMouseButtons()
{
	for (int i = 0; i < 3; i++)
	{
		mMouseButtonStates[i] = false;
	}
}

InputHandler::~InputHandler()
{
	delete mKeyState;
}

