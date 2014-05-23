#ifndef ENEMIES_H
#define ENEMIES_H

#include <SDL2/SDL.h>
#include "imageload.h"

class Enemies
{
public:
	Enemies();
	~Enemies();
	void init();
	void draw();
	void release();
	
private:
	SDL_Texture* m_texture;
	SDL_Rect position;
	ImageLoad* imageLoad;
};

#endif // ENEMIES_H