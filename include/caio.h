#ifndef CAIO_H
#define CAIO_H

#include <SDL2/SDL.h>
#include "canvas.h"
#include "window.h"

class Caio
{
public:
	Caio(Window* window);
	~Caio();
	void move();
	void handleEvent();
	void show();
	void drawCaio();

	int* getRGBA();
	int* getPos();

private:
	bool exitstate[2];
	bool* m_quit;
	int pos[4];
	int rgba[4];
	int speed;
	int dx;
	SDL_Event event;
	Window* m_window;
	Canvas* m_canvas;
};

#endif // CAIO_H
