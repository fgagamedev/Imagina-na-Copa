#ifndef INVENTORY_H
#define INVENTORY_H

#include <SDL2/SDL.h>

class Inventory
{
public:
	Inventory();
	~Inventory();
	void init();
	void draw();
	void release();
private:
	SDL_Texture* m_texture;
};

#endif // INVENTORY_H