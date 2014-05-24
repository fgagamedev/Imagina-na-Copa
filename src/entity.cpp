#include "entity.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

using namespace std;

Entity::Entity()
{
	try 
	{
		caio = new Caio();
		aim = new Aim();
		enemy = new Enemy();
	}
	catch (const string& e)
	{
		delete enemy;
		delete aim;
		delete caio;

		throw e;	
	}

}

Entity::~Entity()
{
	delete enemy;
	delete aim;
	delete caio;
}

void 
Entity::init()
{
	caio->init();
	aim->init();
	enemy->init();
}

void 
Entity::draw()
{
	caio->draw();
	aim->draw();
	enemy->draw();
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
	aim->release();
	enemy->release();
}