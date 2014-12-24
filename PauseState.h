/* ===================== Pause State ===================== 
 Pauses the game play. Resumes from where paused.
 --------------------------------------------------------- 
  
======================================================== */

#pragma once
#include "GameState.h"
#include "GameObject.h"
#include <vector>

class PauseState : public GameState
{
public:
	PauseState(Vector2D* pos){ target = pos; }
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const
	{
		return pauseID;
	}

private:
	static const std::string pauseID;

	Vector2D* target;

	static void pauseToMenu();
	static void resumePlay();

	std::vector<GameObject*> mGOs;
};

