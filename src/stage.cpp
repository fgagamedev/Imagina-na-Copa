#include "stage.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

using namespace std;

Stage::Stage()
{
	hud = new Hud();
	entity = new Entity();
	scenario = new Scenario();
}

Stage::~Stage()
{
	// Nothing yet
}

void 
Stage::init()
{
	hud->init();
    entity->init();
    scenario->init();
}

void 
Stage::draw()
{
	hud->draw();
    entity->draw();
    scenario->draw();
}

void 
Stage::update()
{
	// Nothing yet
}

void 
Stage::release()
{
	hud->release();
    entity->release();
    scenario->release();
}