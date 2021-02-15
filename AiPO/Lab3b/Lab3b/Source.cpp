/*
Задача 4 “Проблемы профессора”.
Профессор по истории проводил экзамен в следующей форме. У него на листе
было записано N различных дат, о которых должны были знать студенты.
Каждый студент садился и писал на своём листе все даты которые он знал,
после отвечал их профессору. Только не все даты студента шли в зачёт.
Входные данные:
Количество вопросов профессора (N)
Даты с 1 по N-ую в столбик.
Количество студентов (M)
Количество ответов студента (K)
Даты с 1 по M-ую
...
N<100, M<10^4; K<10^4
Выходные данные:
В столбик вывести количество правильных (учтённых) ответов каждого
студента.
Вход:
3
1905
1945
2004
1
3
1905
1941
1945
Выход:
2
*/

#include<iostream>
#include<map>
#include<vector>
using namespace std;

struct stud
{
	stud(int cAns)
		: k(cAns)
	{}

	int k; //count asnwers
	int c = 0; //correct answers
	vector<int> ans;

	void Filling()
	{
		int tmp;
		for (int i = 0; i < k; i++) {
			cin >> tmp;
			ans.push_back(tmp);
		}
	}

	int Comparison(vector<int> que)
	{
		for (auto &el : que)
			for (auto &el2 : ans)
				if (el == el2) {
					c++;
					el = -1;
				}
		return c;
	}
};

int main()
{
	int n; //questions count
	cout << "Enter the number of questions: ";
	cin >> n;
	
	vector<int> dates;
	int tmp;

	cout << "Enter the dates: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		dates.push_back(tmp);
	}

	cout << "Enter the number of studs: ";
	int M;
	cin >> M;
	vector<stud*> studs;
	for (int i = 0; i < M; i++) {
		cout << "Enter the number of answers: ";
		cin >> tmp;
		studs.push_back(new stud(tmp));
		studs[i]->Filling();
		cout << studs[i]->Comparison(dates) << endl;
	}


	return 0;
}