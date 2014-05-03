#include "opening.h"
#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

Opening::Opening(Window *window) : m_window(window)
{
    m_srcrectangle.x = 0;
    m_srcrectangle.y = 0;
    m_srcrectangle.w = 261;
    m_srcrectangle.h = 151;

    m_destrectangle.x = 800/2 - 261/2;
    m_destrectangle.y = 600/2 - 151/2;
    m_destrectangle.w = 261;
    m_destrectangle.h = 151;
}

Opening::~Opening()
{
	SDL_DestroyTexture (m_newTexture);
}

SDL_Texture *
Opening::loadOpeningTexture(string path)
{
	m_loadedSurface = NULL;
	m_newTexture = NULL;

    m_loadedSurface = IMG_Load( path.c_str() );
    if( m_loadedSurface == NULL )
    {
        cout << SDL_GetError() << endl;
        throw "Impossível carregar a imagem!";
    }
    else
    {
        m_newTexture = SDL_CreateTextureFromSurface( m_window->renderer(), m_loadedSurface );
        if( m_newTexture == NULL )
        	throw "Impossível criar a textura!";
        SDL_FreeSurface( m_loadedSurface );
    }
    return m_newTexture;
}

void
Opening::showOpening()
{
	m_openingTexture = NULL;

	try
    {
        m_openingTexture = loadOpeningTexture( "res/images/logo.png" );
	}
    catch (const std::string& e)
    {
        throw e;
    }
  
	SDL_RenderClear( m_window->renderer() );
	SDL_RenderCopy( m_window->renderer(), m_openingTexture, &m_srcrectangle, &m_destrectangle );
	SDL_RenderPresent( m_window->renderer() );
}

