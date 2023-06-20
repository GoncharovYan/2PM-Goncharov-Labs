#pragma once
#include "Skill.h"
class Hit : public Skill {
public:
	Hit() {
		name = "Hit";
	}

	void DescribeMe() override;
};

