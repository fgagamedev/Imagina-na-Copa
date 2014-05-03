#include "keyboard.h"

Keyboard::Keyboard(bool* m_quit)
{
	this->m_quit = m_quit;
	keystate[0] = false;
	keystate[1] = false;
}

void
Keyboard::eventLoop()
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
                        keystate[0] = true;
                    break;
                    case SDLK_q:
                        keystate[1] = true;
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
                        keystate[0] = false;
                    break;
                    case SDLK_q:
                        keystate[1] = false;
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

        if (keystate[0] == true && keystate[1] == true)
        {
            *m_quit = true;
        }
    }
}
