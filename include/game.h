#ifndef GAME_H
#define GAME_H

#include "system.h"
#include "window.h"
#include "canvas.h"
#include "keyboard.h"
#include "opening.h"

class Game {
public:
    Game();
    ~Game();

    void run();

private:
    System *m_system;
    Window *m_window;
    Canvas *m_canvas;
    Keyboard *m_keyboard;
    Opening *m_opening;

    bool m_quit;
};

#endif // GAME_H
