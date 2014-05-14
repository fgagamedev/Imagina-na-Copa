#include <SDL2/SDL.h>
#include "rectangle.h"

void 
Rectangle::drawRectangle (SDL_Renderer* renderer, int rectPosition[4], int rectColor[4])
{
	SDL_Rect fillRect = { rectPosition[0], rectPosition[1], rectPosition[2], rectPosition[3] };
    SDL_SetRenderDrawColor( renderer, rectColor[0], rectColor[1], rectColor[2], rectColor[3] );
    SDL_RenderFillRect( renderer, &fillRect );
}
