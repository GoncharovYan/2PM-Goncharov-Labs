#pragma once

#include <vector>
#include <string>
#include <iostream>

class Skill;

class Hero {
protected:
	int hp, s_hp; //s_ - standart value to reset
	int dmg, s_dmg;
	int def, s_def;
	std::vector<Skill*> skills;
	std::string type;
	std::string name;

public:
	Hero(std::string m_type, std::string m_name) 
		: type(m_type), name(m_name) 
	{
		skills.shrink_to_fit();
	}

	std::string getName() { return name; }
	std::string getType() { return type; }
	int GetSkillsCount() { return skills.size(); }

	void addSkill(Skill* sk) { skills.push_back(sk); }
	
	void reset();

	virtual void AboutSkills();
protected:
	void decreaseHp(int count) { hp -= count; }
	void increaseHp(int count) { hp += count; }
	void increaseArmor(int count) { def += count; }
	void decreaseArmor(int count) { def += count; }
	void increaseDamage(int count) { dmg += count; }
	void decreaseDamage(int count) { dmg -= count; }
};

