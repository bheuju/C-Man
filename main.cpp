/* ==================== Main ===================== 
 This is the main file of the program
 ------------------------------------------------- 
  
================================================ */
#define TIXML_USE_STL
#include "SDL.h"
#include "Game.h"
#include "InputHandler.h"
#include <ctime>
const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char** argv)
{
	srand(time(NULL));
	Uint32 frameStart, frameTime;
	int delay;

	Game::Instance()->init("RPG", 400, 100, 640, 480, SDL_WINDOW_SHOWN);

	while (Game::Instance()->isRunning())
	{
		frameStart = SDL_GetTicks();

		Game::Instance()->handleEvents();
		Game::Instance()->update();
		Game::Instance()->render();

		if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
		{
			delay = DELAY_TIME / 3;
		}
		else
		{
			delay = DELAY_TIME;
		}

		frameTime = SDL_GetTicks() - frameStart;
		if (delay > frameTime)
		{
			SDL_Delay(int(delay - frameTime));
		}
	}

	Game::Instance()->clean();
	return 0;
}
