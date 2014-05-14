#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include "window.h"

extern void criarRenderer(SDL_Window* m_window);
extern void destruirRenderer();
extern SDL_Renderer* getRenderer();

static SDL_Renderer* m_renderer;

#endif // RENDERER_H