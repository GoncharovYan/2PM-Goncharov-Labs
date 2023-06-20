#pragma once
#include "Hero.h"
#include "HeroFactory.h"
#include "Crusader.h"
#include "BountyHunter.h"
#include <iostream>

class KnightFactory : public HeroFactory {
public:
	KnightFactory(Hero* m_hero)
		: HeroFactory(m_hero->getType(), m_hero->getName())
	{}
	Hero* produce() override;
};

