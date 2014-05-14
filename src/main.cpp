#include <iostream>

#include "game.h"

using namespace std;

Game* Game::s_instance = 0;

int main ()
{
    try 
    {
        Game::instance()->run();
    } 
    catch (const string& error_message) 
    {
        cout << "Erro: " << error_message << endl;
        return -1;
    }
	return 0;
}
