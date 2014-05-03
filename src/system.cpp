#include "system.h"

#include <SDL2/SDL.h>

System::System()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw "A SDL nao pode ser inicializada!";
}

System::~System()
{
    SDL_Quit();
}
