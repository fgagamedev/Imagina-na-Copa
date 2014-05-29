#ifndef AIM_H
#define AIM_H

#include <SDL2/SDL.h>
#include "imageload.h"
#include "inputhandler.h"

class Aim : public InputHandler
{
public:
	Aim();
	~Aim();

	void init();
	void draw();
	void update();
	void release();

<<<<<<< Updated upstream
=======
	void overPlayer(SDL_Rect rect);
	bool overEnemy(SDL_Rect rect);

>>>>>>> Stashed changes
	bool handle(SDL_Event& event);
private:
	SDL_Texture* m_texture;
	SDL_Rect position;
	ImageLoad* imageLoad;

<<<<<<< Updated upstream
	bool isDrawn;
=======
	int u;
	bool shoot;
>>>>>>> Stashed changes
};

#endif // AIM_H
