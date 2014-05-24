#include "sebastiao.h"
#include "imageload.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

using namespace std;

Sebastiao::Sebastiao()
{
	position.x = 535;
	position.y = 10;
	position.w = 250;
	position.h = 125;

	isDrawn = false;

    imageLoad = imageLoad->getInstance();
}

Sebastiao::~Sebastiao()
{
	// Nothing yet
}

void 
Sebastiao::init()
{
	m_texture = imageLoad->loadImg("res/images/sebastiao.png");
}

void 
Sebastiao::draw()
{
	if (!isDrawn)
	{
		imageLoad->update(m_texture, &position);

		isDrawn = true;
	}
}

void 
Sebastiao::release()
{
	SDL_DestroyTexture(m_texture);
}