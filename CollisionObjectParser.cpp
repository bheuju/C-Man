#include "CollisionObjectParser.h"
#include "Rectangle.h"

bool CollisionObjectParser::parseRectangles(const char* filename, bool chID)
{
	TiXmlDocument doc;				//create xml document
	if (!doc.LoadFile(filename))	//load collisionMap file
	{
		std::cerr<<doc.ErrorDesc()<<std::endl;
		return false;
	}
	std::cout<<"collisionMap XML Load Successful"<<std::endl;

	int x, y, w, h;
	std::string callbackID;

	TiXmlElement* pRoot = doc.RootElement();	//get root element (maps)

	TiXmlElement* pRectRoot = 0;					//declare rects root node (rects)
	pRectRoot = pRoot->FirstChildElement();

	for (TiXmlElement* e = pRectRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		e->Attribute("x", &x);
		e->Attribute("y", &y);
		e->Attribute("w", &w);
		e->Attribute("h", &h);
		if (chID)
		{
			callbackID = e->Attribute("callbackID");
			mCOs.push_back(new Rectangle(x, y, w, h, callbackID));
		}
		else if (!chID)
		{
			mCOs.push_back(new Rectangle(x, y, w, h));
		}

		//std::cout<<x<<" "<<y<<" "<<w<<" "<<h<<std::endl;
		
	}

	return true;
}

