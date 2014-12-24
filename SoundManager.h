/* ====================== Sound Manager ====================== 
Sound Manipulation
----------------------------------------------------------- 

============================================================ */

#pragma once
#include <iostream>
#include <map>
#include <string>
#include "SDL_mixer.h"

enum sound_type
{
	SOUND_MUSIC = 0,
	SOUND_SFX = 1
};

class SoundManager
{
public:
	static SoundManager* Instance()
	{
		if (pInstance == 0)
		{
			pInstance = new SoundManager;
			return pInstance;
		}
		return pInstance;
	}

	bool load (std::string fileName, std::string id, sound_type type);

	void playSound(std::string id, int loop);
	void playMusic(std::string id, int loop);


private:
	static SoundManager* pInstance;

	std::map<std::string, Mix_Chunk*> mSFX;
	std::map<std::string, Mix_Music*> mMusic;
	
	SoundManager();
	SoundManager(const SoundManager&);
	SoundManager &operator=(const SoundManager&);
	
	~SoundManager();
};

