#pragma once
#include "Skill.h"
class FireBall : public Skill {
public:
	FireBall() {
		name = "Fire Ball";
	}

	void DescribeMe() override;
};

