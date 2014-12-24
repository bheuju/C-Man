/* ====================== Play State====================== 
Everything that happens during the game play is mentioned
here. 
--------------------------------------------------------- 
May include other states to change to when requires
like:	Pause State
Combat State (Yet to be created)
======================================================== */

#pragma once
#include "GameState.h"
#include "GameObject.h"
#include "CollisionManager.h"
#include "DialogManager.h"
#include "DialogParser.h"
#include "CollisionObjectParser.h"
#include "CharacterParser.h"
#include <vector>
#include <list>

class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const
	{
		return playID;
	}

protected:
	static const std::string playID;
	static Vector2D* target;

	GameObject* layer0;		//Background Map
	GameObject* layer1;     //Background map below hero
	GameObject* layer2;     //Background map above hero
	GameObject* hero;		//Hero Character Object

	std::vector<GameObject*> npcGOs;	//npc character objects
	std::vector<GameObject*> fGOs;	//faces of characters
	std::vector<GameObject*> mCOs;		//collision rectangles - stored after reading from file
	std::vector<GameObject*> mDOs;		//collision rectangles - stored after reading from file

	std::list <std::string> dialog;		//stores dialog after reading from file

	int npcID;
	bool secondPress;

	DialogParser *d1;
	CollisionManager cm;
	CharacterParser cp;
	CollisionObjectParser coMaps, coDoors;
	void handleDialog();
};

