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
        m_keyboard = new Keyboard(&m_quit);

        m_stack = NULL;
    } 
    catch (const string& e)
    {
        free(m_stack);
        delete m_keyboard;
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
    delete m_keyboard;
    delete m_canvas;
    delete m_fade;
    delete m_loadImage;
    delete m_window;
    delete m_system;
}

void
Game::run()
{
    m_stack = m_loadImage->loadTextures(m_stack);
    for (int i = 0; i < 3; i++)
    {
        m_fade->showImage(m_stack);
        m_stack = ISM_Pop(m_stack);
    }
    while ( !m_quit )
    {
        m_keyboard->eventLoop();
        m_canvas->drawElements();
        m_canvas->update();
    }
}
