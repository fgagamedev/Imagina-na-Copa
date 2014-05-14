#ifndef CAIO_H
#define CAIO_H

#include <SDL2/SDL.h>
#include "window.h"
#include "inputhandler.h"
<<<<<<< HEAD
#include "movehandler.h"
=======
>>>>>>> a1e1f4b7806a829f025ffc432c8f0b81cab8c5cf

class Caio : public InputHandler
{
public:
	Caio();
	~Caio();
	void move();
<<<<<<< HEAD
	void draw(SDL_Renderer* renderer);
=======
>>>>>>> a1e1f4b7806a829f025ffc432c8f0b81cab8c5cf
	void show();

<<<<<<< HEAD
	bool handle(SDL_Event &event);
=======
	int* getRGBA();
	int* getPos();
	bool handle(SDL_Event &event);

>>>>>>> a1e1f4b7806a829f025ffc432c8f0b81cab8c5cf

private:
	bool exitstate[2];
	bool* m_quit;
	int pos[4];
	int rgba[4];
	int speed;
	int dx;
<<<<<<< HEAD
=======
	Window* m_window;
>>>>>>> a1e1f4b7806a829f025ffc432c8f0b81cab8c5cf
};

#endif // CAIO_H
