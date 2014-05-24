#ifndef AIM_H
#define AIM_H

#include <SDL2/SDL.h>
#include "imageload.h"

class Aim
{
public:
	Aim();
	~Aim();
	void init();
	void draw();
	void release();
private:
	SDL_Texture* m_texture;
	SDL_Rect position;
	ImageLoad* imageLoad;

	bool isDrawn;
};

#endif // AIM_H