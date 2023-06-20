#pragma once
#include "Knight.h"

class BountyHunter : public Knight {
public:
	BountyHunter(std::string m_type, std::string m_name)
		: Knight(m_type, m_name) 
	{
		s_hp = hp = 175;
		s_dmg = dmg = 35;
		s_def = def = 15;
	}
};

