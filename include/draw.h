#ifndef DRAW_H
#define DRAW_H

#include <SDL2/SDL.h>
#include "caio.h"

extern void drawElements(SDL_Renderer* renderer);
extern void drawBackground(SDL_Renderer* renderer);
extern void drawSun(SDL_Renderer* renderer);
extern void drawPlatform(SDL_Renderer* renderer);
extern void drawCaio(SDL_Renderer* renderer);
extern void drawSebastiao(SDL_Renderer* renderer);
extern void drawSebastiaoDialogue(SDL_Renderer* renderer);
extern void drawEnemyCurupira(SDL_Renderer* renderer);
extern void drawEnemyUrubu(SDL_Renderer* renderer);
extern void drawBarraHP(SDL_Renderer* renderer);
extern void drawInventory(SDL_Renderer* renderer);
extern void drawAim(SDL_Renderer* renderer);

#endif // DRAW_H

