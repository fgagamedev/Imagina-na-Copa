#ifndef GAME_H
#define GAME_H

#include "system.h"
#include "window.h"
#include "canvas.h"
#include "input.h"
#include "loadImages.h"
#include "fade.h"
#include "resource.h"
#include "caio.h"

class Game {
public:
    Game();
    ~Game();

    void run();

private:
    System *m_system;
    Window *m_window;
    Canvas *m_canvas;
    Input *m_input;
    Fade *m_fade;
    LoadImages *m_loadImage;
    Caio *m_caio;

    struct ISM * m_stack;
    
    bool m_quit;
};

#endif // GAME_H
