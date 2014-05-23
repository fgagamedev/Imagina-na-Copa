#include <iostream>

#include "game.h"

using namespace std;

int main ()
{
    try 
    {
        Game* game = new Game();
        
        game->init();
        game->run();
        game->shutdown();
    } 
    catch (const string& error_message) 
    {
        cout << "Erro: " << error_message << endl;
        return -1;
    }
	return 0;
}
