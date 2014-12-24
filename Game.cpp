#include <iostream>
#include "SDL_image.h"
#include "Game.h"
#include "TexManager.h"
#include "HeroCharacter.h"
#include "InputHandler.h"
#include "MainMenuState.h"
#include "PlayState.h"
#include "DialogManager.h"
#include "DialogParser.h"
#include "CombatState.h"

Game*  Game::pInstance = 0;

void Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
	std::cout<<"Initializing...\n";
	SDL_Init(SDL_INIT_EVERYTHING);		//initializing everything
	win = SDL_CreateWindow(title, xpos, ypos, width, height, flags);	//creating window
	std::cout<<"Window Created\n";
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);		//creating renderer
	std::cout<<"Renderer Created\n";

	if (TTF_Init())
	{
		std::cout<<"ttf not initialized\n";
	}
	
	//SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);		//set render clear color

	//TexManager::Instance()->load("assets/boy.png", "boy");						//These two are now loaded in playstate
	//go = new HeroCharacter(new LoaderParams("boy", 300, 228, 41, 36, 0, 1));		//because they appear there

	std::cout<<"Ready to go...1\n";

	DialogManager::Instance()->init("fonts/SourceSansPro-Bold.ttf", 18);
	//DialogManager::Instance()->load("Once upon a time, In a kingdom far away lived a farmer very poor working hard doing chore. He had a son very small asking him for a ball.");
	DialogManager::Instance()->load("");

	//DialogParser d1;// = new DialogParser;
	//d1.parseCharacters("dialogs/text.xml", "npc");
	
	mGSM = new GameStateMachine;
	mGSM->changeState(new MainMenuState);

	mRunning = true;
}

void Game::update()
{
	//mFrame = int ((SDL_GetTicks() / 100) % 6);
	//go->update();
	mGSM->update();
}

void Game::render()
{
	SDL_RenderClear(ren);		//clear to render clear color

	mGSM->render();
	DialogManager::Instance()->draw();

	SDL_RenderPresent(ren);		//display to window
}

void Game::handleEvents()
{
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		mGSM->changeState(new CombatState);
	}

	InputHandler::Instance()->update();
}

void Game::clean()
{
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}