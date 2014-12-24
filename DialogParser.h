/* =================== Dialog Parser ================== 
 Read and parse dialogs from xml file
 -------------------------------------------------------- 

 ======================================================== */

#pragma once
#include <list>
#include "tinyxml.h"
#include <iostream>
#include <vector>
#include <string>
#include "GameObject.h"

class DialogParser
{
public:
	bool parseCharacters(const char* filename, int npcID);
	std::list<std::string> getDidalog()
	{
		return mDialogs;
	}
private:
	void parseDialog(TiXmlElement* pRoot);
	std::list <std::string> mDialogs;

};
