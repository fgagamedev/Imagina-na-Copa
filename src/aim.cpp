#include "aim.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

using namespace std;

Aim::Aim()
{
	position.x = 400;
	position.y = 300;
	position.w = 87;
	position.h = 90;

	isDrawn = false;

    imageLoad = imageLoad->getInstance();
}

Aim::~Aim()
{
	// Nothing yet
}

void 
Aim::init()
{
	m_texture = imageLoad->loadImg("res/images/s_hud.png");
}

void 
Aim::draw()
{
    imageLoad->update(m_texture,NULL,&position);   
}

void 
Aim::update()
{
<<<<<<< Updated upstream
	if(position.x < 0)
        position.x = 0;
	if((position.x + 20) > 800)
        position.x = 780;
=======
	if(m_position.y < 90)
        u = 0;
    else
        u = 2;

    //cout << Caio::getPositionX() << endl;
	//if((m_position.x + 90) > 800)
     //   m_position.x = 710;
}

bool 
Aim::overEnemy(SDL_Rect rect)
{
    if (m_position.x < rect.x && m_position.x > rect.x-45 && m_position.y < rect.y+55 && m_position.y > rect.y-45)
	{
        u = 1;

		return shoot;
	}

	return false;
}

void
Aim::overPlayer(SDL_Rect rect)
{   
    // Caution cursor if it's pointed to Caio   
    if (m_position.x < rect.x && m_position.x > rect.x-45 && m_position.y < rect.y+55 && m_position.y > rect.y-45)
        u = 0;
>>>>>>> Stashed changes
}

void 
Aim::release()
{
	SDL_DestroyTexture(m_texture);
}

bool 
Aim::handle(SDL_Event& event)
{
	bool processed = false;
	shoot = false;
    switch (event.type)
    {
        case SDL_MOUSEMOTION:
<<<<<<< Updated upstream
            position.x = event.motion.x-10;
            position.y = event.motion.y-10;
=======
            m_position.x = event.motion.x;
            m_position.y = event.motion.y;
            processed = true;
        break;

        case SDL_MOUSEBUTTONDOWN:
            //u++;
			shoot = true;
            processed = true;
        break;
>>>>>>> Stashed changes

            isDrawn = false;
            return true;
        break;
        default:
        break;
    }
    return processed;
}
