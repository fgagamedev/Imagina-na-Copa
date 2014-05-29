#include "entity.h"
#include "curupira.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

using namespace std;

Entity::Entity()
{
	try 
	{
		caio = new Caio();
		aim = new Aim();

		Enemy *enemy = new Curupira(700, 350, 1, 650, 350);
		enemies.push_back(enemy);

		enemy = new Curupira(300, 350, 1, 420, 315);
		enemies.push_back(enemy);
	}
	catch (const string& e)
	{
		delete aim;
		delete caio;

		throw e;	
	}

}

Entity::~Entity()
{
	for (auto it = enemies.begin(); it != enemies.end(); it++)
		delete *it;
	
	delete aim;
	delete caio;
}

void 
Entity::init()
{
	caio->init();
	aim->init();

	for (auto it = enemies.begin(); it != enemies.end(); it++)
		(*it)->init();
}

void 
Entity::draw()
{
	caio->draw();
<<<<<<< Updated upstream
=======
	for (auto it = enemies.begin(); it != enemies.end(); it++)
		(*it)->draw();
>>>>>>> Stashed changes
	aim->draw();
	enemy->draw();
}

void 
Entity::update(Uint32 delta)
{
	if (enemies.size() < 1)
	{
		Enemy *enemy = new Curupira((rand() % 200) + 300, 350, 1, (rand() % 200) + 150, (rand() % 200) + 150);
		enemy->init();
		enemies.push_back(enemy);
	}
 
	caio->update(delta);
<<<<<<< Updated upstream
	aim->update();
=======
	for (auto it = enemies.begin(); it != enemies.end(); it++)
		(*it)->update(delta);
	aim->update();

	aim->overPlayer(caio->getRect());

	auto dead = enemies.end();

	for (auto it = enemies.begin(); it != enemies.end(); it++)
	{
		if (aim->overEnemy((*it)->boundingBox()))
		{
			dead = it;
		}
	}

	if (dead != enemies.end())
	{
		delete *dead;
		enemies.erase(dead);
	}

>>>>>>> Stashed changes
}

void 
Entity::release()
{
	caio->release();
	aim->release();
	for (auto it = enemies.begin(); it != enemies.end(); it++)
		(*it)->release();
}

Caio*
Entity::getCaio() const
{
	return caio;
}

Aim*
Entity::getAim() const
{
	return aim;
}
