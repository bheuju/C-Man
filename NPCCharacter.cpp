#include "NPCCharacter.h"
#include "InputHandler.h"
#include "Game.h"
#include "HeroCharacter.h"
#include "Resource.h"

//int NPCCharacter::flag = 1;

NPCCharacter::NPCCharacter(const LoaderParams* pParams, int id) : CharacterGameObject(pParams)
{
	npcID = id;
}

void NPCCharacter::draw()
{
	//std::cout<<"NPC Rendered"<<std::endl;
	CharacterGameObject::draw();
}

void NPCCharacter::update()
{
	mVelocity.setX(0);		//Set these value to determine what to do when
	mVelocity.setY(0);		//no key is pressed. i.e, default settings
	//mFrame = 1;			//This sets the hero to default idle position
	//mRow = 1;
	//animateNPC();			//animates NPC: AI of NPC wander around : pass true to make the NPC move

	//handleInput();		//no more needed after making the camera move instead of map.
	CharacterGameObject::update();
}

void NPCCharacter::collision(int row)		//changes dirn the npc is facing - faces towards hero
{
	//std::cout<<row;
	switch (row)
	{
	case 3:			//collide from left
		mRow = 1;	//face right
		break;
	case 1:			//collide from right
		mRow = 3;	//face left
		break;
	case 2:			//collide from up
		mRow = 0;	//face down
		break;
	case 0:			//collide from down
		mRow = 2;	//face up
		break;
	}
}

void NPCCharacter::animateNPC(bool move)		//if move is true NPC wanders around, default false
{
	if (delay(5))
	{
		mRow = rand() % 4;
	}

	//int time = (SDL_GetTicks() / 100) % 5;		//sets delay by number after % (i.e. 5*100 ms)
	//if (time == 0 && flag == 1)
	//{
	//	mRow = rand() % 4;		// 4 after % denotes no of directions to face
	//	flag = 0;
	//}
	//else if (time > 0)
	//{
	//	flag = 1;
	//}

	if (move)
	{
		switch (mRow)
		{
		case 0:	//down
			mVelocity.setY(2);		
			break;					

		case 1:	//right				
			mVelocity.setX(2);		//To Do : Halt NPC after moving some distance
			break;					//	Determine boundary for NPC to move
			//	Collision Detection with NPC
		case 2:	//up				//
			mVelocity.setY(-2);		//
			break;					

		case 3:	//left				
			mVelocity.setX(-2);		
			break;					

		default:
			break;
		}
		mFrame = (int)((SDL_GetTicks() / 200) % 3);
	}

}

//This function is not needed any more.
void NPCCharacter::handleInput()
{
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		//mRow = 3;
		//mFrame = (int)((SDL_GetTicks() / 200) % 3);
		mVelocity.setX(2);			//if this is not added the NPC doesnt move with map, stays in one place, moves with hero
	}
	else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		//mRow = 1;
		//mFrame = (int)((SDL_GetTicks() / 200) % 3);
		mVelocity.setX(-2);
	}
	else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		//mRow = 2;
		//mFrame = (int)((SDL_GetTicks() / 200) % 3);
		mVelocity.setY(2);
	}
	else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		//mRow = 0;
		//mFrame = (int)((SDL_GetTicks() / 200) % 3);
		mVelocity.setY(-2);
	}
}

void NPCCharacter::clean()
{

}
