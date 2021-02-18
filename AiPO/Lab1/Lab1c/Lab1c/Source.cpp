#include <iostream>
#include <iomanip>
#include <ctime>

unsigned long long int next = 1;

void srand100(unsigned int seed)
{
	next = seed;
}

int rand100() { //Линейный конгруэнтный метод
	next = next * 1103515245 + 12345;
	return next % 100;
}

long double doublerand() {
	next = next * 1103515245 + 12345;
	long long dbl = next % 1000000000000;
	long double tdbl = static_cast< long double>(dbl) / 1000000000000;
	return tdbl;
}

int main()
{
	std::cout << std::setprecision(12);
	srand100(time(NULL));
	int a = rand100();
	std::cout << "Rand from 0 to 100: " << a << std::endl;

	long double b = doublerand();
	std::cout << "Rand from 0 to 1 with a tail of 12 rand characters: " << b << std::endl;

	std::cout << std::endl << "Rand100 test: " << std::endl;
	for (int i = 0; i < 20; i++)
		std::cout << rand100() << std::endl;
	
	std::cout << std::endl << "Doublerand test: " << std::endl;
	for (int i = 0; i < 20; i++)
		std::cout << doublerand() << std::endl;

	return 0;
}