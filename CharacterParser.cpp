#include "CharacterParser.h"
#include "NPCCharacter.h"

bool CharacterParser::parseCharacters(const char* filename)
{
	TiXmlDocument doc;				//create xml document
	if (!doc.LoadFile(filename))	//load character file
	{
		std::cerr<<doc.ErrorDesc()<<std::endl;
		return false;
	}
	std::cout<<"Character XML Load Successful"<<std::endl;

	int x, y, w, h;
	int id;
	
	std::string mapID;		//used during loading - to map filename to map
	//std::string file;

	TiXmlElement* pRoot = doc.RootElement();	//get root element (maps)

	TiXmlElement* pNPCRoot = 0;					//declare npcs root node (npcs)

	for (TiXmlElement* t = pRoot->FirstChildElement(); t != NULL; t = t->NextSiblingElement())
	{
		pNPCRoot = t;

		//file = pNPCRoot->Attribute("filename");
		mapID = pNPCRoot->Attribute("mapID");

		for (TiXmlElement* e = pNPCRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
		{
			e->Attribute("id", &id);
			e->Attribute("x", &x);
			e->Attribute("y", &y);
			e->Attribute("w", &w);
			e->Attribute("h", &h);

			//std::cout<<filename<<" "<<id<<" "<<x<<" "<<y<<" "<<w<<" "<<h<<std::endl;

			npcGOs.push_back(new NPCCharacter(new LoaderParams(mapID, x, y, w, h, 0, 1), id));

			//need to use multimap to map one-to-many for (filename - npcGOs)
			//this is so that different image is shown for different npcs
			//not needed now.. cause loading is done manually in playstate->onEnter()
		}
	}

	return true;
}

