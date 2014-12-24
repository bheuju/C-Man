#include "MainMenuState.h"
#include "TexManager.h"
#include "MenuButton.h"
#include "Game.h"
#include "PlayState.h"
#include "InputHandler.h"

const std::string MainMenuState::menuID = "MENU";
bool MainMenuState::loadOptions = false;
bool MainMenuState::loadCredits = false;

void MainMenuState::update()
{
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_BACKSPACE))
	{
		loadOptions = false;
		loadCredits = false;
	}
	for (int i = 0; i < mGOs.size(); i++)
	{
		mGOs[i]->update();
	}
}

void MainMenuState::render()
{
	TexManager::Instance()->drawMap("mainbg", 0, 0, 640, 480, 0, 0);
	for (int i = 0; i < mGOs.size(); i++)
	{
		mGOs[i]->draw();
	}
	if (loadOptions)
	{
		TexManager::Instance()->drawMap("optionsbg", 0, 0, 640, 480, 0, 0);
	}
	if (loadCredits)
	{
		TexManager::Instance()->drawMap("creditsbg", 0, 0, 640, 480, 0, 0);
	}
}

bool MainMenuState::onEnter()
{
	TexManager::Instance()->load("assets/mainbg.png", "mainbg");
	TexManager::Instance()->load("assets/optionsmenu.png", "optionsbg");
	TexManager::Instance()->load("assets/creditmenu.png", "creditsbg");

	TexManager::Instance()->load("assets/newgame.png", "newgame");
	TexManager::Instance()->load("assets/options.png", "options");
	TexManager::Instance()->load("assets/credit.png", "credits");
	TexManager::Instance()->load("assets/exitgame.png", "exitgame");

	mGOs.push_back(new MenuButton(new LoaderParams("newgame", 450, 250, 130, 39, 0, 0), menuToPlay));
	mGOs.push_back(new MenuButton(new LoaderParams("options", 450, 300, 130, 39, 0, 0), menuToOptions));
	mGOs.push_back(new MenuButton(new LoaderParams("credits", 450, 350, 130, 39, 0, 0), menuToCredits));
	mGOs.push_back(new MenuButton(new LoaderParams("exitgame", 450, 400, 130, 39, 0, 0), exitFromMenu));

	std::cout<<"Entering MainMenuState\n";
	return true;
}

bool MainMenuState::onExit()
{
	for (int i = 0; i < mGOs.size(); i++)
	{
		mGOs[i]->clean();
	}
	mGOs.clear();
	TexManager::Instance()->clearFromTextureMap("mainbg");
	TexManager::Instance()->clearFromTextureMap("optionbg");
	TexManager::Instance()->clearFromTextureMap("creditsbg");
	TexManager::Instance()->clearFromTextureMap("newgame");
	TexManager::Instance()->clearFromTextureMap("options");
	TexManager::Instance()->clearFromTextureMap("credits");
	TexManager::Instance()->clearFromTextureMap("exitgame");

	std::cout<<"Exiting MainMenuState\n";
	return true;
}

void MainMenuState::menuToPlay()
{
	Game::Instance()->getStateMachine()->changeState(new PlayState);
	std::cout<<"Play Button Clicked\n";
}

void MainMenuState::exitFromMenu()
{
	Game::Instance()->quit();
	std::cout<<"Exit Button Clicked\n";
}

void MainMenuState::menuToOptions()
{
	loadOptions = true;
}
void MainMenuState::menuToCredits()
{
	loadCredits = true;
}