#ifndef CAIO_H
#define CAIO_H

#include <SDL2/SDL.h>
#include "window.h"
#include "inputhandler.h"

class Caio : public InputHandler
{
public:
	Caio(Window* window);
	~Caio();
	void move();
	void show();
	void drawCaio();

	int* getRGBA();
	int* getPos();
	bool handle(SDL_Event &event);


private:
	bool exitstate[2];
	bool* m_quit;
	int pos[4];
	int rgba[4];
	int speed;
	int dx;
	Window* m_window;
};

#endif // CAIO_H
