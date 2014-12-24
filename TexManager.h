/* ==================== TexManager =======================
 This is an abstract base class for all kinds of objects  
 -------------------------------------------------------- 
 Other classes that will inherit from this class will act 
 as base class for other objects. The purpose of making  
 abstract base class is to force the derived classes to   
 follow this class.
 load() : loads images into memory
 draw() : draw characters (hero, npc) => draws in world map
 drawMap() : draw background map (big map / world map) => draws world map
 drawButton() : draw button => draws in camera position
======================================================== */

#pragma once
#include <iostream>
#include <map>
#include "SDL.h"
#include "SDL_image.h"
#include "Game.h"
#include <string>

class TexManager
{
public:
	static TexManager* Instance()
	{
		if (pInstance == 0)
		{
			pInstance = new TexManager();
		}
		return pInstance;
	}

	void load(std::string fileName, std::string id);
	void draw(std::string id, int x, int y, int width, int height, int mRow = 0, int  mFrame = 0, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawMap(std::string id, int x, int y, int width, int height, int mRow, int  mFrame, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawInWin(std::string id, int x, int y, int width, int height, int mRow, int  mFrame, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFighter(std::string id, int x, int y, int srcX, int srcY, int width, int height, SDL_RendererFlip flip);

	void clearFromTextureMap(std::string id)
	{
		texMap.erase(id);
	}

private:
	TexManager(){}
	static TexManager* pInstance;

	SDL_Texture* tex;
	std::map<std::string, SDL_Texture*> texMap;

};

