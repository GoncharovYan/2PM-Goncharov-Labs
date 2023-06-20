#pragma once
#include "Skill.h"
class PowerfulShot : public Skill {
public:
	PowerfulShot() {
		name = "Powerful Shot";
	}

	void DescribeMe() override;
};

