#include "secondplane.h"
#include "imageload.h"
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

SecondPlane::SecondPlane()
{
	position.x = 60;
	position.y = 150;
	position.w = 120;
	position.h = 120;

    imageLoad = ImageLoad::getInstance();
}

SecondPlane::~SecondPlane()
{
	// Nothing yet
}

void
SecondPlane::init()
{
	m_texture = imageLoad->loadImg("res/images/sun.png");
}

void
SecondPlane::draw()
{
	imageLoad->update(m_texture, &position);
	//imageLoad->release(m_texture);
}

void
SecondPlane::release()
{
	SDL_DestroyTexture(m_texture);
}
