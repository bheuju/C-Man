#include "HeroCharacter.h"
#include "InputHandler.h"
#include "Camera.h"

HeroCharacter::HeroCharacter(const LoaderParams* pParams) : CharacterGameObject(pParams)
{
	Camera::Instance()->setTarget(&mPosition);
	//moveDown = moveLeft = moveRight = moveUp = true;
	mCollision = false;
	talk = false;
	isTalking = false;
}

void HeroCharacter::draw()
{
	CharacterGameObject::draw();
}

void HeroCharacter::update()
{
	mVelocity.setX(0);		//Set these value to determine what to do when
	mVelocity.setY(0);		//no key is pressed. i.e, default settings
	mFrame = 1;				//This sets the hero to default idle position

	//std::cout<<mCollision<<std::endl;		//testing collision

	//if (mCollision) { talk = true; }

	if (!isTalking)
	{
		handleInput();			//done before clearing the mCollision
	}
	mCollision = false;		//after setting talk true and handlingInput, mCollision is set to false
	Camera::Instance()->update(mVelocity);
	CharacterGameObject::update();
}

void HeroCharacter::handleInput()
{
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)  && !mCollision)
	{
		mRow = 3;
		mFrame = (int)((SDL_GetTicks() / 200) % 3);
		mVelocity.setX(-2);

		talk = false;
	}
	else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT) && !mCollision)
	{
		mRow = 1;
		mFrame = (int)((SDL_GetTicks() / 200) % 3);
		mVelocity.setX(2);

		talk = false;
	}
	else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP) && !mCollision)
	{
		mRow = 2;
		mFrame = (int)((SDL_GetTicks() / 200) % 3);
		mVelocity.setY(-2);

		talk = false;
	}
	else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN) && !mCollision)
	{
		mRow = 0;
		mFrame = (int)((SDL_GetTicks() / 200) % 3);
		mVelocity.setY(2);

		talk = false;
	}
}

/************************************************
Note on how movement restriction is done:
If collision occurs, set mCollision (true)
mCollision (true) sets the talk (true)
mCollision = false, causes the handleInput() to neglect/restrict the movement for that frame
=> HERO cannon move in any direction for a frame
on next frame, mCollision is set to (false), now accessing the handleInput()
=> HERO can now again move in any direction

EG:	To Do...
*************************************************/

void HeroCharacter::collision(bool talkable)
{
	//Restrict the movement in the direction in which HERO is facing if collision occurs
	switch (mRow)
	{
	case 3:
		std::cout<<"Left Blocked\n";
		mPosition.setX(mPosition.getX() + 1);
		break;
	case 1:
		std::cout<<"Right Blocked\n";
		mPosition.setX(mPosition.getX() - 1);
		break;
	case 2:
		std::cout<<"Up Blocked\n";
		mPosition.setY(mPosition.getY() + 1);
		break;
	case 0:
		std::cout<<"Down Blocked\n";
		mPosition.setY(mPosition.getY() - 1);
		break;
	default:
		break;
	}

	mCollision = true;
	talk = talkable;		//set to true only if collide with npc - passed from collisionManager

	std::cout<<"Collison Detected\n";
}

void HeroCharacter::clean()
{

}

