#include "hp.h"
#include "imageload.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

using namespace std;

Hp::Hp()
{
	// Nothing yet
}

Hp::~Hp()
{
	// Nothing yet
}

void 
Hp::init()
{
    ImageLoad* imageLoad = ImageLoad::getInstance();
	m_texture = imageLoad->loadImg("res/images/hp.png");
}

void 
Hp::draw()
{
	
}

void 
Hp::release()
{
	
}