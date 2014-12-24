/* ==================== Game Object ===================== 
This is an abstract base class for all kinds of objects  
-------------------------------------------------------- 
Other classes that will inherit from this class will act 
as base class for other objects. The purpose of making  
abstract base class is to force the derived classes to   
define the functions. 
======================================================== */

#pragma once
#include "LoaderParams.h"
#include "Vector2D.h"

class GameObject
{
public:
	GameObject(){}
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;

	virtual void collision(bool talkable = false){};
	virtual void doorCollision(){};
	virtual void collision(int row){};
	virtual bool isColliding(){return false;}
	virtual bool canTalk(){return false;}
	virtual int getNpcID() {return 0;}
	virtual void setTalking(bool talking){}
	virtual int getCollisionDirn(){return 0;}

	Vector2D* getPosition()
	{
		return &mPosition;
	}

	Vector2D* getOrgPosition()
	{
		return &orgPosition;
	}

	int getWidth()
	{
		return mWidth;
	}

	int getHeight()
	{
		return mHeight;
	}

	std::string getID()
	{
		return mTexID;
	}
protected:
	GameObject(const LoaderParams* pParam){}
	virtual ~GameObject(){}

	Vector2D mPosition;
	Vector2D mVelocity;
	Vector2D orgPosition;

	int mWidth, mHeight;
	int mRow, mFrame;
	std::string mTexID;
};


