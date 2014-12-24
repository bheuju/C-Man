#include "CollisionManager.h"
#include "Camera.h"
#include "Game.h"
#include "RoomMapState1.h"
#include "RoomMapState2.h"

//check camera - objects collision
bool CollisionManager::checkCameraObjectCollision(GameObject* GOs)
{
	SDL_Rect* rect1 = new SDL_Rect;
	Vector2D pos = Camera::Instance()->getPosition();
	rect1->x = pos.getX();
	rect1->y = pos.getY();
	rect1->w = 640;
	rect1->h = 480;

	SDL_Rect* rect2 = new SDL_Rect;
	rect2->x = GOs->getOrgPosition()->getX();
	rect2->y = GOs->getOrgPosition()->getY();
	rect2->w = GOs->getWidth();
	rect2->h = GOs->getHeight();

	//std::cout<<rect2->x<<" "<<rect2->y<<" "<<rect2->w<<" "<<rect2->h<<std::endl;

	if (checkCollision(rect1, rect2))
	{
		delete rect2;
		delete rect1;
		return true;
	}
	delete rect2;
	delete rect1;

	return false;
}

//checks hero - npc collision
int CollisionManager::checkHeroNPCCollision(GameObject* hero, std::vector <GameObject*> &npcGOs)
{
	static int npcID;
	SDL_Rect* rect1 = new SDL_Rect;
	rect1->x = hero->getPosition()->getX();
	rect1->y = hero->getPosition()->getY();
	rect1->w = hero->getWidth();
	rect1->h = hero->getHeight();

	for (int i = 0; i < npcGOs.size(); i++)
	{
		SDL_Rect* rect2 = new SDL_Rect;
		rect2->x = npcGOs[i]->getPosition()->getX();
		rect2->y = npcGOs[i]->getPosition()->getY();
		rect2->w = npcGOs[i]->getWidth();
		rect2->h = npcGOs[i]->getHeight();

 	if (checkCollision(rect1, rect2))
		{
			hero->collision(true);		//true passes so that hero can talk
			npcGOs[i]->collision(hero->getCollisionDirn());		//pass dirn of hero - to make npc face towards hero
			npcID = npcGOs[i]->getNpcID();
		}

		delete rect2;
	}
	delete rect1;

	return npcID;
}

//checks hero - mapobjects collision
void CollisionManager::checkHeroMapObjectsCollision(GameObject* hero, std::vector <GameObject*> &mapGOs)
{
	SDL_Rect* rect1 = new SDL_Rect;
	rect1->x = hero->getPosition()->getX();
	rect1->y = hero->getPosition()->getY();
	rect1->w = hero->getWidth();
	rect1->h = hero->getHeight();

	for (int i = 0; i < mapGOs.size(); i++)
	{
		SDL_Rect* rect2 = new SDL_Rect;
		rect2->x = mapGOs[i]->getPosition()->getX();
		rect2->y = mapGOs[i]->getPosition()->getY();
		rect2->w = mapGOs[i]->getWidth();
		rect2->h = mapGOs[i]->getHeight();

		if (checkCollision(rect1, rect2))
		{
			hero->collision(false);
		}
		delete rect2;
	}
	delete rect1;
}

//checks hero - rectangle collision
void CollisionManager::checkHeroRectangleCollision(GameObject* hero, std::vector <GameObject*> &mCOs)
{
	SDL_Rect* rect1 = new SDL_Rect;
	rect1->x = hero->getPosition()->getX();
	rect1->y = hero->getPosition()->getY();
	rect1->w = hero->getWidth();
	rect1->h = hero->getHeight();

	for (int i = 0; i < mCOs.size(); i++)
	{
		SDL_Rect* rect2 = new SDL_Rect;
		rect2->x = mCOs[i]->getPosition()->getX();
		rect2->y = mCOs[i]->getPosition()->getY();
		rect2->w = mCOs[i]->getWidth();
		rect2->h = mCOs[i]->getHeight();

		//std::cout<<rect2->x<<" "<<rect2->y<<" "<<rect2->w<<" "<<rect2->h<<std::endl;

		if (checkCollision(rect1, rect2))
		{
			hero->collision(false);
		}

		delete rect2;
	}
	delete rect1;
}

//checks hero - rectangle collision
void CollisionManager::checkHeroDoorCollision(GameObject* hero, std::vector <GameObject*> &mDOs)
{
	SDL_Rect* rect1 = new SDL_Rect;
	rect1->x = hero->getPosition()->getX();
	rect1->y = hero->getPosition()->getY();
	rect1->w = hero->getWidth();
	rect1->h = hero->getHeight();

	for (int i = 0; i < mDOs.size(); i++)
	{
		SDL_Rect* rect2 = new SDL_Rect;
		rect2->x = mDOs[i]->getPosition()->getX();
		rect2->y = mDOs[i]->getPosition()->getY();
		rect2->w = mDOs[i]->getWidth();
		rect2->h = mDOs[i]->getHeight();

		//std::cout<<rect2->x<<" "<<rect2->y<<" "<<rect2->w<<" "<<rect2->h<<std::endl;

		if (checkCollision(rect1, rect2))
		{
			Vector2D* target = Camera::Instance()->getTarget();
			if (mDOs[i]->getID() == "hd1")
			{
				Game::Instance()->getStateMachine()->pushState(new RoomMapState1(target, hero));
			}
			else if (mDOs[i]->getID() == "hd2")
			{
				Game::Instance()->getStateMachine()->pushState(new RoomMapState2(target, hero));
			}
			else if (mDOs[i]->getID() == "rd1")
			{
				Game::Instance()->getStateMachine()->popState();
			}

		}
		delete rect2;
	}
	delete rect1;
}

void CollisionManager::checkFighterCollision(GameObject* go, GameObject* go1)
{
	SDL_Rect* rect1 = new SDL_Rect;
	rect1->x = go->getPosition()->getX();
	rect1->y = go->getPosition()->getY();
	rect1->w = go->getWidth();
	rect1->h = go->getHeight();

	SDL_Rect* rect2 = new SDL_Rect;
	rect2->x = go1->getPosition()->getX();
	rect2->y = go1->getPosition()->getY();
	rect2->w = go1->getWidth();
	rect2->h = go1->getHeight();

	if (checkCollision(rect1, rect2))
	{
		go->collision();
		go1->collision();
	}
	delete rect2;

	delete rect1;
}
