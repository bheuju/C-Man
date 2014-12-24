#pragma once
#include "Fighter.h"
#include "HeroFighter.h"
#include "Resource.h"

class VillainFighter : public Fighter
{
public:
	VillainFighter(const LoaderParams* pParams);
	
	virtual void draw();
	virtual void update();
	virtual void clean();

	void handleInput();
	void collision(bool talk);

private:
	bool CollideVar;
	bool moveLeft;
	void AIvillain();
	static bool check;
	bool animateDefeat;

	void init();

	void AnimateOnEnteringCombat();
	void AnimateOnDefeat();

	void AnimateLeft();
	void AnimateRight();

	void AnimateA();
	void AnimateS();
	void AnimateD();
	
};

