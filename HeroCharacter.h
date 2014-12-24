/* =================== Hero Character ====================
This class handles the main character (HERO)
Inherited from CharacterGameObject. 
-------------------------------------------------------- 
Conisits the features of CharacterGameObject Class
======================================================== */

#pragma once
#include "CharacterGameObject.h"

class HeroCharacter : public CharacterGameObject
{
public:
	HeroCharacter(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();

	void handleInput();
	void collision(bool talkable = false);

	int getRow()
	{
		return mRow;
	}

	bool isColliding()
	{
		return mCollision;
	}

	bool canTalk()
	{
		return talk;
	}

	int getCollisionDirn()
	{
		return mRow;
	}

private:
	bool mCollision;	//required for dialog when facing to NPC
	bool talk;			//decides if hero can talk or no with the collision object - set true if collide with npc

};

