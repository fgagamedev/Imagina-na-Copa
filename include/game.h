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
#include "inputhandler.h"

class Game : public InputHandler 
{
public:
    Game();
    ~Game();

    void run();

    bool handle(SDL_Event &event);
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
    bool exitstate[2];

};

#endif // GAME_H
