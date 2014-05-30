#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <SDL2/SDL.h>
#include "imagesprite.h"

class GameMenu : public ImageSprite
{
public:
	GameMenu();
	~GameMenu();

	void generateClips();
private:
	bool isDrawn;
};

#endif // GAMEMENU_H