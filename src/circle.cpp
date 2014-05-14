#include <SDL2/SDL.h>
#include "canvas.h"
#include "circle.h"
#include "fillpoints.h"

Circle::Circle()
{
	m_fill = new FillPoints();
}
Circle::~Circle()
{
	delete m_fill;
}

void 
Circle::drawCircle(SDL_Renderer* renderer, int radius, int circlePosition[4], int circleColor[4])
{	
	int error = 3 - (radius << 1);
	circlePosition[2] = 0;
	circlePosition[3] = radius;

    SDL_SetRenderDrawColor( renderer, circleColor[0],circleColor[1],circleColor[2],circleColor[3] );
	
	do 
	{
        m_fill->fillPoints(renderer, circlePosition);

		if (error < 0)
		{
			error += (circlePosition[2] << 2) + 6;
		} else 
		{
			error += ((circlePosition[2] - circlePosition[3]) << 2) + 10;
			circlePosition[3]--;
		}	

		circlePosition[2]++;
	} while (circlePosition[2] <= circlePosition[3]);
}
