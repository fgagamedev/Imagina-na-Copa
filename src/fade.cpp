#include "fade.h"
#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

Fade::Fade(Window* window) : m_window(window)
{

}
Fade::~Fade()
{
    delete m_window;
}

void 
Fade::showImage(struct ISM *m_stack)
{
    fadein(m_stack);
    SDL_Delay(2000);
    fadeout(m_stack);
}

void
Fade::fadein(struct ISM * m_stack)
{
    for (alpha = 0x00; alpha < 0xFF;)
    {
        alpha += 0x05;

        SDL_SetTextureBlendMode( ISM_TopTexture(m_stack), SDL_BLENDMODE_BLEND );
        SDL_SetTextureAlphaMod( ISM_TopTexture(m_stack), alpha );
        SDL_RenderClear( m_window->renderer() );

        SDL_RenderCopy( m_window->renderer(), ISM_TopTexture(m_stack), ISM_TopSrc(m_stack), ISM_TopDest(m_stack) );

        SDL_RenderPresent( m_window->renderer() );
    }
}

void
Fade::fadeout(struct ISM * m_stack)
{
    for (alpha = 0xFF; alpha > 0x00;)
    {
        alpha -= 0x01;
     
        SDL_SetTextureBlendMode( ISM_TopTexture(m_stack), SDL_BLENDMODE_BLEND );
        SDL_SetTextureAlphaMod( ISM_TopTexture(m_stack), alpha );
        SDL_RenderClear( m_window->renderer() );

        SDL_RenderCopy( m_window->renderer(), ISM_TopTexture(m_stack), ISM_TopSrc(m_stack), ISM_TopDest(m_stack) );

        SDL_RenderPresent( m_window->renderer() );
    }

}

