#include "KnightFactory.h"

Hero* KnightFactory::produce()
{
	int n;
	std::cout << name << ", do you want to upgrade your knight to crusader or bounty hunter?\n1.Crusader\t\t2.Bounty Hunter" << std::endl;
	std::cin >> n;
	switch (n) {
	case 1: return new Crusader("crusader", name); break;
	case 2: return new BountyHunter("bountyhunter", name); break;
	default: std::cout << "Incorrect enter" << std::endl;
	}
}
