/*
Лабораторная работа №4
Есть человек, о нём известны: {фамилия, имя, отчество, год рождения и
пароль}. Всей этой информации достаточно для доступа к его счёту.
Требуется написать программу, в которой вводиться вышеперечисленная
информация + add/remove cумма, которая добавляет соответствующую сумму к
счёту или уменьшает (или выводить ошибку – исключение).
Использовать unordered_map с ключом в виде данных(обозначены в фигурных
скобках). Ошибку(exception) обрабатывать. В конце вывести весь список людей
и их суммы на счету.
Указание к выполнению: необходимо описать struct с указанным
набором, описать для него оператор = , написать отдельный класс hashCount в
котором описать перегрузку круглых скобок size_t operator() (const classCount
&el). В ходе реализации функции использовать std::hash от стандартных типов и
случайный полином.
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

struct info
{
	string Name;
	string Surname;
	string Patronymic;

	string Password;
	int Year;
	
	info(string name, string surname, string patronymic, string password, int year)
		: Name(name), Surname(surname), Patronymic(patronymic), Password(password), Year(year) {};
	

	bool operator==(const info i) const
	{
		return (Name == i.Name &&
				Surname == i.Surname &&
				Patronymic == i.Patronymic &&
				Year == i.Year);
	}
};

class hashCount
{
public:
	size_t operator() (const info i) const
	{
		size_t h1 = hash<string>()(i.Name);
		size_t h2 = hash<string>()(i.Surname);
		size_t h3 = hash<string>()(i.Patronymic);
		size_t h4 = hash<int>()(i.Year);

		return h1 ^ h2 ^ h3 ^ h4;
	}
};

class Bank
{
	unordered_map<info, int, hashCount> um;
public:
	void add(info person, int sum) {
		um.insert(make_pair(person, sum));
	}

	void addsum(info person, int sum) {
		try
		{
			auto it = um.at(person);
		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << endl;
			cout << "The person is not in the database" << endl;
			return;
		}
		um[person] += sum;
	}

	void remove(info person) {
		try
		{
			auto it = um.at(person);
		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << endl;
			cout << "The person is not in the database" << endl;
			return;
		}
		um.erase(person);
	}

	void removesum(info person, int sum) {
		try
		{
			auto it = um.at(person);
		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << endl;
			cout << "The person is not in the database" << endl;
			return;
		}
		um[person] -= sum;
	}

	void show() {
		cout << endl;
		for (const auto& per : um) {
			cout << per.first.Name << " " << per.first.Surname << " " << per.first.Patronymic << " has " << per.second << " moneys in the account." << endl;
		}
		cout << endl;
	}
};

int main()
{
	info p1("Andre", "Gan", "Bruh", "XXC40", 2001);
	info p2("Scorceze", "Gan", "Bruh", "XXC40", 2001);
	Bank Perviy;
	Perviy.add(p1, 20000);
	Perviy.add(p2, 15000);

	Perviy.show();

	Perviy.addsum(p2, 20000);
	Perviy.removesum(p1, 5000);

	Perviy.show();

	Perviy.remove(p2);
	Perviy.removesum(p2, 20000);

	Perviy.show();

	Perviy.remove(p2);
	
	return 0;
}