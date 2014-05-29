#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>
#include "imageload.h"

class Enemy
{
public:
<<<<<<< Updated upstream
	Enemy();
	~Enemy();
	void init();
	void draw();
	void release();
=======
	Enemy(int x, int y);
	virtual ~Enemy();

	virtual void init();
	virtual void draw();
	virtual void update(Uint32 delta);
	virtual void release();
>>>>>>> Stashed changes
	
	SDL_Rect boundingBox() const;

protected:
	int m_speed;
	int m_dx;
	int m_frame;
	SDL_Rect m_box;
	ImageSprite* m_sprite;

	SDL_Texture* m_texture;
	SDL_Texture* m_texture2;
	SDL_Rect positionCurupira;
	SDL_Rect positionUrubu;
	ImageLoad* imageLoad;

<<<<<<< Updated upstream
	bool isDrawn;
=======

	SDL_Rect m_clips[8];
	int uC[2];
	int dxC[2];
	int dxU[3];
	int speedC;
	int speedU;
>>>>>>> Stashed changes
};

#endif // ENEMY_H
