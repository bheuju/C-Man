#include "GameStateMachine.h"


void GameStateMachine::pushState(GameState* pState)
{
	mGS.push_back(pState);
	mGS.back()->onEnter();
}

void GameStateMachine::changeState(GameState* pState)
{
	if (!mGS.empty())
	{
		if (mGS.back()->getStateID() == pState->getStateID())
		{
			return;
		}

		if (mGS.back()->onExit())
		{
			//delete mGS.back();
			mGS.pop_back();
		}
	}
	mGS.push_back(pState);
	mGS.back()->onEnter();
}

void GameStateMachine::popState()
{
	if (!mGS.empty())
	{
		if (mGS.back()->onExit())
		{
			//delete mGS.back();
			mGS.pop_back();
		}
	}
}

void GameStateMachine::update()
{
	if (!mGS.empty())
	{
		std::cout<<typeid(*mGS.back()).name()<<std::endl;
		mGS.back()->update();
	}
}

void GameStateMachine::render()
{
	if (!mGS.empty())
	{
		mGS.back()->render();
	}
}