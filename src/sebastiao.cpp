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
	int w, h;
	m_texture = imageLoad->loadImg("res/images/sebastiao.png", &w, &h);
}

void 
Sebastiao::draw()
{
	imageLoad->update(m_texture, NULL, &position);
}

void 
Sebastiao::release()
{
	SDL_DestroyTexture(m_texture);
}
