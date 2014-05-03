#ifndef LOADIMAGES_H
#define LOADIMAGES_H

#include "window.h"
#include "resource.h"
#include <SDL2/SDL.h>
#include <string>

using namespace std;

class LoadImages
{
public:
	LoadImages(Window* window);
	~LoadImages();
	struct ISM* loadTextures(struct ISM *m_stack);
	SDL_Texture* openingTextures(string path);
	
private:
	Window* m_window;

	SDL_Texture* m_tryforceLogo;
	SDL_Texture* m_otherLogo;
	SDL_Texture* m_menu;
	SDL_Texture* m_newTexture;
	SDL_Surface* m_loadedSurface;

	SDL_Rect srcTryforceLogo;
	SDL_Rect destTryforceLogo;
	SDL_Rect srcOtherLogo;
	SDL_Rect destOtherLogo;
	SDL_Rect srcMenu;
	SDL_Rect destMenu;
};


#endif // LOADIMAGES_H