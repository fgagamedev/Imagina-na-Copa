#ifndef SECONDPLANE_H
#define SECONDPLANE_H

#include "imageload.h"
#include <SDL2/SDL.h>

class SecondPlane 
{
public:
	SecondPlane();
	~SecondPlane();
	void init();
	void draw();
	void release();
private:
	SDL_Texture* m_texture;
	SDL_Rect position;
	ImageLoad* imageLoad;
};

#endif // SECONDPLANE_H