#include "DialogParser.h"
#include "DialogManager.h"

bool DialogParser::parseCharacters(const char* filename, int npcID)
{
	TiXmlDocument doc;				//create xml document
	if (!doc.LoadFile(filename))	//load dialog file
	{
		std::cerr<<doc.ErrorDesc()<<std::endl;
		return false;
	}
	std::cout<<"Dialog XML Load Successful"<<std::endl;

	std::string fontname;
	int size;

	int id;

	std::string npcName;
	std::string npcFile;

	TiXmlElement* pRoot = doc.RootElement();		//get root element (characters)
	fontname = pRoot->Attribute("font");			//get attribute font
	pRoot->Attribute("size", &size);				//get attribute size
	DialogManager::Instance()->init(fontname, size);

	TiXmlElement* pNPCRoot = 0;		//declare npcs root node (npc)
	for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		e->Attribute("id", &id);
		if (id == npcID)
		{
			pNPCRoot = e->FirstChildElement();

			npcName = pNPCRoot->Attribute("name");
			npcFile = pNPCRoot->Attribute("file");

			//Need to push back image also... image of character to load during dialog
		}
	}

	parseDialog(pNPCRoot);

	return true;
}

void DialogParser::parseDialog(TiXmlElement* pRoot)
{
	//std::string heroDialog;
	//std::string npcDialog;
	std::string dialog;

	//TiXmlElement* pDialogRoot = 0;
	for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		//if (e->Value() == "hero")
		//{
		//	heroDialog = e->Attribute("dialog");
		//	DialogManager::Instance()->load(heroDialog);
		//}
		//if (e->Value() == "npc")
		//{
		//	npcDialog = e->Attribute("dialog");
		//	DialogManager::Instance()->load(npcDialog);
		//}
		dialog = e->Attribute("dialog");
		mDialogs.push_back(dialog);
		//DialogManager::Instance()->load(dialog);
	}
	mDialogs.push_back("");		//push empty at last to clear the dialog automatically
}

