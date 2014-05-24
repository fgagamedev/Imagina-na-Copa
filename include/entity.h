#ifndef ENTITY_H
#define ENTITY_H

#include "caio.h"
#include "aim.h"
#include "enemy.h"

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
	Enemy* enemy;
	Aim* aim;

};

#endif // ENTITY_H