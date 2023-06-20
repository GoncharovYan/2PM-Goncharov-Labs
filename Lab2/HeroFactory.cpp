#include "HeroFactory.h"

Hero* HeroFactory::produce()
{
	if (type == "knight")	return new Knight(type, name);
	else if (type == "archer")	return new Archer(type, name);
	else if (type == "wizzard")	return new Wizzard(type, name);
}
