#pragma once
#include "GameState.h"
#include "TexManager.h"
#include "GameObject.h"
#include "CollisionManager.h"
//#include <string>

class CombatState : public GameState
{
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const
	{
		return combatID;
	}

		//friend class  HeroFighter;


private:
	static const std::string combatID;
	GameObject* bg;
	GameObject* go;
	GameObject* go1;

	CollisionManager cm;
};

