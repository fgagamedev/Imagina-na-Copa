#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SDL2/SDL.h>

class Keyboard{
public:
	Keyboard(bool *quit);

	void exitEvent();
	SDL_Event getCurrentEvent();
private:
	SDL_Event event;
	bool exitstate[2];
	bool *m_quit;
};

#endif // KEYBOARD_H