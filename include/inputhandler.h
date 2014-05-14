#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SDL2/SDL.h>

class InputHandler
{
public:
	virtual ~InputHandler(){}
	virtual bool handle(SDL_Event &event) = 0;
<<<<<<< HEAD
=======

>>>>>>> a1e1f4b7806a829f025ffc432c8f0b81cab8c5cf
};

#endif // INPUTHANDLER_H