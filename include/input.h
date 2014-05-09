#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
#include "keyboard.h"

class Input
{
public:
	Input(bool* quit);
	~Input();
	void eventLoop();
private:
	Keyboard *m_keyboard;
	bool m_quit;
};

#endif // INPUT_H
