#pragma once
#include "Hero.h"
#include "Knight.h"
#include "Archer.h"
#include "Wizzard.h"
#include <string>

class HeroFactory {
protected:
	std::string type;
	std::string name;
public:
	HeroFactory(std::string m_type, std::string m_name)
		: type(m_type), name(m_name) {}
	virtual Hero* produce();
};