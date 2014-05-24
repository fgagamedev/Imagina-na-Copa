#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "window.h"

using namespace std;

Window::Window(unsigned int width, unsigned int height) : m_w(width), m_h(height)
{
    // Setando filtro de textura linear
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );

    // Criando a janela
    m_window = SDL_CreateWindow( "InC. - Imagina na Copa", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        m_w, m_h, SDL_WINDOW_SHOWN );

    if ( m_window == NULL )
        throw "Nao pode criar a janela!";

    // Criando renderer para a janela
    m_renderer = SDL_CreateRenderer( m_window, -1, SDL_RENDERER_ACCELERATED );

    if ( m_renderer == NULL )
    {
        SDL_DestroyWindow(m_window);
        throw "Renderer não pode ser criado";
    }

    SDL_SetRenderDrawColor( m_renderer, 255, 255, 255, 255 );

    // Criando imagem
    imageFlags = IMG_INIT_PNG;

    if (!(IMG_Init(imageFlags) & imageFlags))
    {
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        throw "Criação de imagem não pode ser criado";
    }
    else{
        m_surface = SDL_GetWindowSurface (m_window);
    }
}

Window::~Window()
{
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
}

SDL_Renderer *
Window::renderer() const
{
    return m_renderer;
}

SDL_Surface *
Window::getSurface() const
{
    return m_surface;
}

int
Window::w() const
{
    return m_w;
}

int
Window::h() const
{
    return m_h;
}
