#ifndef GAME_H
#define GAME_H

#include "system.h"
#include "stage.h"
#include "window.h"
#include "canvas.h"
#include "keyboard.h"
#include "loadImages.h"
#include "fade.h"
#include "resource.h"

class Game {
public:
    Game();
    ~Game();

    void init();
    void run();
    void shutdown();

private:
    Stage stage;
    
    System *m_system;
    Window *m_window;
    Canvas *m_canvas;
    Keyboard *m_keyboard;
    Fade *m_fade;
    LoadImages *m_loadImages;

    struct ISM * m_stack;
    
    bool m_quit;
};

#endif // GAME_H
