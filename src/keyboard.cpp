#include "keyboard.h"

Keyboard::Keyboard(bool* quit)
{
	m_quit = quit;
    exitstate[0] = false;
    exitstate[1] = false;
}

void
Keyboard::exitEvent()
{
	//Início do event loop
    while (SDL_PollEvent(&event) != 0)
    {
        //Requisição de saida do usuário
        if (event.type == SDL_QUIT)
        {
            *m_quit = true;
        } 
        switch (event.type)
        {
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_LCTRL:
                        exitstate[0] = true;
                    break;
                    case SDLK_q:
                        exitstate[1] = true;
                    break;
                    default:
                        //do nothing
                    break;
                }
            break;

            case SDL_KEYUP:
                switch(event.key.keysym.sym)
                {
                    case SDLK_LCTRL:
                        exitstate[0] = false;
                    break;
                    case SDLK_q:
                        exitstate[1] = false;
                    break;
                    default:
                        //do nothing
                    break;
                }
            break;

            default:
                // do nothing
            break;
        }

        if (exitstate[0] == true && exitstate[1] == true)
        {
            *m_quit = true;
        }
    }
}
