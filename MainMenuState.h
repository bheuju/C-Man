/* ==================== Main Menu State =================== 
 Menu Shown when the Game first boots up. i.e,
 New Game
 Load Game
 Exit Game
 -------------------------------------------------------- 
 
======================================================== */

#pragma once
#include "GameState.h"
#include "GameObject.h"
#include <vector>

class MainMenuState : public GameState
{
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const
	{
		return menuID;
	}

private:
	static const std::string menuID;

	static bool loadOptions;
	static bool loadCredits;

	static void menuToPlay();
	static void exitFromMenu();

	static void menuToOptions();
	static void menuToCredits();

	std::vector<GameObject*> mGOs;
};

