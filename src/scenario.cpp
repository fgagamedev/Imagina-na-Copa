#include "scenario.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

using namespace std;

Scenario::Scenario()
{
	try
	{
		background = new Background();
		secondplane = new SecondPlane();
		platform = new Platform();
	}
	catch (const string& e)
	{
		delete platform;
		delete secondplane;
		delete background;

		throw e;
	}
}

Scenario::~Scenario()
{
	delete platform;
	delete secondplane;
	delete background;
}

void 
Scenario::init()
{
	background->init();
	secondplane->init();
	platform->init();
}

void 
Scenario::draw()
{
	background->draw();
	secondplane->draw();
	platform->draw();
}

void 
Scenario::update()
{
	// Nothing yet
}

void 
Scenario::release()
{
	platform->release();
	secondplane->release();
	background->release();
}