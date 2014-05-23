#ifndef CAIO_H
#define CAIO_H

#include <SDL2/SDL.h>
#include "imageload.h"

class Caio
{
public:
	Caio();
	~Caio();
	void init();
	void draw();
	void release();
private:
	SDL_Texture* m_texture;
	SDL_Rect position;
	ImageLoad* imageLoad;
};

#endif // CAIO_H