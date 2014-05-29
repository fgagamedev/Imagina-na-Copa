#ifndef CURUPIRA_H
#define CURUPIRA_H

#include "enemy.h"

class Curupira : public Enemy 
{
public:
	Curupira(int x, int y, int dx, int max_x, int max_y);

	void init();
	void draw();
	void update(Uint32 delta);
	void release();

protected:
	int m_max_x;
	int m_max_y;
};

#endif

