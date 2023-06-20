#pragma once
#include "Hero.h"

#include "Skill.h"
#include "FireBall.h"
#include "IceShard.h"
#include "PowerfulHit.h"
#include "Roots.h"
#include "Hit.h"

#include "Curse.h"
#include "Lasso.h"
#include "PowerfulShot.h"
#include "Shrapnel.h"
#include "Summon.h"
#include "ShiningShield.h"

#include <string>
#include <iostream>

class SkillFactory   {
protected:
	std::string type;
	std::string name;
	int skills;
public:
	SkillFactory(Hero* hero)
		: type(hero->getType()), name(hero->getName()), skills(1)  {}
	Skill* produce();
	void FreeSkills();
	std::string SpecialSkills();
};

