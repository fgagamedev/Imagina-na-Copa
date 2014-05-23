#include "mira.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

using namespace std;

Mira::Mira()
{
	position.x = 400;
	position.y = 300;
	position.w = 20;
	position.h = 20;

    imageLoad = imageLoad->getInstance();
}

Mira::~Mira()
{
	// Nothing yet
}

void 
Mira::init()
{
	m_texture = imageLoad->loadImg("res/images/mira.png");
}

void 
Mira::draw()
{
    imageLoad->update(m_texture, &position);
}

void 
Mira::release()
{
	SDL_DestroyTexture(m_texture);
}