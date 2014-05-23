#ifndef HP_H
#define HP_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Hp
{
public:
	Hp();
	~Hp();
	void init();
	void draw();
	void release();
private:
	SDL_Texture* m_texture;

};

#endif // HP_H