#include <SDL2/SDL.h>
#include "renderpresent.h"

void
RenderPresent::update(SDL_Renderer* renderer)
{
    SDL_RenderPresent(renderer);
}