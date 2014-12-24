#include "VillainFighter.h"
#include "InputHandler.h"
#include "CharacterGameObject.h"

bool VillainFighter::check=false;

VillainFighter::VillainFighter(const LoaderParams* pParams) : Fighter(pParams)
{
	flip = SDL_FLIP_HORIZONTAL;
	mCollision = false;
	moveLeft=true;
	CollideVar = false;
	init();
	srcX = 0;
	srcY = mHeight;
	returnDefault = false;
	startAnimate = false;
	animate = true;
	animateDefeat = false;
	animA = animS = animD = false;
	animLeft = animRight = false;
}

void VillainFighter::init()
{
	int fAnimate[] = {53, 53, 53, 53,53,53,85, 103, 101, 90, 90, 92, 109, 106, 106, 106, 106, 90};
	int fSoftPunch[] = {84,82,109,104,90};
	int fRun[] = {84,84,96,118,98,96,111,102};
	int fDefeat[] = {76,82,84,84,60,60,68,101,121,145};
	int fSoftKick[] = {84,61,48,82,126,134,120,86,68};
	int fHardPunch[] = {74,78,78,75,65,78,101,89,85,87};
	int fJump[] = {84,84,82,82,63,78,94,84,84,84,84};

	for (int i = 0; i < 18; i++)
	{
		wAnimate[i] = fAnimate[i];
	}
	for (int i = 0; i < 5; i++)
	{
		wSoftPunch[i] = fSoftPunch[i];
	}
	for (int i = 0; i < 8; i++)
	{
		wRun[i] = fRun[i];
	}
	for (int i = 0; i < 10; i++)
	{
		wDefeat[i] = fDefeat[i];
	}
	for (int i = 0; i < 9; i++)
	{
		wSoftKick[i] = fSoftKick[i];
	}
	for (int i = 0; i < 10; i++)
	{
		wHardPunch[i] = fHardPunch[i];
	}
	for (int i = 0; i < 11; i++)
	{
		wJump[i] = fJump[i];
	}
}

void VillainFighter::draw()
{
	TexManager::Instance()->drawFighter("fighter2", mPosition.getX(), mPosition.getY(), srcX, srcY, mWidth, mHeight, flip);
}

void VillainFighter::update()
{
	//CollideVar = false;
	mVelocity.setX(0);		//Set these value to determine what to do when
	//mVelocity.setY(0);		//no key is pressed. i.e, default settings

	std::cout<<"Hero: "<<heroHP<<std::endl;

	if (returnDefault)
	{
		srcX = 0;			
		srcY = 1;
		mWidth = 84;
		mHeight = 150;
	}

	if (animate) AnimateOnEnteringCombat();

	if (delay(20) && inputHandle)
	{
		int n = rand() % 5 + 1;
		std::cout<<n<<std::endl;
		switch(n)
		{
		case 1:
			animA = true;
			if (mCollision)
				Fighter::heroDMG = 100;
			break;
		case 2:
			animS = true;
			if (mCollision)
				Fighter::heroDMG = 100;
			break;
		case 3:
			animD = true;	
			if (mCollision)
				Fighter::heroDMG = 500;
			break;
		case 4:
			animLeft = true;
			break;
		case 5:
			animRight = true;
			break;
		}
	}

	if (animA) AnimateA();
	if (animS) AnimateS();
	if (animD) AnimateD();
	if (animLeft) AnimateLeft();

	if (animateDefeat)
	{
		AnimateOnDefeat();
		inputHandle = false;
	}

	//handleInput();
	//mVelocity.setX(0);

	Fighter::update();
	mCollision = false;
	CollideVar = false;
}

void VillainFighter::collision(bool talk)
{
	CollideVar = true;
	mCollision = true;
	moveLeft = false;

	mPosition.setX(mPosition.getX() + 1);

	if (villianHP < 0)
	{
		animateDefeat = true;
		villianHP = 1000;
	}

	std::cout << "Colllided with hero\n";
	//moveLeft = false;
}

void VillainFighter::handleInput()
{
	AIvillain();
	moveLeft=true;
}
void VillainFighter::AIvillain()
{
	if(CollideVar && InputVar)
	{
		check=true;
		std::cout << "Fight now" << std::endl;
		if(delay(3))
		{
			AnimateA();
			returnDefault =true;
		}
		delay(28);
	}
	else
	{
		mRow = 0;
		mFrame = 0;
	}

	if(check && CollideVar)
	{
		/*mRow=0;
		mFrame=1;*/
		AnimateA();
		if(delay(8))
		{
			mRow = 0;
			mFrame = 0;
			delay(28);
		}
	}

	if(moveLeft && moveleft_hero)
	{
		//mRow = 2;
		//mFrame = (int)((SDL_GetTicks() / 200) % 3);
		//mVelocity.setX(-0.7);
		AnimateLeft();
		mVelocity.setX(-0.7);
		returnDefault = true;
	}

	else if(!moveLeft)
	{
		mVelocity.setX(0);
	}

	//std::cout << moveLeft << std::endl;

}


void VillainFighter::AnimateLeft()
{
	srcY = 2;
	animLeft = doAnimate(8, wRun);

	mVelocity.setX(-2);
}
void VillainFighter::AnimateRight()
{
	srcY = 2;
	animRight = doAnimate(8, wRun);

	mVelocity.setX(-1);
}

void  VillainFighter::AnimateOnEnteringCombat()
{
	srcX = 0;
	srcY = 0;
	doAnimate(18, wAnimate);
}
void VillainFighter::AnimateOnDefeat()
{
	srcY = 3;
	if (!doAnimate(10, wDefeat))
	{
		animate = false;
		inputHandle = false;
		animateDefeat = false;
		returnDefault = false;
	}
}

void VillainFighter::AnimateA()		//soft punch
{
	srcY = 1;
	animA = doAnimate(5, wSoftPunch);	
}
void VillainFighter::AnimateS()		//soft kick
{
	srcY = 5;
	animS = doAnimate(9, wSoftKick);
}
void VillainFighter::AnimateD()		//hard punch
{
	srcY = 6;
	animD = doAnimate(10, wHardPunch);
}

void VillainFighter::clean()
{

}