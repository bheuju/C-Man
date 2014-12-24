#include "Fighter.h"
//#include "TexManager.h"

bool Fighter::InputVar = false;
bool Fighter::moveleft_hero = false;
bool Fighter::inputHandle = true;
int Fighter::heroHP = 1000;
int Fighter::villianHP = 1000;
int Fighter::heroDMG = 0;
int Fighter::villianDMG = 0;

Fighter::Fighter(const LoaderParams* pParams) : GameObject(pParams)
{
	//mX = pParams->getX();
	//mY = pParams->getY();
	mPosition = Vector2D(pParams->getX(), pParams->getY());
	orgPosition = mPosition;
	mVelocity = Vector2D(0, 0);
	mWidth = pParams->getWidth();
	mHeight = pParams->getHeight();
	mTexID = pParams->getTexID();
	mRow = pParams->getRow();
	mFrame = pParams->getFrame();
	flip = SDL_FLIP_NONE;

}

void Fighter::draw()
{
	TexManager::Instance()->draw(mTexID, mPosition.getX(), mPosition.getY(), mWidth, mHeight, mRow, mFrame, flip);
}

void Fighter::update()
{
	mPosition += mVelocity;
	heroHP-=heroDMG;
	villianHP-=villianDMG;
	heroDMG = 0;
	villianDMG = 0;
}

bool Fighter::doAnimate(int num, int move[])
{
	int n;
	n = (int) (SDL_GetTicks() / 100) % num;
	if (n == 0)
	{
		startAnimate = true;
	}
	if (startAnimate)
	{
		for (int i = 0; i < n; i++)
		{
			srcX += move[i];
		}
		mWidth = move[n];

		//mVelocity.setX(0);

		if (n == num - 1)
		{
			animate = false;
			inputHandle = true;
			returnDefault = true;
			return false;
		}
	}
	return true;
}

void Fighter::clean()
{

}
