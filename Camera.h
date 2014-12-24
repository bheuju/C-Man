#pragma once
#include "Vector2D.h"

class Camera
{
public:
	static Camera* Instance()
	{
		if (pInstance == 0)
		{
			pInstance = new Camera;
		}
		return pInstance;
	}

	void setTarget(Vector2D* target);
	Vector2D* getTarget()
	{
		return mTarget;
	}
	const Vector2D getPosition();

	void update(Vector2D velocity);

private:
	Camera();
	static Camera* pInstance;

	Vector2D *mTarget;
	Vector2D mPosition;

};

