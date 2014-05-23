#include "dialogue.h"
#include "imageload.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

using namespace std;

Dialogue::Dialogue()
{
	// Nothing yet
}

Dialogue::~Dialogue()
{
	// Nothing yet
}

void 
Dialogue::init()
{
    ImageLoad* imageLoad = ImageLoad::getInstance();
	m_texture = imageLoad->loadImg("res/images/dialogue.png");
}

void 
Dialogue::draw()
{

}

void 
Dialogue::release()
{

}