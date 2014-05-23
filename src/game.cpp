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
        m_loadImages = new LoadImages(m_window);
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
        delete m_loadImages;
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
    delete m_loadImages;
    delete m_window;
    delete m_system;
}

void
Game::init()
{
    stage.init();
}

void
Game::shutdown()
{
    stage.release();
}

void
Game::run()
{

   /* //Front End
    m_stack = m_loadImages->loadTextures(m_stack);
    for (int i = 0; i < 4; i++)
    {
        m_fade->showImage(m_stack);
        m_stack = ISM_Pop(m_stack);
    }
    */
    //Game loop
    while ( !m_quit )
    {
        m_keyboard->eventLoop();
        //m_canvas->drawElements();
        stage.draw();
    }
}
