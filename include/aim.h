#ifndef AIM_H
#define AIM_H

#include <SDL2/SDL.h>
#include "imageload.h"
#include "imagesprite.h"
#include "inputhandler.h"
#include "caio.h"

class Aim : public InputHandler
{
public:
	Aim();
	~Aim();

	void init();
	void draw();
	void update();
	void release();

<<<<<<< HEAD
	void overPlayer(SDL_Rect rect);
	bool overEnemy(SDL_Rect rect);

=======
<<<<<<< Updated upstream
=======
	void overPlayer(SDL_Rect rect);
	bool overEnemy(SDL_Rect rect);

>>>>>>> Stashed changes
>>>>>>> c0f3889543340193a9efdf91c019a0e5649ce5d4
	bool handle(SDL_Event& event);
private:
	SDL_Texture* m_texture;
	SDL_Rect m_position;
	SDL_Rect m_clips[3];
	ImageSprite* m_imageSprite;
	ImageLoad* imageLoad;

<<<<<<< HEAD
	int u;
	bool shoot;
=======
<<<<<<< Updated upstream
	bool isDrawn;
=======
	int u;
	bool shoot;
>>>>>>> Stashed changes
>>>>>>> c0f3889543340193a9efdf91c019a0e5649ce5d4
};

#endif // AIM_H
