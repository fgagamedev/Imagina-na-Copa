#ifndef MIRA_H
#define MIRA_H

#include <SDL2/SDL.h>
#include "imageload.h"

class Mira
{
public:
	Mira();
	~Mira();
	void init();
	void draw();
	void release();
private:
	SDL_Texture* m_texture;
	SDL_Rect position;
	ImageLoad* imageLoad;
};

#endif // MIRA_H