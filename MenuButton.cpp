#include "MenuButton.h"
#include "TexManager.h"
#include "InputHandler.h"
#include "Camera.h"

MenuButton::MenuButton(const LoaderParams* pParams, void (*callback)()) : GameObject(pParams)
{
	mPosition = Vector2D(pParams->getX(), pParams->getY());
	mWidth = pParams->getWidth();
	mHeight = pParams->getHeight();
	mTexID = pParams->getTexID();
	mRow = pParams->getRow();
	mFrame = MOUSE_OUT;

	mCallback = callback;

	Camera::Instance()->setTarget(&Vector2D(0, 0));
}

void MenuButton::draw()
{
	TexManager::Instance()->drawInWin(mTexID, mPosition.getX(), mPosition.getY(), mWidth, mHeight, mRow, mFrame);
}

void MenuButton::update()
{
	Vector2D* pMousePos = InputHandler::Instance()->getMousePosition();

	if (pMousePos->getX() < (mPosition.getX() + mWidth) &&
		pMousePos->getX() > (mPosition.getX()) &&
		pMousePos->getY() < (mPosition.getY() + mHeight) &&
		pMousePos->getY() > (mPosition.getY()))
	{
		mFrame = MOUSE_OVER;

		if (InputHandler::Instance()->getMouseButtonState(LEFT) && mReleased)
		{
			mFrame = CLICKED;

			mCallback();

			mReleased = false;
		}
	}
	else
	{
		mReleased = true;
		mFrame = MOUSE_OUT;
	}
}

void MenuButton::clean()
{

}
