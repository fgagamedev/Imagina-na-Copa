#include "enemies.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

using namespace std;

Enemies::Enemies()
{
	position.x = 700;
	position.y = 350;
	position.w = 50;
	position.h = 100;

    imageLoad = imageLoad->getInstance();
}

Enemies::~Enemies()
{
	// Nothing yet
}

void 
Enemies::init()
{
	m_texture = imageLoad->loadImg("res/images/curupira.png");
}

void 
Enemies::draw()
{
    imageLoad->update(m_texture, &position);
}

void 
Enemies::release()
{
	SDL_DestroyTexture(m_texture);
}