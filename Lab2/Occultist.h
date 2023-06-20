#pragma once
#include "Wizzard.h"

class Occultist : public Wizzard {
public:
	Occultist(std::string m_type, std::string m_name)
		: Wizzard(m_type, m_name)
	{
		hp = 125;
		dmg = 40;
		def = 5;
	}
};

