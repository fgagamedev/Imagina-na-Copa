#ifndef STAGE_H
#define STAGE_H

#include "hud.h"
#include "entity.h"
#include "scenario.h"

class Stage
{
public:
	Stage();
	~Stage();
	void init();
	void draw();
	void update();
	void release();
private:
	Hud* hud;
	Entity* entity;
	Scenario* scenario;
};

#endif // STAGE_H