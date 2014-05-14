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
    ~Game();

    void run();

<<<<<<< HEAD
    void frontEnd();
    bool handle(SDL_Event &event);

    static Game* instance();
    static Game* s_instance;

=======
    bool handle(SDL_Event &event);
>>>>>>> a1e1f4b7806a829f025ffc432c8f0b81cab8c5cf
private:
    Game();
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
<<<<<<< HEAD
    bool initialized;
=======
>>>>>>> a1e1f4b7806a829f025ffc432c8f0b81cab8c5cf

};

#endif // GAME_H
