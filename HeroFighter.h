#pragma once
#include "Fighter.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "CombatState.h"
#include "VillainFighter.h"

class HeroFighter : public Fighter
{
public:
	HeroFighter(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();

	void handleInput();

	Vector2D* getPosition()
	{
		return &mPosition;
	}

	void collision(bool talk);

private:
	bool moveRight;
	bool animateDefeat;
	bool Jump;

	void init();

	void AnimateA();
	void AnimateS();
	void AnimateD();
	void AnimateF();

	void AnimateLeft();
	void AnimateRight();
	//void AnimateJump();

	void AnimateOnEnteringCombat();
	void AnimateOnDefeat();
};

