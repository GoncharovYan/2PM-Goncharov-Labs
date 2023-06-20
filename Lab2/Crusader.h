#pragma once
#include "Knight.h"

class Crusader : public Knight {
public:
	Crusader(std::string m_type, std::string m_name)
		: Knight(m_type, m_name)
	{
		s_hp = hp = 200;
		s_dmg = dmg = 30;
		s_def = def = 25;
	}
};

