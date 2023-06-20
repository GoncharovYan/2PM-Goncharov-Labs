#pragma once
#include "Hero.h"
#include "HeroFactory.h"
#include "Occultist.h"
#include "Summoner.h"
#include <iostream>

class WizzardFactory : public HeroFactory {
public:
	WizzardFactory(Hero* m_hero)
		: HeroFactory(m_hero->getType(), m_hero->getName())
	{}
	Hero* produce() override;
};
