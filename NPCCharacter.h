/* =================== NPCs Character ====================
 Handles Non Playable Character: Generally like villagers
 Inherited from CharacterGameObject. 
 -------------------------------------------------------- 
 Conisits the features of CharacterGameObject Class
======================================================== */

#pragma once
#include "CharacterGameObject.h"

class NPCCharacter : public CharacterGameObject
{
public:
	NPCCharacter(const LoaderParams* pParams, int id);

	virtual void draw();
	virtual void update();
	virtual void clean();

	void handleInput();
	void animateNPC(bool move = false);
	void collision(int row);

	int getNpcID()
	{
		return npcID;
	}

private:
	int npcID;

};

