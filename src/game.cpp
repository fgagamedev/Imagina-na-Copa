#include "game.h"
#include "imageload.h"

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

        ImageLoad* imageLoad = ImageLoad::getInstance();
        imageLoad->setRenderer(m_window->renderer());

        m_keyboard = new Keyboard(&m_quit);
        frontEnd = new FrontEnd();

        m_stack = NULL;
    } 
    catch (const string& e)
    {
        free(m_stack);
        delete frontEnd;
        delete m_keyboard;
        delete m_window;
        delete m_system;
        throw e;
    }
}

Game::~Game()
{
    free(m_stack);
    delete frontEnd;
    delete m_keyboard;
    delete m_window;
    delete m_system;
}

void
Game::init()
{
    frontEnd->init();
    stage.init();
}

void
Game::shutdown()
{
    stage.release();
    frontEnd->release();
}

void
Game::run()
{
    frontEnd->draw();

    while ( !m_quit )
    {
        m_keyboard->eventLoop();
        stage.draw();
    }
}
