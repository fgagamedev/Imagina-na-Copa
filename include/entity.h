#ifndef ENTITY_H
#define ENTITY_H

#include "caio.h"
#include "mira.h"
#include "enemies.h"

class Entity
{
public:
	Entity();
	~Entity();
	void init();
	void draw();
	void update();
	void release();
private:
	Caio* caio;
	Enemies* enemies;
	Mira* mira;

};

#endif // ENTITY_H