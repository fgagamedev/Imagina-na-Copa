#include <SDL2/SDL.h>
#include "renderer.h"
#include "window.h"

void
criarRenderer(SDL_Window* m_window)
{
    m_renderer = SDL_CreateRenderer( m_window, -1, SDL_RENDERER_ACCELERATED );

    if ( m_renderer == NULL )
    {
        SDL_DestroyWindow(m_window);
        throw "Renderer não pode ser criado";
    }

    SDL_SetRenderDrawColor( m_renderer, 255, 255, 255, 255 );
}

void
destruirRenderer()
{
	SDL_DestroyRenderer(m_renderer);
}

SDL_Renderer*
getRenderer()
{
	return m_renderer;
}