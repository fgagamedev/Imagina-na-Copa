#ifndef FADE_H
#define FADE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "inputhandler.h"
#include "resource.h"
#include "window.h"
#include "input.h"
#include "inputhandler.h"

using namespace std;

<<<<<<< HEAD
class Fade : public InputHandler 
=======
class Fade : public InputHandler
>>>>>>> a1e1f4b7806a829f025ffc432c8f0b81cab8c5cf
{
public:
	Fade(Window* window);
	~Fade();
	void showImage(struct ISM *m_stack);
	void fadein(struct ISM *m_stack);
	void fadeout(struct ISM *m_stack);
	bool handle(SDL_Event &event);
private:
	Window* m_window;
	Input* m_input;
	Uint8 alpha;
	bool m_escape;
};

#endif // FADE_H
