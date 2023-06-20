#include "ArcherFactory.h"

Hero* ArcherFactory::produce() {
	int n;
	std::cout << name << ", do you want to upgrade your archer to crossbowman or sniper?\n1.Crossbowman\t\t2.Sniper" << std::endl;
	std::cin >> n;
	switch (n) {
	case 1: return new Crossbowman("crossbowman", name); break;
	case 2: return new Sniper("sniper", name); break;
	default: std::cout << "Incorrect enter" << std::endl;
	}
	
}
