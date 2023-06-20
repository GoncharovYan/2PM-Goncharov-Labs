#include "WizzardFactory.h"

Hero* WizzardFactory::produce()
{
	int n;
	std::cout << name << ", do you want to upgrade your wizzard to occultist or summoner?\n1.Occultist\t\t2.Summoner" << std::endl;
	std::cin >> n;
	switch (n) {
	case 1: return new Occultist("occultist", name); break;
	case 2: return new Summoner("summoner", name); break;
	default: std::cout << "Incorrect enter" << std::endl;
	}
}
