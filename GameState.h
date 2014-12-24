/* ===================== Game State ====================== 
 This class is an abstract base class that is inherited by
 other game states
 -------------------------------------------------------- 
 
======================================================== */

#pragma once
#include <iostream>

class GameState
{
public:
	virtual void update() = 0;
	virtual void render() = 0;
	
	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;

	virtual std::string getStateID() const = 0;

private:
	enum gameStates
	{
		MENU = 0,
		PLAY = 1,
		CUTSCENES = 2,
		GAMEOVER = 3
	};
};