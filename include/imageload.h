#ifndef IMAGELOAD_H
#define IMAGELOAD_H

#include <SDL2/SDL.h>
#include <string>

using namespace std;

class ImageLoad
{
public:
	static ImageLoad* getInstance();
	static void releaseInstance();

	void setRenderer(SDL_Renderer* renderer);

	SDL_Texture* loadImg(const string& path);
	void release(SDL_Texture* texture);
	void update(SDL_Texture* texture, SDL_Rect* destRect);

private:
	ImageLoad();
	SDL_Renderer* m_renderer;

};

#endif // IMAGELOAD_H