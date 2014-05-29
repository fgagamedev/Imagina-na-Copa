#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>
#include "imagesprite.h"
#include "imageload.h"

class Enemy
{
public:
<<<<<<< HEAD
=======
<<<<<<< Updated upstream
	Enemy();
	~Enemy();
	void init();
	void draw();
	void release();
=======
>>>>>>> c0f3889543340193a9efdf91c019a0e5649ce5d4
	Enemy(int x, int y);
	virtual ~Enemy();

	virtual void init();
	virtual void draw();
	virtual void update(Uint32 delta);
	virtual void release();
<<<<<<< HEAD
=======
>>>>>>> Stashed changes
>>>>>>> c0f3889543340193a9efdf91c019a0e5649ce5d4
	
	SDL_Rect boundingBox() const;

protected:
	int m_speed;
	int m_dx;
	int m_frame;
	SDL_Rect m_box;
	ImageSprite* m_sprite;

	SDL_Texture* m_texture;
	SDL_Texture* m_texture2;
	SDL_Rect positionCurupira[2];
	SDL_Rect positionUrubu[3];
	ImageLoad* imageLoad;
	ImageSprite* m_imageSpriteUrubu;
	ImageSprite* m_imageSpriteCurupira;


<<<<<<< HEAD
=======
<<<<<<< Updated upstream
	bool isDrawn;
=======

>>>>>>> c0f3889543340193a9efdf91c019a0e5649ce5d4
	SDL_Rect m_clips[8];
	int uC[2];
	int dxC[2];
	int dxU[3];
	int speedC;
	int speedU;
<<<<<<< HEAD
=======
>>>>>>> Stashed changes
>>>>>>> c0f3889543340193a9efdf91c019a0e5649ce5d4
};

#endif // ENEMY_H
