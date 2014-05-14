#ifndef CANVAS_H
#define CANVAS_H

#include "line.h"
#include "circle.h"
#include "rectangle.h"
#include "fillpoints.h"
#include "renderpresent.h"

class Canvas
{
	public:
        virtual void drawLines(const SDL_Renderer* renderer, const int linePosition[4], const int lineColor[4]) = 0;
        virtual void fillPoints(const SDL_Renderer* renderer, const int circlePosition[4]) = 0;
        virtual void drawCircle(const SDL_Renderer* renderer, const int radius, 
        	const int circlePosition[4], const int circleColor[4]) = 0;
        virtual void drawRectangle(const SDL_Renderer* renderer, const int rectPosition[4], const int rectColor[4]) = 0;

        virtual void update(const SDL_Renderer* renderer) = 0;
};

#endif // CANVAS_H
