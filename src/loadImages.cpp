#include "loadImages.h"
#include <iostream>

using namespace std;

LoadImages::LoadImages(Window* window) : m_window(window)
{
	// Tryforce Logo
	srcTryforceLogo.x = 0;
    srcTryforceLogo.y = 0;
    srcTryforceLogo.w = 261;
    srcTryforceLogo.h = 151;
    destTryforceLogo.x = 800/2 - 261/2;
    destTryforceLogo.y = 600/2 - 151/2;
    destTryforceLogo.w = 261;
    destTryforceLogo.h = 151;

    // Other Logos
    srcOtherLogo.x = 0;
    srcOtherLogo.y = 0;
    srcOtherLogo.w = 459;
    srcOtherLogo.h = 400;
    destOtherLogo.x = 800/2 - 459/2;
    destOtherLogo.y = 600/2 - 400/2;
    destOtherLogo.w = 459;
    destOtherLogo.h = 400;
    
    // Rating
    srcRating.x = 0;
    srcRating.y = 0;
    srcRating.w = 191;
    srcRating.h = 285;
    destRating.x = 800/2 - 191/2;
    destRating.y = 600/2 - 285/2;
    destRating.w = 191;
    destRating.h = 285;

    // InC menu
    srcMenu.x = 0;
    srcMenu.y = 0;
    srcMenu.w = 682;
    srcMenu.h = 437;
    destMenu.x = 800/2 - 682/2;
    destMenu.y = 600/2 - 437/2;
    destMenu.w = 682;
    destMenu.h = 437;
}

LoadImages::~LoadImages()
{
	SDL_DestroyTexture (m_tryforceLogo);
	SDL_DestroyTexture (m_otherLogo);
    SDL_DestroyTexture (m_rating);
	SDL_DestroyTexture (m_menu);
	SDL_DestroyTexture (m_newTexture);
	SDL_FreeSurface (m_loadedSurface);
}

struct ISM *
LoadImages::loadTextures(struct ISM *m_stack)
{
	try
    {
        m_menu = openingTextures("res/images/menu.png");
        m_stack = ISM_Insert(m_stack, &srcMenu, &destMenu, m_menu);
        m_rating = openingTextures("res/images/rating.png");
        m_stack = ISM_Insert(m_stack, &srcRating, &destRating, m_rating);
        m_otherLogo = openingTextures("res/images/demaisLogos.png");
        m_stack = ISM_Insert(m_stack, &srcOtherLogo, &destOtherLogo, m_otherLogo);
        m_tryforceLogo = openingTextures( "res/images/logo.png" );
        m_stack = ISM_Insert(m_stack, &srcTryforceLogo, &destTryforceLogo, m_tryforceLogo);
    }
    catch (const std::string& e)
    {
        throw e;
    }
    return m_stack;
}

SDL_Texture *
LoadImages::openingTextures(string path)
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
