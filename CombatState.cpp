#include "CombatState.h"
#include "HeroFighter.h"
#include "VillainFighter.h"
#include "MapGameObject.h"
#include "Camera.h"

const std::string CombatState::combatID = "COMBAT";

void CombatState::update()
{
	go->update();
	go1->update();
	cm.checkFighterCollision(go, go1);
}

void CombatState::render()
{
	bg->draw();
	go->draw();
	go1->draw();
}

bool CombatState::onEnter()
{
	TexManager::Instance()->load("assets/battlebg.png", "bg");
	TexManager::Instance()->load("assets/herofighter1.png", "fighter1");
	TexManager::Instance()->load("assets/villainfighter.png","fighter2");

	Camera::Instance()->setTarget(new Vector2D(640, 720));

	bg = new MapGameObject(new LoaderParams("bg", 0, 0, 1920, 1440, 0, 0));
	go = new HeroFighter(new LoaderParams("fighter1", 480, 770, 58, 140, 0, 0));
	go1 = new VillainFighter(new LoaderParams("fighter2", 800, 760, 58, 150, 0, 0));

	std::cout<<"Entering Combat State...\n";
	return true;
}

bool CombatState::onExit()
{
	return true;
}
