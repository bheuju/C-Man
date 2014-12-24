#pragma once
#include "SDL.h"
#include "CharacterGameObject.h"
#include "GameStateMachine.h"
#include "SDL_ttf.h"

class Game
{
public:
	static Game* Instance()
	{
		if (pInstance == 0)
		{
			pInstance = new Game();
		}
		return pInstance;
	}

	void init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void update();
	void handleEvents();
	void render();
	void clean();

	bool isRunning()
	{
		return mRunning;
	}

	SDL_Renderer* getRenderer()
	{
		return ren;
	}

	void quit()
	{
		mRunning = false;
	}

	GameStateMachine* getStateMachine()
	{
		return mGSM;
	}

private:
	static Game* pInstance;
	Game(){}

	bool mRunning;
	SDL_Window* win;
	SDL_Renderer* ren;

	//CharacterGameObject* cGO;
	GameObject* go;
	GameStateMachine* mGSM;

	int mFrame;
};