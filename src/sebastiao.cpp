#include "sebastiao.h"
#include "imageload.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

using namespace std;

Sebastiao::Sebastiao()
{
	// Nothing yet
}

Sebastiao::~Sebastiao()
{
	// Nothing yet
}

void 
Sebastiao::init()
{
    ImageLoad* imageLoad = ImageLoad::getInstance();
	m_texture = imageLoad->loadImg("res/images/sebastiao.png");
}

void 
Sebastiao::draw()
{

}

void 
Sebastiao::release()
{

}