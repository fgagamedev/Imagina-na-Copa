#ifndef STAGE_H
#define STAGE_H

#include "hud.h"
#include "inputhandler.h"
#include "scenario.h"
#include "entity.h"

class Stage
{
public:
	Stage();
	~Stage();

	void init();
	void draw();
	void update(Uint32 delta);

	void release();

	Entity* getEntity() const;

private:
	Hud* hud;
	Entity* entity;
	Scenario* scenario;
};

#endif // STAGE_H