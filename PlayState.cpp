#include "PlayState.h"
#include "TexManager.h"
#include "HeroCharacter.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "MapGameObject.h"
#include "SoundManager.h"
#include "NPCCharacter.h"
#include "Camera.h"
#include "Resource.h"
#include "RoomMapState1.h"
#include "CombatState.h"

const std::string PlayState::playID = "PLAY";
Vector2D* PlayState::target = 0;

void PlayState::update()
{
	//Will need this concept to focus the map on something else during the gameplay
	//eg: focus camera on villian
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_A) && !npcGOs.empty())	//on pressing A, focuses camera on NPC
	{
		std::cout<<"A";
		Vector2D *pos = npcGOs[2]->getPosition();			//need to set this to position of NPC to focus on it.
		Camera::Instance()->setTarget(pos);
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_S))	//on pressing S, focuses camera on HERO
	{
		std::cout<<"S";
		Vector2D *pos = hero->getPosition();
		Camera::Instance()->setTarget(pos);
	}



	//std::cout<<"x: "<<hero->getPosition()->getX()<<" y: "<<hero->getPosition()->getY()<<std::endl;

	handleDialog();		//Calls the function to display and handle the dialogs

	target = Camera::Instance()->getTarget();		//storing position of current target
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_P))
	{
		Game::Instance()->getStateMachine()->pushState(new PauseState(target));		//target is passed so that on exiting pausestate camera can be refocused on previous target
	}

	//bgMap->update();								//mapObjects have nothing to update
	hero->update();
	for (int i = 0; i < npcGOs.size(); i++)
	{
		npcGOs[i]->update();
	}
	//for (int i = 0; i < mapGOs.size(); i++)
	//{
	//	mapGOs[i]->update();						//mapObjects have nothing to update
	//}

	//cm.checkHeroMapObjectsCollision(hero, mapGOs);	//checks collision between hero and map objects
	npcID = cm.checkHeroNPCCollision(hero, npcGOs);		//checks collision between hero and characters - the returned npcID is the id of npc whom hero collided with
	cm.checkHeroRectangleCollision(hero, mCOs);			//checks collision between hero and rectangles
	cm.checkHeroDoorCollision(hero, mDOs);				//checks collision between hero and door rectangles
}

void PlayState::render()
{
	//Rendering Background Map
	if (cm.checkCameraObjectCollision(layer0))			//check the portion of layer0 to be rendered
	{
		layer0->draw();
	}

	//Rendering NPC Characters
	for (int i = 0; i < npcGOs.size(); i++)
	{
		if (cm.checkCameraObjectCollision(npcGOs[i]))		//check the npc characters to be rendered
		{
			npcGOs[i]->draw();
		}
	}

	if (cm.checkCameraObjectCollision(layer1))			//check the portion of layer1 to be rendered
	{
		layer1->draw();
	}

	//Rendering Hero Character
	hero->draw();		//render this before mapGOs so that hero can be behind objects, i.e. trees, houses

	if (cm.checkCameraObjectCollision(layer2))			//check the portion of layer2 to be rendered
	{
		layer2->draw();
	}


	//std::cout<<npcID;
	//TexManager::Instance()->draw("fnpc3", fGOs[npcID]->getOrgPosition()->getX(), fGOs[npcID]->getOrgPosition()->getY(), fGOs[npcID]->getWidth(), fGOs[npcID]->getHeight(), 0, 0);

	//Rendering mapGameObjects		-- not used at the moment
	//for (int i = 0; i < mapGOs.size(); i++)
	//{
	//	if (cm.checkCameraObjectCollision(mapGOs[i]))	//check the mapGameObjects to be rendered
	//	{
	//		mapGOs[i]->draw();
	//	}
	//}

	//Rendering Collision Rectangles
	//remove this later... no need to render
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

void PlayState::handleDialog()
{
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_Z) && hero->canTalk() && !InputHandler::Instance()->getPressed())		//Displaying Dialog
	{
		if (!secondPress)
		{
			hero->setTalking(true);
			d1 = new DialogParser;
			std::cout<<npcID<<std::endl;
 			d1->parseCharacters("dialogs/dialog.xml", npcID);
			dialog = d1->getDidalog();
			delete d1;

			std::cout<<npcID<<std::endl;

			DialogManager::Instance()->load(*(dialog.begin()));
			dialog.pop_front();

			secondPress = true;
			std::cout<<"Dialog Displayed\n";
		}
		else if (secondPress && !dialog.empty())
		{
			DialogManager::Instance()->load(*(dialog.begin()));		//load dialog every 1000ms
			dialog.pop_front();										//and then delete the dialog from list
			if (dialog.empty() && npcID == 6)
			{
				Game::Instance()->getStateMachine()->pushState(new CombatState);
			}
		}
		InputHandler::Instance()->setPressed(true);
	}

	if (dialog.empty())
	{
		secondPress = false;
		hero->setTalking(false);
	}
}

