#ifndef IMAGESPRITE_H
#define IMAGESPRITE_H

#include <vector>
#include "imageload.h"
#include "camera.h"
#include "collision.h"
#include "configuration.h"
#include "timer.h"

using namespace camera;
using namespace collision;
using namespace configuration;
using namespace std;
using namespace timer;

class ImageSprite
{
public:
	ImageSprite();
	~ImageSprite();
	
	void generatePosition(int x, int y, int w, int h);
	void addClip(int x, int y, int w, int h);

	SDL_Rect getPosition();
	int getWidth();
	int getHeight();

	void init();
	void draw();
	void drawRelative();
	void render();
	void release();
	SDL_Rect position() const;

	SDL_Texture* m_texture;
	ImageLoad* imageLoad;
	vector<SDL_Rect> m_clips;
	string imagePath;

	int m_clipNumber;
	SDL_Rect m_position;

private:
	int m_width;
	int m_height;
	
};

#endif // IMAGESPRITE_H