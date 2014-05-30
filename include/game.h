#ifndef GAME_H
#define GAME_H

#include "frontend.h"
#include "imageload.h"
#include "input.h"
#include "inputhandler.h"
#include "resource.h"
#include "stage.h"
#include "system.h"
#include "window.h"

class Game : public InputHandler
{
public:
    Game();
    ~Game();

    void init();
    void run();
    void shutdown();
    
    bool handle(SDL_Event &event);

private:
    Stage* m_stage;
    FrontEnd* m_frontEnd;
    Input *m_input;
    ImageLoad* imageLoad;

    System *m_system;
    Window *m_window;

    struct ISM * m_stack;
    bool exitstate[2];

    
    bool m_quit;
};

#endif // GAME_H