bool PlayState::onEnter()
{
	TexManager::Instance()->load("assets/boy.png", "boy");
	TexManager::Instance()->load("assets/npc.png", "npc");
	TexManager::Instance()->load("assets/layer0.png", "layer0");
	TexManager::Instance()->load("assets/layer1.png", "layer1");
	TexManager::Instance()->load("assets/layer2.png", "layer2");

	TexManager::Instance()->load("assets/fhero.png", "fhero");
	TexManager::Instance()->load("assets/fnpc1.png", "fnpc1");
	TexManager::Instance()->load("assets/fnpc2.png", "fnpc2");
	TexManager::Instance()->load("assets/fnpc3.png", "fnpc3");
	TexManager::Instance()->load("assets/fnpc4.png", "fnpc4");
	TexManager::Instance()->load("assets/fvillian.png", "fvillian");

	layer0 = new MapGameObject(new LoaderParams("layer0", 0, 0, 1920, 1440, 0, 0));
	layer1 = new MapGameObject(new LoaderParams("layer1", 0, 0, 1920, 1440, 0, 0));
	layer2 = new MapGameObject(new LoaderParams("layer2", 0, 0, 1920, 1440, 0, 0));
	hero = new HeroCharacter(new LoaderParams("boy", 100, 220, 41, 36, 0, 1));

	fGOs.push_back(new NPCCharacter(new LoaderParams("fhero", 0, 239, 101, 111, 0, 0), 0));
	fGOs.push_back(new NPCCharacter(new LoaderParams("fnpc1", 544, 239, 101, 111, 0, 0) ,1));
	fGOs.push_back(new NPCCharacter(new LoaderParams("fnpc1", 543, 239, 101, 111, 0, 0), 2));
	fGOs.push_back(new NPCCharacter(new LoaderParams("fnpc2", 541, 239, 101, 111, 0, 0), 3));
	fGOs.push_back(new NPCCharacter(new LoaderParams("fnpc3", 536, 239, 101, 111, 0, 0), 4));
	fGOs.push_back(new NPCCharacter(new LoaderParams("fnpc4", 536, 239, 101, 111, 0, 0), 5));

	//Parsing and Loading collision rectangles from file
	coMaps.parseRectangles("maps/collisionRectangles.xml");
	mCOs = coMaps.getCOs();
	//Parsing and Loading door rectangles from file
	coDoors.parseRectangles("maps/doorRectangles.xml", true);	//true passed to show that it is door rectangle
	mDOs = coDoors.getCOs();

	//Parsing and Loading NPC Characters from file
	cp.parseCharacters("maps/characters.xml");
	npcGOs = cp.getNpcGOs();

	SoundManager::Instance()->load("assets/bgmusic.ogg", "back", SOUND_MUSIC);
	SoundManager::Instance()->playMusic("back", -1);

	secondPress = false;
	npcID = 0;
	std::cout<<"Entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	for (int i = 0; i < npcGOs.size(); i++)
	{
		npcGOs[i]->clean();		//in clean function need to delete to free memory
	}
	for (int i = 0; i < fGOs.size(); i++)
	{
		fGOs[i]->clean();
	}
	for (int i = 0; i < mCOs.size(); i++)
	{
		mCOs[i]->clean();
	}

	npcGOs.clear();
	fGOs.clear();
	mCOs.clear();

	TexManager::Instance()->clearFromTextureMap("layer0");
	TexManager::Instance()->clearFromTextureMap("layer1");
	TexManager::Instance()->clearFromTextureMap("layer2");
	TexManager::Instance()->clearFromTextureMap("npc");
	TexManager::Instance()->clearFromTextureMap("boy");

	std::cout<<"Exiting PlayState\n";
	return true;
}


