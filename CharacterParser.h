#pragma once
#include "GameObject.h"
#include "tinyxml.h"
#include <vector>
#include <string>

class CharacterParser
{
public:
	bool parseCharacters(const char* filename);
	std::vector<GameObject*> getNpcGOs()
	{
		return npcGOs;
	}
private:
	std::vector <GameObject*> npcGOs;

};

