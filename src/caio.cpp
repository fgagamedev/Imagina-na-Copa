#include "caio.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

using namespace std;

Caio::Caio()
{
	position.x = 50;
	position.y = 350;
	position.w = 50;
	position.h = 100;

    imageLoad = imageLoad->getInstance();
}

Caio::~Caio()
{
	// Nothing yet
}

void 
Caio::init()
{
	m_texture = imageLoad->loadImg("res/images/caio.png");
}

void 
Caio::draw()
{
    imageLoad->update(m_texture, &position);
}

void 
Caio::release()
{
	SDL_DestroyTexture(m_texture);
}