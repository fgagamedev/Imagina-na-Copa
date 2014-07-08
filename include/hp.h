#ifndef HP_H
#define HP_H

#include "imagesprite.h"

class Hp : public ImageSprite
{
public:
	Hp();
	~Hp();

	void generateClips();
	void drawEach();
	void setHp(int health);
	void setMaxHp(int max);
	void setPoisonedHp(int poison);
	int getHp();
protected:
	int hp;
	int maxHp;
	int poisonedHp;
};

#endif // HP_H