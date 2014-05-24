#ifndef GAME_H
#define GAME_H

#include "system.h"
#include "stage.h"
#include "window.h"
#include "keyboard.h"
#include "resource.h"
#include "frontend.h"

class Game {
public:
    Game();
    ~Game();

    void init();
    void run();
    void shutdown();

private:
    Stage stage;
    FrontEnd* frontEnd;
    
    System *m_system;
    Window *m_window;
    Keyboard *m_keyboard;

    struct ISM * m_stack;
    
    bool m_quit;
};

#endif // GAME_H
