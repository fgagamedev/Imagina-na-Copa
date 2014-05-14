/*#ifndef MOVE_H
#define MOVE_H

#include <vector>
#include "movehandler.h"

using namespace std;

class Move
{
public:
	Move();
	~Move();
	void eventLoop();
	void addHandler(MoveHandler * m);
private:
	bool moved;
	vector<MoveHandler *> m_handlers;
};

#endif // MOVE_H
*/