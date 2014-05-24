#include "dialogue.h"
#include "imageload.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

using namespace std;

Dialogue::Dialogue()
{
	position.x = 265;
	position.y = 10;
	position.w = 250;
	position.h = 125;

	isDrawn = false;

    imageLoad = imageLoad->getInstance();
}

Dialogue::~Dialogue()
{
	// Nothing yet
}

void 
Dialogue::init()
{
	m_texture = imageLoad->loadImg("res/images/dialogue.png");
}

void 
Dialogue::draw()
{
if (!isDrawn)
	{
	    imageLoad->update(m_texture, &position);
		
		isDrawn = true;
	}
}

void 
Dialogue::release()
{
	SDL_DestroyTexture(m_texture);
}