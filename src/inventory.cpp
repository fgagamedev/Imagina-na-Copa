#include "inventory.h"
#include "imageload.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

using namespace std;

Inventory::Inventory()
{
	// Nothing yet
}

Inventory::~Inventory()
{
	// Nothing yet
}

void 
Inventory::init()
{
    ImageLoad* imageLoad = ImageLoad::getInstance();
	m_texture = imageLoad->loadImg("res/images/inventario.png");

}

void 
Inventory::draw()
{

}

void 
Inventory::release()
{

}