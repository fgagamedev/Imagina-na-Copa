#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "imageload.h"
#include <iostream>

using namespace std;

ImageLoad::ImageLoad()
{
	m_renderer = NULL;
}

static ImageLoad* instance = NULL;

ImageLoad* 
ImageLoad::getInstance()
{
	if (instance == NULL)
	{
		instance = new ImageLoad();
	}
		
	return instance;
}

void 
ImageLoad::releaseInstance()
{
	delete instance;
}

void 
ImageLoad::setRenderer(SDL_Renderer* renderer)
{
	m_renderer = renderer;
}


SDL_Texture* 
ImageLoad::loadImg(const string& path)
{
	if (m_renderer == NULL)
	{
		return NULL;
	}
	
	SDL_Surface* surface = IMG_Load( path.c_str() );

    if( surface == NULL )
    {
        cout << SDL_GetError() << endl;
        throw "Impossível carregar a imagem!";
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface( m_renderer, surface );
    
    if( texture == NULL )
    {
    	SDL_FreeSurface(surface);
    	throw "Impossível criar a textura!";
    }


    return texture;
}

void 
ImageLoad::release(SDL_Texture* texture)
{
	if (texture)
	{
		SDL_DestroyTexture(texture);
	}
}

void
ImageLoad::update(SDL_Texture* m_texture, SDL_Rect* destRect)
{
	//SDL_RenderClear(m_renderer);
    SDL_RenderCopy( m_renderer, m_texture, NULL, destRect );
    SDL_RenderPresent( m_renderer );
}
