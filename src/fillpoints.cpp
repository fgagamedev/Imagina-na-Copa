#include <SDL2/SDL.h>
#include "fillpoints.h"

void 
FillPoints::fillPoints(SDL_Renderer* renderer, int circlePosition[4])
{
	for (int j = circlePosition[2]; j <= circlePosition[3]; j++)
	{
        SDL_RenderDrawPoint(renderer, circlePosition[0]+circlePosition[2], circlePosition[1]+j);
        SDL_RenderDrawPoint(renderer, circlePosition[0]+circlePosition[2], circlePosition[1]-j);
        SDL_RenderDrawPoint(renderer, circlePosition[0]-circlePosition[2], circlePosition[1]+j);
        SDL_RenderDrawPoint(renderer, circlePosition[0]-circlePosition[2], circlePosition[1]-j);
        SDL_RenderDrawPoint(renderer, circlePosition[0]+j, circlePosition[1]+circlePosition[2]);
        SDL_RenderDrawPoint(renderer, circlePosition[0]+j, circlePosition[1]-circlePosition[2]);
        SDL_RenderDrawPoint(renderer, circlePosition[0]-j, circlePosition[1]+circlePosition[2]);
        SDL_RenderDrawPoint(renderer, circlePosition[0]-j, circlePosition[1]-circlePosition[2]);
	}
}
