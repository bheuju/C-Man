#include "CharacterGameObject.h"

CharacterGameObject::CharacterGameObject(const LoaderParams* pParams) : GameObject(pParams)
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

void CharacterGameObject::draw()
{
	TexManager::Instance()->draw(mTexID, mPosition.getX(), mPosition.getY(), mWidth, mHeight, mRow, mFrame);
}

void CharacterGameObject::update()
{
	//mFrame = (int)((SDL_GetTicks() / 100) % 3);
	mPosition += mVelocity;
}

void CharacterGameObject::clean()
{

}
