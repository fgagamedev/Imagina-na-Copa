#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SDL2/SDL.h>

class InputHandler
{
public:
	virtual ~InputHandler(){}
	virtual bool handle(SDL_Event &event) = 0;
};

#endif // INPUTHANDLER_H