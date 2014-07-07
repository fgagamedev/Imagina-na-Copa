#include "enemy.h"

Enemy::Enemy() : ImageEffect()
{
	m_hunt = false;
	m_attacking = false;
	m_direction = -1;
	m_tracking = false;
}

Enemy::~Enemy() {}

void
Enemy::update(SDL_Rect target) 
{
	return (void) target;
}

void
Enemy::updatePosition(SDL_Rect target)
{
	m_target = target;
	if(m_hunt)
		hunt();
	else if(m_hunter)
	{
		updateDetection();
	}
	if(((m_patrol == doNormalPatrol()) || (m_patrol == doExtensePatrol())) && !m_attacking)
	{
		updateDirection();
		m_position.x += calculatePosition(m_direction);
	}		
}

void
Enemy::hunt()
{
	if(m_flying)
	{
		if(!m_attacking)
		{
			defineCurrentIdleTime(1);
			if(m_position.y > getFlyingStandardHeight())
				m_position.y += calculatePosition(-1);
			else
			{
				m_position.y = getFlyingStandardHeight();
				if(getCurrentIdleTime() == m_idleFlying)
				{
					setCurrentIdleTime(0);
					m_attacking = true;
					m_tracking = false;
				}
				else
				{
					m_tracking = true;
					updateDirection();
					setCurrentIdleTime(getCurrentIdleTime()+1);	
				}
			}
		}
		else
		{
			if(getPlatformH()-55 >= m_position.y+m_position.h)
				m_position.y += round(2*calculatePosition(1));
			else
			{
				m_attacking = false;
			}
		}
	}
	else
	{
		m_attacking = true;
	}
	if(m_attacking)
	{
		if(m_target.x <= m_position.x)
		{
			m_direction = -1;
			m_position.x += calculatePosition(m_direction);
		}
		else
		{
			m_direction = 1;
			m_position.x += calculatePosition(m_direction);
		}
	}
}

void
Enemy::updateDetection()
{
	switch(m_typeDetection)
	{
		case 0:
			if(ifCollided(0,m_position, m_target))
			{
				m_hunt = true;
			}
		break;

		case 1:
			m_hunt = true;
		break;

		case 400:
			SDL_Rect rangeDetection =
			{	m_position.x-((m_typeDetection)/2),
				m_position.y-((m_typeDetection)/2),
				m_position.w+m_typeDetection,
				m_position.h+m_typeDetection	};
			if((ifCollided(0,rangeDetection,m_target)))
			{
				m_hunt = true;
			}
		break;
	}
}

int
Enemy::calculatePosition(int direction)
{
	loop("[Enemy] Updating Position in Horizontal axis.");
		return round(((m_speed*getDelta())/1000.0)*direction);
}

void
Enemy::updateDirection()
{
	loop("[Enemy] Updating Direction in Horizontal axis.");
	if(m_flying && m_tracking)
	{
			if(m_target.x+80 <= m_position.x)
				m_direction = -1;
			else if(m_target.x-80 >= m_position.x+m_position.w)
				m_direction = 1;
	}
	else
	{
		if (m_position.x >= m_patrolRange[1])
			m_direction = -1;
		else if (m_position.x <= m_patrolRange[0])
			m_direction = 1;
	}
}

bool
Enemy::isOnRightDirection()
{
	loop("[Enemy] Verifying if is on Right Direction.");
	if(m_direction == 1)
		return true;
	return false;
}

bool
Enemy::isOnLeftDirection()
{
	loop("[Enemy] Verifying if is on Left Direction.");
	if(m_direction == -1)
		return true;
	return false;
}

int
Enemy::getItem()
{
	return m_item;
}