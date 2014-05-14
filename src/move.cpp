/*#include "move.h"
#include <queue>
#include <iostream>

#define XYWH 4

using namespace std;

Move::Move()
{
}

Move::~Move()
{
}

void
Move::eventLoop()
{
	int position[XYWH];
	queue <int[]> positions;

	//pegando eventos pendentes
    while (moved = true)
    {
    	positions.push(position);
	}
	while(positions.empty() == false)
	{
		position = positions.front();
		positions.pop();
		for (size_t i = 0; i < m_handlers.size(); i++)
		{
			if (m_handlers[i]->handle(position))
			{
				break;
			}
		}
	}
}

void 
Move::addHandler(MoveHandler * m)
{
	m_handlers.push_back(m);
}
*/