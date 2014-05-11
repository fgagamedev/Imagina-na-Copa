#ifndef FADE_H
#define FADE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "inputhandler.h"
#include "resource.h"
#include "window.h"

using namespace std;

class Fade : public InputHandler
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
	Uint8 alpha;
	bool m_escape;
};

#endif // FADE_H
