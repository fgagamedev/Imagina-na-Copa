#ifndef CIRCLE_H
#define CIRCLE_H

#include "fillpoints.h"

class Circle
{
public:
	Circle();
	~Circle();
	void drawCircle(SDL_Renderer* renderer, int radius, int circlePosition[4], int circleColor[4]);
private:
	FillPoints* m_fill;
};
#endif // CIRCLE_H