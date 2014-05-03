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
        m_opening = new Opening(m_window);
        m_canvas = new Canvas(m_window);
        m_keyboard = new Keyboard(&m_quit);
    } 
    catch (const string& e)
    {
        delete m_keyboard;
        delete m_opening;
        delete m_canvas;
        delete m_window;
        delete m_system;
        throw e;
    }
}

Game::~Game()
{
    delete m_keyboard;
    delete m_opening;
    delete m_canvas;
    delete m_window;
    delete m_system;
}

void
Game::run()
{
    m_opening->showOpening();
    SDL_Delay (2000);
    while ( !m_quit )
    {
        m_keyboard->eventLoop();
        m_canvas->drawElements();
        m_canvas->update();
    }
}
