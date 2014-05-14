#ifndef CAIO_H
#define CAIO_H

#include <SDL2/SDL.h>
#include "window.h"
#include "inputhandler.h"
#include "movehandler.h"

class Caio : public InputHandler
{
public:
	Caio();
	~Caio();
	void move();
	void draw(SDL_Renderer* renderer);
	void show();

	bool handle(SDL_Event &event);

private:
	bool exitstate[2];
	bool* m_quit;
	int pos[4];
	int rgba[4];
	int speed;
	int dx;
};

#endif // CAIO_H
