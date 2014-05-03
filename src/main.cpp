#include <iostream>

#include "game.h"

using namespace std;

int main ()
{
    Game *game = NULL;
    try 
    {
        game = new Game();
        game->run();
    } 
    catch (const string& error_message) 
    {
        cout << "Erro: " << error_message << endl;
        return -1;
    }
	return 0;
}
