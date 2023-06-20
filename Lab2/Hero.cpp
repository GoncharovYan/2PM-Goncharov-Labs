#include "Hero.h"
#include "Skill.h"

void Hero::reset() {
	hp = s_hp;
	dmg = s_dmg;
	def = s_def;
}

void Hero::AboutSkills() {
	int k = 0;
	while (k < GetSkillsCount()) {
		skills[k]->DescribeMe();
		k++;
	}
}
