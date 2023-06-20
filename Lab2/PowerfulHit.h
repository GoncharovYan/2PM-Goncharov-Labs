#pragma once
#include "Skill.h"
class PowerfulHit : public Skill {
public:
	PowerfulHit() {
		name = "Powerful Hit";
	}

	void DescribeMe() override;
};

