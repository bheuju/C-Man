/* ================= Game State Machine ================== 
 Manages game states.
 Push State
 Change State
 Delete State
 --------------------------------------------------------- 
  
======================================================== */

#pragma once
#include "GameState.h"
#include <iostream>
#include <vector>
#include <string>

class GameStateMachine
{
public:
	void update();
	void render();

	void pushState(GameState* pState);
	void changeState(GameState* pState);
	void popState();

private:
	std::vector<GameState*> mGS;
};

