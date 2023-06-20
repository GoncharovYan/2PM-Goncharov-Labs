#pragma once
#include "Archer.h"

class Sniper : public Archer {
public:
	Sniper(std::string m_type, std::string m_name)
		: Archer(m_type, m_name) 
	{
		s_hp = hp = 125;
		s_dmg = dmg = 45;
		s_def = def = 5;
	}
};

