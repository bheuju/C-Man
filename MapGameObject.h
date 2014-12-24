/* =============== Map GameObject =================
 
 -------------------------------------------------------- 
 
======================================================== */

#pragma once
#include "GameObject.h"
#include "TexManager.h"
#include "Vector2D.h"

#pragma once
class MapGameObject : public GameObject
{
public:
	MapGameObject (const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();

	void handleInput();

protected:
	//int mX, mY;
	//Vector2D mPosition;
	//Vector2D mVelocity;

	//int mWidth, mHeight;
	//int mRow, mFrame;
	//std::string mTexID;
	
	
};

