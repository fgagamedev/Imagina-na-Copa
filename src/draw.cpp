#include "draw.h"
#include "rectangle.h"
#include "line.h"
#include "circle.h"
#include "caio.h"

#include <SDL2/SDL.h>

void drawElements(SDL_Renderer* renderer)
{
    drawBackground(renderer);
    drawSun(renderer);
    drawPlatform(renderer);
 //   drawCaio(renderer);
    drawSebastiao(renderer);
    drawSebastiaoDialogue(renderer);
    drawEnemyCurupira(renderer);
    drawEnemyUrubu(renderer);
    drawBarraHP(renderer);
    drawInventory(renderer);
    drawAim(renderer);
}

void drawBackground(SDL_Renderer* renderer)
{
    // Setting white color to the background 
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( renderer );
}

void drawSun(SDL_Renderer* renderer)
{
    // Setting to the background a yellow sun
    int circlePosition[4] = {60, 150, 0, 0};
    int circleRGBAColor[4] = {255, 255, 0, 255};
    int radius = 60;
    Circle().drawCircle(renderer, radius, circlePosition, circleRGBAColor);
}

void drawPlatform(SDL_Renderer* renderer)
{
    int rectanglePosition[4] = {0, 450, 800, 150};
    int rectangleRGBAColor[4] = {255, 255, 0, 255};
    Rectangle().drawRectangle(renderer, rectanglePosition, rectangleRGBAColor);
}

/*void drawCaio(SDL_Renderer* renderer)
{
    Caio().draw(renderer);
}
*/
void drawSebastiao(SDL_Renderer* renderer)
{
    int rectanglePosition[4] = {535, 10, 250, 125};
    int rectangleRGBAColor[4] = { 0, 0, 255, 255 };
    Rectangle().drawRectangle(renderer, rectanglePosition, rectangleRGBAColor);
}

void drawSebastiaoDialogue(SDL_Renderer* renderer)
{ 
    // Drawing a big black rectangle to Sebastião's dialogues
    int rectanglePosition[4] = { 265, 10, 250, 125 };
    int rectangleRGBAColor[4] = { 0, 0, 0, 255 };
    Rectangle().drawRectangle(renderer, rectanglePosition, rectangleRGBAColor);
}

void drawEnemyCurupira(SDL_Renderer* renderer)
{
    // Drawing a cyan rectangles to the enemies Curupira
    int rectanglePosition[4] = { 700, 350, 50, 100 };
    int rectangleRGBAColor[4] = { 0, 255, 255, 255 };
    Rectangle().drawRectangle(renderer, rectanglePosition, rectangleRGBAColor);
    rectanglePosition[0] = 600;
    Rectangle().drawRectangle(renderer, rectanglePosition, rectangleRGBAColor);
}

void drawEnemyUrubu(SDL_Renderer* renderer)
{
    // Drawing a black rectangles to the enemies Urubu
    int rectanglePosition[4] = { 150, 175, 50, 25 };
    int rectangleRGBAColor[4] = { 0, 0, 0, 255 };
    Rectangle().drawRectangle(renderer, rectanglePosition, rectangleRGBAColor);
    rectanglePosition[0] = 350; 
    Rectangle().drawRectangle(renderer, rectanglePosition, rectangleRGBAColor);
    rectanglePosition[0] = 550; 
    Rectangle().drawRectangle(renderer, rectanglePosition, rectangleRGBAColor);
}

void drawBarraHP(SDL_Renderer* renderer)
{
    // Drawing a red rectangles to the HP gauge
    int rectanglePosition[4] = { 10, 10, 30, 20 };
    int rectangleRGBAColor[4] = { 255, 0, 0, 255 };
    Rectangle().drawRectangle(renderer, rectanglePosition, rectangleRGBAColor);
    rectanglePosition[0] = 50; 
    Rectangle().drawRectangle(renderer, rectanglePosition, rectangleRGBAColor);
    rectanglePosition[0] = 90; 
    Rectangle().drawRectangle(renderer, rectanglePosition, rectangleRGBAColor);
}

void drawInventory(SDL_Renderer* renderer)
{
    // Drawing a magenta rectangle to the Inventory
    int rectanglePosition[4] = { 10, 40, 35, 25 };
    int rectangleRGBAColor[4] = { 255, 0, 255, 255 };
    Rectangle().drawRectangle(renderer, rectanglePosition, rectangleRGBAColor);
    rectanglePosition[0] = 50; 
    Rectangle().drawRectangle(renderer, rectanglePosition, rectangleRGBAColor);
    rectanglePosition[0] = 90; 
    Rectangle().drawRectangle(renderer, rectanglePosition, rectangleRGBAColor);
    rectanglePosition[0] = 130; 
    Rectangle().drawRectangle(renderer, rectanglePosition, rectangleRGBAColor);
    rectanglePosition[0] = 170; 
    Rectangle().drawRectangle(renderer, rectanglePosition, rectangleRGBAColor);
    rectanglePosition[0] = 210; 
    Rectangle().drawRectangle(renderer, rectanglePosition, rectangleRGBAColor);
}

void drawAim(SDL_Renderer* renderer)
{
    // Drawing crossed lines of the aim reticle     
    int linePosition[4] = {(400-10), 300, (400-3), 300};
    int lineColor[4] = {0,255,0,255};
    Line().drawLines(renderer, linePosition, lineColor);
    linePosition[0] = (400+3);
    linePosition[2] = (400+10);
    Line().drawLines(renderer,linePosition, lineColor);
    linePosition[0] = 400;
    linePosition[1] = (300-10);
    linePosition[2] = 400;
    linePosition[3] = (300-3);
    Line().drawLines(renderer, linePosition, lineColor);
    linePosition[1] = (300+3);
    linePosition[3] = (300+10);
    Line().drawLines(renderer, linePosition, lineColor);
}