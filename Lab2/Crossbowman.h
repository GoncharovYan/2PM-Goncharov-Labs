#pragma once
#include "Archer.h"

class Crossbowman : public Archer {
public:
	Crossbowman(std::string m_type, std::string m_name)
		: Archer(m_type, m_name) 
	{
		hp = 175;
		dmg = 35;
		def = 10;
	}
};

