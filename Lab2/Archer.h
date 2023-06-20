#pragma once
#include "Hero.h"

class Archer : public Hero {
public:
	Archer(std::string m_type, std::string m_name) :
		Hero(m_type, m_name) 
	{
		s_hp = hp = 150;
		s_dmg = dmg = 30;
		s_dmg = def = 5;
	}
};