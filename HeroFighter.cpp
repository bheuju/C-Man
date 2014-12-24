#include"HeroFighter.h"
#include "InputHandler.h"
#include "CombatState.h"
#include "GameObject.h"

//static bool moveRight = true;

HeroFighter::HeroFighter(const LoaderParams* pParams) : Fighter(pParams)
{
	//flip = SDL_FLIP_NONE;
	mCollision = false;
	moveRight = true;
	init();		//initialize arrays
	mWidth = wAnimate[0];
	srcX = 0;
	srcY = mHeight;
	animate = true;
	animA = animS = animD = false;
	animateDefeat = false;
	inputHandle = false;
	returnDefault = false;
	startAnimate = false;
	Jump = false;
}

void HeroFighter::init()
{
	int fAnimate[] = {41, 41, 41, 43, 46, 46, 46, 46, 46, 46, 43, 41, 41, 41, 65, 52, 52,82,87,87,88,51,46,46,58,72,80};
	int fSoftPunch[] = {66, 75, 93, 94, 82};
	int fRun[] = {74, 86, 89, 87, 66, 53, 86, 87, 85, 67, 51, 74};
	int fDefeat[] = {64, 57, 63, 61, 61, 62, 63, 94, 111, 138};
	int fSoftKick[] = {66,54,93,54,66};
	int fHardPunch[] = {66,71,71,115,113,97,71,66};
	int fJump[]={74,46,50,61,69,61,50,46,74};

	for (int i = 0; i < 27; i++)
	{
		wAnimate[i] = fAnimate[i];
	}
	for (int i = 0; i < 5; i++)
	{
		wSoftPunch[i] = fSoftPunch[i];
	}
	for (int i = 0; i < 12; i++)
	{
		wRun[i] = fRun[i];
	}
	for (int i = 0; i < 10; i++)
	{
		wDefeat[i] = fDefeat[i];
	}

	for (int i = 0; i < 5; i++)
	{
		wSoftKick[i] = fSoftKick[i];
	}

	for (int i = 0; i < 8; i++)
	{
		wHardPunch[i] = fHardPunch[i];
	}
	for (int i = 0; i < 9; i++)
	{
		wJump[i] = fJump[i];
	}

}

void HeroFighter::draw()
{
	TexManager::Instance()->drawFighter("fighter1", mPosition.getX(), mPosition.getY(), srcX, srcY, mWidth, mHeight, flip);
}

void HeroFighter::update()
{
	//std::cout << "I am here" << std::endl;
	mVelocity.setX(0);		//Set these value to determine what to do when
	//mVelocity.setY(0);		//no key is pressed. i.e, default settings

	std::cout<<"Villian: "<<villianHP<<std::endl;

	//This sets the hero to default idle position
	if (returnDefault)
	{
		srcX = 0;			
		srcY = 1;
		mWidth = 66;
		mHeight = 140;
	}

	InputVar = false;

	if (animate) AnimateOnEnteringCombat();
	if (animateDefeat) AnimateOnDefeat();

	if (animA) AnimateA();
	if (animS) AnimateS();
	if (animD) AnimateD();

	if (inputHandle) handleInput();

	Fighter::update();
	mCollision = false;
}

void HeroFighter::collision(bool talk)
{
	//mVelocity.setX(0);
	//moveRight = false;
	//CollideVar = true;
	mCollision = true;

	std::cout<<"Hero HP: "<<heroHP<<std::endl;

	if (heroHP < 0)
	{
		animateDefeat = true;
		heroHP = 1000;
	}

	std::cout << "Collide var is true" << std::endl;
	std::cout<<"Fighter collision\n";
}

void HeroFighter::handleInput()
{
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))	//soft punch
	{
		animA = true;
		if (mCollision)
		{
			Fighter::villianDMG = 10;
		}
		returnDefault = true;
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_S))	//soft kick
	{
		animS = true;
		if (mCollision)
		{
			Fighter::villianDMG = 10;
		}
		returnDefault = true;
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_D))	//hard punch
	{
		animD = true;
		if (mCollision)
		{
			Fighter::villianDMG = 20;
		}
		returnDefault = true;
	}
	//if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_F))
	//{
	//	AnimateF();
	//	returnDefault = true;
	//}

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		AnimateLeft();
		returnDefault = true;
	}
	else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		AnimateRight();
		returnDefault = true;
	}
}

//Attacks Input
void HeroFighter::AnimateA()	//soft punch
{
	srcY = 1;
	animA = doAnimate(5, wSoftPunch);

	InputVar = true;
}
void HeroFighter::AnimateS()	//soft kick
{
	srcY = 5;
	animS = doAnimate(5, wSoftKick);
}
void HeroFighter::AnimateD()	//hard punch
{
	srcY = 6;
	animD = doAnimate(8, wHardPunch);
}
void HeroFighter::AnimateF()
{

}

//Movement Input
void HeroFighter::AnimateLeft()
{
	moveRight = true;
	moveleft_hero = true;

	{
		int n;
		n = (int) (SDL_GetTicks() / 100) % 12;

		srcX = 0;
		srcY = 2;
		for (int i = 0; i < n; i++)
		{
			srcX += wRun[i];
		}
		//for (int i = 0; i < 2; i++)
		//{
		//	srcY += hAll[i];
		//}
		mWidth = wRun[n];
	}

	mVelocity.setX(-2);

	if (!moveRight)
	{
		mVelocity.setX(0);
	}
}
void HeroFighter::AnimateRight()
{
	moveleft_hero = 0;

	{
		int n;
		n = (int) (SDL_GetTicks() / 100) % 12;

		srcX = 0;
		srcY = 2;
		for (int i = 0; i < n; i++)
		{
			srcX += wRun[i];
		}
		//for (int i = 0; i < 2; i++)
		//{
		//	srcY += hAll[i];
		//}
		mWidth = wRun[n];
	}

	mVelocity.setX(2);

	if (!moveRight)
	{
		mVelocity.setX(0);
	}

	//std::cout<<"n = "<<n<<" x = "<<srcX<<" w = "<<mWidth<<std::endl;
}
//void HeroFighter::AnimateJump()
//{
//		int n;
//		n = (int) (SDL_GetTicks() / 100) % 9;
//
//		srcX = 0;
//		srcY = 4;
//		for (int i = 0; i < n; i++)
//		{
//			srcX += wJump[i];
//			mPosition.setY(mPosition.getY()-5);
//		}
//	
//		mWidth = wJump[n];
//		
//}

//Auto Animations
void  HeroFighter::AnimateOnEnteringCombat()
{
	srcX = 0;
	srcY = 0;
	inputHandle = !doAnimate(27, wAnimate);
}
void HeroFighter::AnimateOnDefeat()
{
	srcX = 0;
	srcY = 3;
	if (!doAnimate(10, wDefeat))
	{
		animate = false;
		inputHandle = false;
		animateDefeat = false;
		returnDefault = false;
	}
}

void HeroFighter::clean()
{

}
