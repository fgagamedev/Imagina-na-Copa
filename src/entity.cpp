#include "entity.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

using namespace std;

Entity::Entity()
{
	caio = new Caio();
	mira = new Mira();
	enemies = new Enemies();
}

Entity::~Entity()
{
	// Nothing yet
}

void 
Entity::init()
{
	caio->init();
	mira->init();
	enemies->init();
}

void 
Entity::draw()
{
	caio->draw();
	mira->draw();
	enemies->draw();
}

void 
Entity::update()
{
	// Nothing yet
}

void 
Entity::release()
{
	caio->release();
	mira->release();
	enemies->release();
}