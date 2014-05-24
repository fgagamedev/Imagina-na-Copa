#include "game.h"
#include "imageload.h"
#include "systemlogger.h"

#include <string>
#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

Game::Game()
{
    try 
    {
        SystemLogger::step("[Game] Trying to Construct.");
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
        SystemLogger::error(e);
        SystemLogger::step("[Game] Destroying Manually.");
        free(m_stack);
        delete frontEnd;
        delete m_keyboard;
        delete m_window;
        delete m_system;
    }
}

Game::~Game()
{
    SystemLogger::step("[Game] Destroying.");
    free(m_stack);
    delete frontEnd;
    delete m_keyboard;
    delete m_window;
    delete m_system;
}

void
Game::init()
{
    SystemLogger::step("[Game] Using Init Method.");
    frontEnd->init();
    stage.init();
}

void
Game::shutdown()
{
    SystemLogger::step("[Game] Using Shutdown Method.");
    stage.release();
    frontEnd->release();
}

void
Game::run()
{
    SystemLogger::step("[Game] Using Run Method.");
    frontEnd->draw();

    while ( !m_quit )
    {
        m_keyboard->eventLoop();
        stage.draw();
    }
}
