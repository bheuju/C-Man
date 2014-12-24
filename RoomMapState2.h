#pragma once
#include "GameState.h"
#include "PlayState.h"
#include "GameObject.h"
#include <vector>
#include <string>
#include <list>

class RoomMapState2 : public PlayState
{
public:
	RoomMapState2(Vector2D* pos, GameObject* hero)
	{
		target = pos;
		this->hero = hero;
	}
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const
	{
		return roomMapID;
	}

private:
	static const std::string roomMapID;

};

