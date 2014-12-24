#include "TexManager.h"
#include "Camera.h"

TexManager* TexManager::pInstance = 0;

void TexManager::load(std::string fileName, std::string id)
{
	SDL_Renderer* ren = Game::Instance()->getRenderer();
	tex = IMG_LoadTexture(ren, fileName.c_str());
	texMap[id] = tex;
}

void TexManager::draw(std::string id, int x, int y, int width, int height, int mRow, int  mFrame, SDL_RendererFlip flip)
{
	SDL_Renderer* ren = Game::Instance()->getRenderer();
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = width * mFrame;
	srcRect.y = height * mRow;

	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;

	Vector2D pos = Camera::Instance()->getPosition();

	destRect.x = x - pos.getX();		//(x, y) is object's world coordinate
	destRect.y = y - pos.getY();		//pos () is camera's world coordinate
										//destRect () is object's camera coordinate

	//destRect.x = 300 + pos.getX();
	//destRect.y = 220 + pos.getY();

	SDL_RenderCopyEx(ren, texMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TexManager::drawMap(std::string id, int x, int y, int width, int height, int mRow, int  mFrame, SDL_RendererFlip flip)
{
	SDL_Renderer* ren = Game::Instance()->getRenderer();
	SDL_Rect srcRect;
	SDL_Rect destRect;

	//srcRect.x = 640 * mFrame;
	//srcRect.y = 480 * mRow;

	Vector2D pos = Camera::Instance()->getPosition();

	srcRect.x = pos.getX();
	srcRect.y = pos.getY();

	destRect.x = 0;
	destRect.y = 0;

	//destRect.x = pos.getX();
	//destRect.y = pos.getY();

	srcRect.w = 640;
	srcRect.h = 480;

	destRect.w = 640;
	destRect.h = 480;

	SDL_RenderCopyEx(ren, texMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TexManager::drawInWin(std::string id, int x, int y, int width, int height, int mRow, int  mFrame, SDL_RendererFlip flip)
{
	SDL_Renderer* ren = Game::Instance()->getRenderer();
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = width * mFrame;
	srcRect.y = height * mRow;

	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;

	Vector2D pos = Camera::Instance()->getPosition();

	destRect.x = x - pos.getX();		//(x, y) is object's world coordinate
	destRect.y = y - pos.getY();		//pos () is camera's world coordinate
										//destRect () is object's camera coordinate

	SDL_RenderCopyEx(ren, texMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TexManager::drawFighter(std::string id, int x, int y, int srcX, int srcY, int width, int height, SDL_RendererFlip flip)
{
	SDL_Renderer* ren = Game::Instance()->getRenderer();
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = srcX;
	srcRect.y = height * srcY;

	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;

	Vector2D pos = Camera::Instance()->getPosition();

	destRect.x = x - pos.getX();		//(x, y) is object's world coordinate
	destRect.y = y - pos.getY();		//pos () is camera's world coordinate
										//destRect () is object's camera coordinate

	SDL_RenderCopyEx(ren, texMap[id], &srcRect, &destRect, 0, 0, flip);
}
