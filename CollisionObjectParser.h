#pragma once
#include "GameObject.h"
#include "tinyxml.h"
#include <vector>

class CollisionObjectParser
{
public:
	bool parseRectangles(const char* filename, bool chID = false);
	std::vector<GameObject*> getCOs()
	{
		return mCOs;
	}
private:
	//void parseDialog(TiXmlElement* pRoot);
	std::vector <GameObject*> mCOs;



};

