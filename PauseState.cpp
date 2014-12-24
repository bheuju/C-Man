#include "PauseState.h"
#include "Game.h"
#include "MainMenuState.h"
#include "MenuButton.h"
#include "InputHandler.h"
#include "Camera.h"

const std::string PauseState::pauseID = "PAUSE";

void PauseState::update()
{
	for (int i = 0; i < mGOs.size(); i++)
	{
		mGOs[i]->update();
	}
}

void PauseState::render()
{
	for (int i = 0; i < mGOs.size(); i++)
	{
		mGOs[i]->draw();
	}
}

bool PauseState::onEnter()
{
	TexManager::Instance()->load("assets/main.png", "mainbutton");
	TexManager::Instance()->load("assets/resume.png", "resumebutton");

	mGOs.push_back(new MenuButton(new LoaderParams("mainbutton", 200, 100, 200, 80, 0, 0), pauseToMenu));
	mGOs.push_back(new MenuButton(new LoaderParams("resumebutton", 200, 300, 200, 80, 0, 0), resumePlay));

	return true;
}

bool PauseState::onExit()
{
	for (int i = 0; i < mGOs.size(); i++)
	{
		mGOs[i]->clean();
	}
	mGOs.clear();

	TexManager::Instance()->clearFromTextureMap("resumebutton");
	TexManager::Instance()->clearFromTextureMap("menubutton");

	InputHandler::Instance()->resetMouseButtons();

	Camera::Instance()->setTarget(target);		//on exiting pausestate refocus the camera to HERO, target is assigned from passed value

	return true;
}

void PauseState::pauseToMenu()
{
	Game::Instance()->getStateMachine()->changeState(new MainMenuState);
}

void PauseState::resumePlay()
{
	Game::Instance()->getStateMachine()->popState();
}

