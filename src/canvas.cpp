#include <SDL2/SDL.h>
#include "canvas.h"
	
Canvas::Canvas(Window *window) : m_window(window)
{
}

void Canvas::drawLines(int linePosition[4], int lineColor[4])
{
    SDL_SetRenderDrawColor( m_window->renderer(), lineColor[0], lineColor[1], lineColor[2], lineColor[3] );
    SDL_RenderDrawLine( m_window->renderer(), linePosition[0], linePosition[1], linePosition[2], linePosition[3] );
}

void Canvas::fillPoints(int circlePosition[4])
{
	for (int j = circlePosition[2]; j <= circlePosition[3]; j++)
	{
        SDL_RenderDrawPoint(m_window->renderer(), circlePosition[0]+circlePosition[2], circlePosition[1]+j);
        SDL_RenderDrawPoint(m_window->renderer(), circlePosition[0]+circlePosition[2], circlePosition[1]-j);
        SDL_RenderDrawPoint(m_window->renderer(), circlePosition[0]-circlePosition[2], circlePosition[1]+j);
        SDL_RenderDrawPoint(m_window->renderer(), circlePosition[0]-circlePosition[2], circlePosition[1]-j);
        SDL_RenderDrawPoint(m_window->renderer(), circlePosition[0]+j, circlePosition[1]+circlePosition[2]);
        SDL_RenderDrawPoint(m_window->renderer(), circlePosition[0]+j, circlePosition[1]-circlePosition[2]);
        SDL_RenderDrawPoint(m_window->renderer(), circlePosition[0]-j, circlePosition[1]+circlePosition[2]);
        SDL_RenderDrawPoint(m_window->renderer(), circlePosition[0]-j, circlePosition[1]-circlePosition[2]);

	}
}

