#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <SDL2/SDL.h>

class Dialogue
{
public:
	Dialogue();
	~Dialogue();
	void init();
	void draw();
	void release();
private:
	SDL_Texture* m_texture;

};

#endif // DIALOGUE_H