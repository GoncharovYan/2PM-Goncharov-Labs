#pragma once
#include "Hero.h"
#include "Crossbowman.h"
#include "Sniper.h"
#include "HeroFactory.h"
#include <iostream>

class ArcherFactory : public HeroFactory {
public:
	ArcherFactory(Hero* m_hero)
		: HeroFactory(m_hero->getType(), m_hero->getName())
	{
		delete m_hero;
	}
	Hero* produce() override;
};