void Canvas::drawFilledCircle(int radius, int circlePosition[4], int circleColor[4])
{	
	int error = 3 - (radius << 1);
	circlePosition[2] = 0;
	circlePosition[3] = radius;

    SDL_SetRenderDrawColor( m_window->renderer(), circleColor[0],circleColor[1],circleColor[2],circleColor[3] );
	
	do 
	{
        fillPoints(circlePosition);

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

void Canvas::drawRectangle (int rectPosition[4], int rectColor[4])
{
	SDL_Rect fillRect = { rectPosition[0], rectPosition[1], rectPosition[2], rectPosition[3] };
    SDL_SetRenderDrawColor( m_window->renderer(), rectColor[0], rectColor[1], rectColor[2], rectColor[3] );
    SDL_RenderFillRect( m_window->renderer(), &fillRect );
}

void
Canvas::update()
{
    SDL_RenderPresent(m_window->renderer());
}

// Daqui para baixo deve-se refatorar

void Canvas::drawElements()
{
    drawBackground();
    drawSun();
    drawPlatform();
    drawCaio();
    drawSebastiao();
    drawSebastiaoDialogue();
    drawEnemyCurupira();
    drawEnemyUrubu();
    drawBarraHP();
    drawInventory();
    drawAim();
}

void Canvas::drawBackground()
{
	// Setting white color to the background 
    SDL_SetRenderDrawColor( m_window->renderer(), 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( m_window->renderer() );
}

void Canvas::drawSun()
{
	// Setting to the background a yellow sun
	int circlePosition[4] = {60, 150, 0, 0};
	int circleRGBAColor[4] = {255, 255, 0, 255};
	int radius = 60;
    drawFilledCircle(radius, circlePosition, circleRGBAColor);
}

void Canvas::drawPlatform()
{
    int rectanglePosition[4] = {0, m_window->h()-150, m_window->w(), 150};
    int rectangleRGBAColor[4] = {255, 255, 0, 255};
    drawRectangle(rectanglePosition, rectangleRGBAColor);
}

void Canvas::drawCaio()
{
	
    int rectanglePosition[4] = {50, m_window->h()-250, 50, 100};
	int rectangleRGBAColor[4] = { 0, 255, 0, 255 };
    drawRectangle(rectanglePosition, rectangleRGBAColor);
}

void Canvas::drawSebastiao()
{
    int rectanglePosition[4] = {m_window->w()-265, 10, 250, 125};
	int rectangleRGBAColor[4] = { 0, 0, 255, 255 };
    drawRectangle(rectanglePosition, rectangleRGBAColor);
}

void Canvas::drawSebastiaoDialogue()
{ 
	// Drawing a big black rectangle to Sebastião's dialogues
	int rectanglePosition[4] = { 265, 10, 250, 125 };
	int rectangleRGBAColor[4] = { 0, 0, 0, 255 };
    drawRectangle(rectanglePosition, rectangleRGBAColor);
}

void Canvas::drawEnemyCurupira()
{
	// Drawing a cyan rectangles to the enemies Curupira
    int rectanglePosition[4] = { m_window->w()-100, m_window->h()-250, 50, 100 };
	int rectangleRGBAColor[4] = { 0, 255, 255, 255 };
    drawRectangle(rectanglePosition, rectangleRGBAColor);
    rectanglePosition[0] = m_window->w()-200;
    drawRectangle(rectanglePosition, rectangleRGBAColor);
}

void Canvas::drawEnemyUrubu()
{
	// Drawing a black rectangles to the enemies Urubu
	int rectanglePosition[4] = { 150, 175, 50, 25 };
	int rectangleRGBAColor[4] = { 0, 0, 0, 255 };
    drawRectangle(rectanglePosition, rectangleRGBAColor);
	rectanglePosition[0] = 350; 
    drawRectangle(rectanglePosition, rectangleRGBAColor);
	rectanglePosition[0] = 550; 
    drawRectangle(rectanglePosition, rectangleRGBAColor);
}

void Canvas::drawBarraHP()
{
	// Drawing a red rectangles to the HP gauge
	int rectanglePosition[4] = { 10, 10, 30, 20 };
	int rectangleRGBAColor[4] = { 255, 0, 0, 255 };
    drawRectangle(rectanglePosition, rectangleRGBAColor);
	rectanglePosition[0] = 50; 
    drawRectangle(rectanglePosition, rectangleRGBAColor);
	rectanglePosition[0] = 90; 
    drawRectangle(rectanglePosition, rectangleRGBAColor);
}

void Canvas::drawInventory()
{
	// Drawing a magenta rectangle to the Inventory
	int rectanglePosition[4] = { 10, 40, 35, 25 };
	int rectangleRGBAColor[4] = { 255, 0, 255, 255 };
    drawRectangle(rectanglePosition, rectangleRGBAColor);
	rectanglePosition[0] = 50; 
    drawRectangle(rectanglePosition, rectangleRGBAColor);
	rectanglePosition[0] = 90; 
    drawRectangle(rectanglePosition, rectangleRGBAColor);
	rectanglePosition[0] = 130; 
    drawRectangle(rectanglePosition, rectangleRGBAColor);
	rectanglePosition[0] = 170; 
    drawRectangle(rectanglePosition, rectangleRGBAColor);
	rectanglePosition[0] = 210; 
    drawRectangle(rectanglePosition, rectangleRGBAColor);
}

void Canvas::drawAim()
{
	// Drawing crossed lines of the aim reticle	
    int linePosition[4] = {((m_window->w()/2)-10), (m_window->h()/2), ((m_window->w()/2)-3), (m_window->h()/2)};
	int lineColor[4] = {0,255,0,255};
    drawLines(linePosition, lineColor);
    linePosition[0] = ((m_window->w()/2)+3);
    linePosition[2] = ((m_window->w()/2)+10);
    drawLines(linePosition, lineColor);
    linePosition[0] = (m_window->w()/2);
    linePosition[1] = ((m_window->h()/2)-10);
    linePosition[2] = (m_window->w()/2);
    linePosition[3] = ((m_window->h()/2)-3);
    drawLines(linePosition, lineColor);
    linePosition[1] = ((m_window->h()/2)+3);
    linePosition[3] = ((m_window->h()/2)+10);
    drawLines(linePosition, lineColor);
}

