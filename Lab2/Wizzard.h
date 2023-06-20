#pragma once
#include "Hero.h"

class Wizzard : public Hero {
public:
	Wizzard(std::string m_type, std::string m_name) :
		Hero(m_type, m_name) 
	{
		s_hp = hp = 150;
		s_dmg = dmg = 25;
		s_def = def = 10;
	}
};

