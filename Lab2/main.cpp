#include "Hero.h"

#include "HeroFactory.h"
#include "SkillFactory.h"
#include "KnightFactory.h"
#include "ArcherFactory.h"
#include "WizzardFactory.h"

#include <iostream>
#include <map>
#include <string>

Hero* HeroPick() {
	std::string name;
	std::string type;
	int n;
	std::cout << "Player , enter your name: ";
	std::cin >> name;
	std::cout << std::endl << name << ", choose your hero:\n1.Knight\n2.Archer\n3.Wizzard" << std::endl;
	std::cin >> n;
	switch (n) {
	case 1: type = "knight"; break;
	case 2: type = "archer"; break;
	case 3: type = "wizzard"; break;
	default: std::cout << "Incorrect enter" << std::endl;
	}
	HeroFactory HF(type, name);
	return HF.produce();
}
Hero* HeroUpgrade(Hero* player) {
	int n;
	if (player->getType() == "knight")	n = 1;
	else if (player->getType() == "archer")	n = 2;
	else if (player->getType() == "wizzard")	n = 3;

	switch (n) {
	case 1: {
		KnightFactory KF(player);
		return KF.produce();
	}
	case 2: {
		ArcherFactory AF(player);
		return AF.produce();
	}
	case 3: {
		WizzardFactory WF(player);
		return WF.produce();
	}
	}
}
void SkillsSelect(Hero* player) {
	SkillFactory SF(player);
	while (player->GetSkillsCount() < 3) {
		player->addSkill(SF.produce());
	}
}

int main() {
	Hero* player1(HeroPick());
	//Hero* player2 = HeroPick();
	
	std::cout << std::endl;

	player1 = HeroUpgrade(player1);

	std::cout << std::endl;

	SkillsSelect(player1);

	player1->AboutSkills();

	return 0;
}