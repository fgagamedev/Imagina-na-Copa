#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SDL2/SDL.h>


class Keyboard{
public:
	Keyboard(bool *quit);

	void eventLoop();
private:
	SDL_Event event;
	bool keystate[2];
	bool *m_quit;
};

#endif // KEYBOARD_H