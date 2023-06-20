#pragma once
#include "Hero.h"

class Knight : public Hero {
public:
	Knight(std::string m_type, std::string m_name) :
		Hero(m_type, m_name) 
	{
		s_hp = hp = 200;
		s_dmg = dmg = 20;
		s_def = def = 20;
	}
};