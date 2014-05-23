#ifndef SEBASTIAO_H
#define SEBASTIAO_H

#include <SDL2/SDL.h>

class Sebastiao
{
public:
	Sebastiao();
	~Sebastiao();
	void init();
	void draw();
	void release();
private:
	SDL_Texture* m_texture;
	

};

#endif // SEBASTIAO_H