#pragma once
#include "Wizzard.h"

class Summoner : public Wizzard {
public:
	Summoner(std::string m_type, std::string m_name)
		: Wizzard(m_type, m_name)
	{
		s_hp = hp = 150;
		s_dmg = dmg = 30;
		s_def = def = 15;
	}
};

