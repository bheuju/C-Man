/* =================== Dialog Manager ================== 
Manages dialogs for all characters
-------------------------------------------------------- 

======================================================== */

#pragma once
#include <iostream>
#include <map>
#include <string>
#include "SDL_ttf.h"

class DialogManager
{
public:
	static DialogManager* Instance()
	{
		if (pInstance == 0)
		{
			pInstance = new DialogManager;
			return pInstance;
		}
		return pInstance;
	}

	void init(std::string fontName, int size);
	void load(std::string text);
	void draw();
	void clean();

private:
	static DialogManager* pInstance;

	DialogManager(){}

	SDL_Surface* surf;
	SDL_Texture* tex;
	SDL_Texture* tex1;

	TTF_Font* font;
};

