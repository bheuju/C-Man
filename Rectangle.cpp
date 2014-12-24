#include "Rectangle.h"
#include "Game.h"
#include "Camera.h"

Rectangle::Rectangle(int xx, int yy, int ww, int hh)
{
	mPosition.setX(xx);
	mPosition.setY(yy);
	orgPosition = mPosition;

	mWidth = ww;
	mHeight = hh;

	int x = mPosition.getX();
	int y = mPosition.getY();
	int w = mWidth;
	int h = mHeight;
}

Rectangle::Rectangle(int xx, int yy, int ww, int hh, std::string id)
{
	mPosition.setX(xx);
	mPosition.setY(yy);
	orgPosition = mPosition;

	mTexID = id;

	mWidth = ww;
	mHeight = hh;

	int x = mPosition.getX();
	int y = mPosition.getY();
	int w = mWidth;
	int h = mHeight;
}

void Rectangle::draw()
{
	int x = mPosition.getX();
	int y = mPosition.getY();

	rect1.w = mWidth;
	rect1.h = mHeight;

	Vector2D pos = Camera::Instance()->getPosition();

	rect1.x = x - pos.getX();		//(x, y) is object's world coordinate
	rect1.y = y - pos.getY();		//pos () is camera's world coordinate
	//destRect () is object's camera coordinate

	//std::cout<<"Collision Rectangle Drawn"<<std::endl;
	SDL_RenderDrawRect(Game::Instance()->getRenderer(), &rect1);
}

void Rectangle::update()
{

}

void Rectangle::clean()
{

}



