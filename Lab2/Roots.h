#pragma once
#include "Skill.h"
class Roots : public Skill {
public:
	Roots() {
		name = "Roots";
	}

	void DescribeMe() override;
};

