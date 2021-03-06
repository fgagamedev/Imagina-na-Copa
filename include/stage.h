#ifndef STAGE_H
#define STAGE_H

#include "entity.h"
#include "hud.h"
#include "scenario.h"
//#include "item.h"

#include "fontconfiguration.h"
#include "text.h"

#include "potion.h"
#include "alteredpotion.h"
#include "antitudo.h"
#include "battery.h"
#include "freeboi.h"
#include "cup.h"
#include "inclogo.h"
#include "antiboss.h"

using namespace fontConfiguration;

class Stage : public Scenario, public Hud, public Entity
{
public:
	Stage();
	~Stage();

	void init();
	void draw();
	void update();
	
	void setGameOver(bool over);
	bool gameOver();
	void setFinished(bool finished);
	bool isFinished();
	void damagingCaio();
	void lootItem();
	void killingEnemy();
	void usingItens();
	void rescuingCivilian();
	void controlEntityEvents();

protected:
	bool m_gameOver;
	bool m_finished;
};

#endif // STAGE_H