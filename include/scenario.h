#ifndef SCENARIO_H
#define SCENARIO_H

#include "background.h"
#include "platform.h"
#include "secondplane.h"

class Scenario
{
public:
	Scenario();
	~Scenario();
	void init();
	void draw();
	void update();
	void release();
private:
	Background* background;
	Platform* platform;
	SecondPlane* secondplane;
};

#endif // SCENARIO_H