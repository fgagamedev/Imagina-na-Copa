#include "platform.h"
#include "imageload.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

using namespace std;

Platform::Platform()
{
	position.x = 0;
	position.y = 450;
	position.w = 800;
	position.h = 150;

    imageLoad = imageLoad->getInstance();
}

Platform::~Platform()
{
	// Nothing yet
}

void 
Platform::init()
{
	m_texture = imageLoad->loadImg("res/images/platform.png");
	//imageLoad->release(m_texture);
}

void 
Platform::draw()
{
    imageLoad->update(m_texture, &position);
}

void 
Platform::release()
{
	SDL_DestroyTexture(m_texture);
}