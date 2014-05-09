#include <SDL2/SDL.h>
#include <iostream>
#include "canvas.h"
#include "caio.h"

using namespace std;

Caio::Caio(Window* window) //: m_window(window)
{
    this->m_window = window;
    m_canvas = new Canvas(m_window);
	pos[0] = 50;
	pos[1] = 350;
	pos[2] = 50;
	pos[3] = 100;
	rgba[0] = 0;
	rgba[1] = 255;
	rgba[2] = 0;
	rgba[3] = 255;

	speed = 25;
	dx = 0;
}

Caio::~Caio()
{	
    delete m_canvas;
}

void
Caio::move()
{
	// Movimenta o BM para a esquerda ou direita
	pos[0] += dx;

	// Se o BM vai muito para a esquerda ou direita
	if( (pos[0] < 0) || ( pos[0] + 800 > 600 ) )
	{
		// Retrocede
		pos[0] -= dx;
	}
}

void
Caio::handleEvent()
{
	while (SDL_PollEvent(&event) != 0)
    {
        switch (event.type)
        {
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_a:
						dx -= speed;
						cout << "esqueda" << endl;
						cout << dx << endl;
                    break;
                    case SDLK_d:
                    	dx += speed;
                    	cout << "direita" << endl;
						cout << dx << endl;
                    break;
                    default:
                        //do nothing
                    break;
                }
            break;

            case SDL_KEYUP:
                switch(event.key.keysym.sym)
                {
                    case SDLK_a:
                    	dx += speed;
                    case SDLK_d:
                    	dx -= speed;
                    break;
                    default:
                        //do nothing
                    break;
                }
            break;

            default:
                // do nothing
            break;
        }        
    }
}

void
Caio::drawCaio()
{
    m_canvas->drawRectangle(pos, rgba);
}

int*
Caio::getPos() 
{
	return pos;
}

int*
Caio::getRGBA() 
{
	return rgba;
}
