#include "curupira.h"
#include "systemlogger.h"

#include <sstream>
using namespace std;

Curupira::Curupira(int x, int y, int dx, int max_x, int max_y)
	: Enemy(x, y)
{
	m_speed = 50;
	m_dx = dx;
	m_frame = 0;
	m_sprite = NULL;

	m_box.w = 50;
	m_box.h = 100;

	m_max_x = max_x;
	m_max_y = max_y;
}

void 
Curupira::init()
{
	m_sprite = new ImageSprite();
	int w, h;
	m_sprite->loadFromFile("res/images/s_curupira.png");

	ostringstream os;
}

void 
Curupira::draw()
{
	SDL_Rect clip;
	clip.x = (m_frame % 4) * m_box.w;
	clip.y = (m_frame / 4) * m_box.h;
	clip.w = m_box.w;
	clip.h = m_box.h;

	SDL_Rect position;
	position.x = m_box.x;
	position.y = m_box.y;
	position.w = m_box.w;
	position.h = m_box.h;

	imageLoad->update(m_sprite->m_texture, &clip, &position);
}

void 
Curupira::update(Uint32 delta)
{	
	if (delta < 100)
	{
		m_box.x += round(((m_speed*delta)/1000.0)*m_dx);

		if (m_box.x >= m_max_x)
			m_dx = -1;
		if (m_box.x <= m_max_y)
			m_dx = 1;
	}

	delta = 0;
}

void 
Curupira::release()
{

}

