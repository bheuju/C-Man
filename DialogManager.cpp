#include "DialogManager.h"
#include "Game.h"

DialogManager* DialogManager::pInstance = 0;

void DialogManager::init(std::string fontName, int size)
{
	font = TTF_OpenFont(fontName.c_str(), size);
	tex1 = IMG_LoadTexture(Game::Instance()->getRenderer(), "assets/black.png");
}

void DialogManager::load(std::string text)
{
	SDL_Color color = {255, 255, 255};

	surf = TTF_RenderText_Blended_Wrapped(font, text.c_str(), color, 500);
	
	tex = SDL_CreateTextureFromSurface(Game::Instance()->getRenderer(), surf);
	
	SDL_FreeSurface(surf);
}

void DialogManager::draw()
{
	SDL_Renderer* ren = Game::Instance()->getRenderer();
	SDL_Rect srcRect;
	SDL_Rect destRect;
	SDL_Rect rectBlack;
	
	SDL_QueryTexture(tex, 0, 0, &srcRect.w, &srcRect.h);

	destRect.w = srcRect.w;
	destRect.h = srcRect.h;

	destRect.x = 80;
	destRect.y = 350;

	rectBlack.x = destRect.x - 10;
	rectBlack.y = destRect.y - 10;
	rectBlack.w = destRect.w + 20;
	rectBlack.h = destRect.h + 20;

	SDL_SetTextureAlphaMod(tex1, 175);
	SDL_RenderCopy(ren, tex1, 0, &rectBlack);
	SDL_RenderCopy(ren, tex, 0, &destRect);
}

void DialogManager::clean()
{
	TTF_CloseFont(font);
}
