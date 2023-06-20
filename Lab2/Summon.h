#pragma once
#include "Skill.h"
class Summon : public Skill {
public:
	Summon() {
		name = "Summon";
	}

	void DescribeMe() override;

};

