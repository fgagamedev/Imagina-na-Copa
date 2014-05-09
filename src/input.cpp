#include "input.h"
#include "keyboard.h"

Input::Input(bool* quit)
{
	m_keyboard = new Keyboard(quit);
	this->m_quit = quit;
}

Input::~Input()
{
	delete m_keyboard;
}

void
Input::eventLoop()
{
	m_keyboard->exitEvent();
}