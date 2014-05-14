#include <SDL2/SDL.h>
#include "line.h"

void 
Line::drawLines(SDL_Renderer* renderer, int linePosition[4], int lineColor[4])
{
    SDL_SetRenderDrawColor( renderer, lineColor[0], lineColor[1], lineColor[2], lineColor[3] );
    SDL_RenderDrawLine( renderer, linePosition[0], linePosition[1], linePosition[2], linePosition[3] );
}