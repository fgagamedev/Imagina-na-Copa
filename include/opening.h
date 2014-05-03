#ifndef OPENING_H
#define OPENING_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "window.h"
#include <string>


class Opening{
public:
	Opening(Window* window);
	~Opening();
	SDL_Texture* loadOpeningTexture(std::string path);
	void showOpening();
	void fadein();
	void fadeout();

private:
	Window* m_window;
	SDL_Texture* m_newTexture;
	SDL_Texture* m_openingTexture;
	SDL_Surface* m_loadedSurface;
	SDL_Rect m_srcrectangle;
	SDL_Rect m_destrectangle;
};

#endif // OPENING_H
