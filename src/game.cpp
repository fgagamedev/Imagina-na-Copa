#include "game.h"

#include <string>
#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

Game::Game()
{
    try 
    {
        m_system = new System();
        m_window = new Window();
        m_loadImage = new LoadImages(m_window);
        m_fade = new Fade(m_window);
        m_canvas = new Canvas(m_window);
        m_input = new Input();
        m_caio = new Caio(m_window);

        m_stack = NULL;
        exitstate[0] = false;
        exitstate[1] = false;
        m_input->addHandler(this);
        m_input->addHandler(m_caio);
        m_input->addHandler(m_fade);
    } 
    catch (const string& e)
    {
        free(m_stack);
        delete m_caio;
        delete m_input;
        delete m_canvas;
        delete m_fade;
        delete m_loadImage;
        delete m_window;
        delete m_system;
        throw e;
    }
}

Game::~Game()
{
    free(m_stack);
    delete m_caio;
    delete m_input;
    delete m_canvas;
    delete m_fade;
    delete m_loadImage;
    delete m_window;
    delete m_system;
}

void
Game::run()
{   
    //Front End
    m_stack = m_loadImage->loadTextures(m_stack);
    for (int i = 0; i < 4; i++)
    {
        m_fade->showImage(m_stack);
        m_stack = ISM_Pop(m_stack);
    }
    //Game loop
    while ( !m_quit )
    {
        m_input->eventLoop();
        //m_caio->move();
        m_caio->drawCaio();
        m_canvas->drawElements();
        m_canvas->update();
    }
}

bool 
Game::handle(SDL_Event &event)
{
    bool processed = false;

    if (event.type == SDL_QUIT)
    {
        m_quit = true;
    }

    switch (event.type)
    {
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
                //SDL_keycodes
                case SDLK_LCTRL:
                    exitstate[0] = true;
                    processed = true;
                break;
                case SDLK_q:
                    exitstate[1] = true;
                    processed = true;
                break;
                default:
                break;
            }
        break;

        case SDL_KEYUP:
            switch(event.key.keysym.sym)
            {
                case SDLK_LCTRL:
                    exitstate[0] = false;
                    processed = true;
                break;
                case SDLK_q:
                    exitstate[1] = false;
                    processed = true;
                break;
                default:
                break;
            }
        break;

        default:
        break;
    }
    
    if (exitstate[0] == true && exitstate[1] == true)
    {
        m_quit = true;
    }

    return processed;
}
