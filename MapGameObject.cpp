#include "MapGameObject.h"
#include "InputHandler.h"

MapGameObject::MapGameObject(const LoaderParams* pParams) : GameObject(pParams)
{
	mPosition = Vector2D(pParams->getX(), pParams->getY());
	orgPosition = mPosition;
	mVelocity = Vector2D(0, 0);
	mWidth = pParams->getWidth();
	mHeight = pParams->getHeight();
	mTexID = pParams->getTexID();
	mRow = pParams->getRow();
	mFrame = pParams->getFrame();
}

void MapGameObject::draw()
{
	TexManager::Instance()->draw(mTexID, mPosition.getX(), mPosition.getY(), mWidth, mHeight, mRow, mFrame);
}

void MapGameObject::update()
{
	//mFrame = (int)((SDL_GetTicks() / 100) % 3);
	//mPosition += mVelocity;
	//mVelocity.setX(0);
	//mVelocity.setY(0);
	//handleInput();
}

void MapGameObject::handleInput()
{
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		mVelocity.setX(2);
	}
	else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		mVelocity.setX(-2);
	}
	else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		mVelocity.setY(2);
	}
	else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		mVelocity.setY(-2);
	}
}

void MapGameObject::clean()
{

}


