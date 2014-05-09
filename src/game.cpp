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
        m_input = new Input(&m_quit);
        m_caio = new Caio(m_window);

        m_stack = NULL;
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
    /*//Front End
    m_stack = m_loadImage->loadTextures(m_stack);
    for (int i = 0; i < 4; i++)
    {
        m_fade->showImage(m_stack);
        m_stack = ISM_Pop(m_stack);
    }
    */
    //Game loop
    while ( !m_quit )
    {
        //m_caio->move();
        m_input->eventLoop();
        //m_caio->handleEvent();
        //m_caio->drawCaio();
        m_canvas->drawElements();
        m_canvas->update();
    }
}
