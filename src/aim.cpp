#include "aim.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

using namespace std;

Aim::Aim()
{
	position.x = 400;
	position.y = 300;
	position.w = 20;
	position.h = 20;

	isDrawn = false;

    imageLoad = imageLoad->getInstance();
}

Aim::~Aim()
{
	// Nothing yet
}

void 
Aim::init()
{
	m_texture = imageLoad->loadImg("res/images/aim.png");
}

void 
Aim::draw()
{
	if (!isDrawn)
	{
    	imageLoad->update(m_texture, &position);

    	isDrawn = true;
    }
}

void 
Aim::release()
{
	SDL_DestroyTexture(m_texture);
}