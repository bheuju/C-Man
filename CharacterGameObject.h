/* =============== Character GameObject =================
 This class handles character objects
 (hero, villians, civillians).
 Inherited from GameObject. 
 -------------------------------------------------------- 
 Character objects are the ones that can move.
 Other classes that will inherit from this class will be 
 character objects that are drawn to the screen. 
======================================================== */

#pragma once
#include "GameObject.h"
#include "TexManager.h"
#include <iostream>
#include <string>
#include <map>
#include "Vector2D.h"

class CharacterGameObject : public GameObject
{
public:
	CharacterGameObject (const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();

	void setTalking(bool talking)
	{
		isTalking = talking;
	}

protected:
	bool isTalking;

};

