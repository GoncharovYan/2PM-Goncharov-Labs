/*
2)Последовательность
Вывести ряд Фибоначчи до n-го символа.
При выполнении задания использовать массив, объявленный как F[NMAX], где NMAX - целая,
положительная, числовая константа(100, 200, 5).
Формула ряда:
F(0)=0, F(1) =1, F(n)=F(n-1)+F(n-2)
*/
#include <iostream>
using namespace std;

void Fib(long long F[], const int N)
{
	if (N > 1) {
		F[1] = 1;
		for (int i = 2; i < N; i++)
			F[i] = F[i - 2] + F[i - 1];

	}
}

int main()
{
	const int NMAX(50);
	long long F[NMAX] = {};

	Fib(F, NMAX);

	for (auto el : F)
		cout << el << endl;

	return 0;
}