#include "Curse.h"

void Curse::DescribeMe() {
	std::cout << name << std::endl;
	std::cout << "Deals damage equal to the hero's damage. Not reduced by armor. Heals the hero for half of the damage dealt. The curse lasts 2 turns." << std::endl;
}
