#pragma once
#include "Resource.h"
#include "GameObject.h"
#include <vector>

class CollisionManager
{
public:
	bool checkCameraObjectCollision(GameObject* GOs);								//checks hero - objects collision (to render objects present within camera view)
	int checkHeroNPCCollision(GameObject* hero, std::vector <GameObject*> &npcGOs);				//checks hero - npc collision
	void checkHeroMapObjectsCollision(GameObject* hero, std::vector <GameObject*> &mapGOs);		//checks hero - map objects collision
	void checkHeroRectangleCollision(GameObject* hero, std::vector <GameObject*> &mCOs);		//checks hero - rectangles collision
	void checkHeroDoorCollision(GameObject* hero, std::vector <GameObject*> &mDOs);		//checks hero - rectangles collision
		
	void checkFighterCollision(GameObject* go, GameObject* go1);		//fighter collision
};
