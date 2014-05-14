#include <SDL2/SDL.h>
#include <iostream>
#include "canvas.h"
#include "caio.h"
#include "game.h"
#include "draw.h"

using namespace std;

Caio::Caio()
{
	pos[0] = 50;
	pos[1] = 350;
	pos[2] = 38;
	pos[3] = 114;
	rgba[0] = 0;
	rgba[1] = 255;
	rgba[2] = 0;
	rgba[3] = 255;

	speed = 19;
	dx = 0;
}

Caio::~Caio()
{	
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

bool
Caio::handle(SDL_Event &event)
{
    bool processed = false;
    switch (event.type)
    {
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
                case SDLK_a:
					dx -= speed;
					move();
                    cout << "esquerda" << endl;
                    processed = true;
                break;
                case SDLK_d:
                	dx += speed;
                    move();
                	cout << "direita" << endl;
                    processed = true;
                break;
                default:
                break;
            }
        break;

        case SDL_KEYUP:
            switch(event.key.keysym.sym)
            {
                case SDLK_a:
                	dx += speed;
                    move();
                    processed = true;
                case SDLK_d:
                	dx -= speed;
                    move();
                    processed = true;
                break;
                default:
                break;
            }
        break;

        default:
        break;
    }
    return processed;
}

void
Caio::draw(SDL_Renderer* renderer)
{
    Rectangle().drawRectangle(renderer, pos, rgba);
}
