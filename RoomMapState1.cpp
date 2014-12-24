#include "RoomMapState1.h"
#include "TexManager.h"
#include "MapGameObject.h"
#include "InputHandler.h"
#include "HeroCharacter.h"
#include "NPCCharacter.h"
#include "Rectangle.h"
#include "Camera.h"
#include "Vector2D.h"

const std::string RoomMapState1::roomMapID = "ROOM1";

void RoomMapState1::update()
{
	handleDialog();
	hero->update();
	cm.checkHeroRectangleCollision(hero, mCOs);			//checks collision between hero and rectangles
	cm.checkHeroDoorCollision(hero, mDOs);				//checks collision between hero and door rectangles
	npcID = cm.checkHeroNPCCollision(hero, npcGOs);
}

void RoomMapState1::render()
{
	//Rendering Background Map
	if (cm.checkCameraObjectCollision(layer0))			//check the portion of layer0 to be rendered
	{
		layer0->draw();
	}
	hero->draw();
	for(int i = 0; i < npcGOs.size(); i++)
	{
		npcGOs[i]->draw();
	}
	//for (int i = 0; i < mCOs.size(); i++)
	//{
	//	if (cm.checkCameraObjectCollision(mCOs[i]))	//check the collision rectangles to be rendered
	//	{
	//		mCOs[i]->draw();
	//	}
	//}
	//for (int i = 0; i < mDOs.size(); i++)
	//{
	//	if (cm.checkCameraObjectCollision(mDOs[i]))	//check the door rectangles to be rendered
	//	{
	//		mDOs[i]->draw();
	//	}
	//}
}

bool RoomMapState1::onEnter()
{
	TexManager::Instance()->load("assets/room1.png", "room1");
	//TexManager::Instance()->load("assets/room1.png", "room1");

	layer0 = new MapGameObject(new LoaderParams("room1", 0, 0, 1920, 1440, 0, 0));
	hero = new HeroCharacter(new LoaderParams("boy", 955, 890, 41, 36, 2, 1));
	npcGOs.push_back(new NPCCharacter(new LoaderParams("npc", 955, 800, 41, 36, 0, 0), 5));

	//Parsing and Loading collision rectangles from file
	coMaps.parseRectangles("maps/room1Rectangles.xml");
	mCOs = coMaps.getCOs();
	mDOs.push_back(new Rectangle(942, 950, 68, 14, "rd1"));


	std::cout<<"Room 1 Entered"<<std::endl;
	return true;
}

bool RoomMapState1::onExit()
{
	TexManager::Instance()->clearFromTextureMap("room1");
	InputHandler::Instance()->resetMouseButtons();

	mCOs.clear();
	mDOs.clear();

	std::cout<<target->getX()<<" "<<target->getY()<<std::endl;

	Camera::Instance()->setTarget(target);		//on exiting pausestate refocus the camera to HERO, target is assigned from passed value
	return true;
}
