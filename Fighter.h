#pragma once
#include "GameObject.h"
#include "LoaderParams.h"
#include "TexManager.h"

class Fighter : public GameObject
{
public:

	Fighter (const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();

	bool doAnimate(int num, int move[]);

protected:
	SDL_RendererFlip flip;

	static bool InputVar;
	static bool moveleft_hero;

	bool mCollision;
	static int heroHP, villianHP;
	static int heroDMG, villianDMG;
	static bool inputHandle;

	int srcX, srcY;
	int wAnimate[30];
	int wSoftPunch[20];
	int wRun[20];
	int wDefeat[20];
	int wSoftKick[20];
	int wHardPunch[20];
	int wJump[20];

	bool startAnimate;
	bool animate;
	bool returnDefault;
	bool animA;
	bool animS;
	bool animD;
	bool animLeft;
	bool animRight;
};