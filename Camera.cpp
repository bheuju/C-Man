#include "Camera.h"
#include <iostream>

Camera* Camera::pInstance = 0;

Camera::Camera()
{
	mTarget = new Vector2D(0, 0);
	mPosition = Vector2D(0, 0);
}

void Camera::setTarget(Vector2D* target)
{
	mTarget = target;
}

const Vector2D Camera::getPosition()
{
	if(mTarget != 0)
	{
		Vector2D pos((mTarget->getX() - 320), (mTarget->getY() - 240));		//centres the hero
		
		//std::cout<<pos.getX()<<" "<<pos.getY()<<std::endl;

		//Check to see if map has reached its edges
		if(pos.getX() < 0)
		{
			pos.setX(0);
		}
		if(pos.getY() < 0)
		{
			pos.setY(0);
		}
		if(pos.getX() > 1280)
		{
			pos.setX(1280);
		}
		if(pos.getY() > 960)
		{
			pos.setY(960);
		}

		return pos;
	}

	return mPosition;
}

void Camera::update(Vector2D velocity)
{
	//velocity = Vector2D(2, 2);
	mPosition += velocity;
}
