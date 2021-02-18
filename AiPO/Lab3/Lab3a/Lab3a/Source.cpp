#include <iostream>
#include <vector>
using namespace std;

bool find_up_connection(vector<vector<char>> vec, int i, int& j, int m) {
	bool connect = false;
	while (vec[i][j] == '#') {
		if (vec[i - 1][j] == '#')
			connect = true;
		j++;

		if (j == m)	return connect;
	}

	return connect;
}

/*
#####
#...#
#...#
#...#
#####

0

*/

void find_side_connection(vector<vector<char>> vec, int i, int m, int& count) {
	int m_count = 0; //Number of connected gardens
	int swt = 0;

	for (int j = 0; j < m; j++) {

		swt = 0;
		if (vec[i][j] == '#')								swt = 1;
		if (vec[i][j] == '#' && vec[i - 1][j] == '#')		swt = 2;
// #.#
// #.#
// ###
//
// m_count = 1;
// count = 2;
		switch (swt)
		{
		case 1:
		{
			while (j < m && vec[i][j] == '#' && vec[i - 1][j] != '#')
				j++;
			j--;
			break;
		}
		case 2:
		{
			while (j < m && vec[i][j] == '#' && vec[i - 1][j] == '#')
				j++;
			m_count++;
			j--;
			break;
		}
		default:
		{
			if (m_count > 1) count -= m_count - 1;
			m_count = 0;
			break;
		}
		}

	}

	if (swt != 0 && m_count > 1) count -= m_count - 1;
	return;
}





int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<char>> vec(n, vector<char>(m));

	for (auto& el : vec) {
		for (auto& ell : el) {
			cin >> ell;
		}
	}

	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (i == 0) {

				if (vec[i][j] == '#') {
					while (vec[i][j] == '#') {
						j++;
						if (j == m)
							break;
					}
					count++;
				}
			}
			else {
				if (vec[i][j] == '#')
					if (!find_up_connection(vec, i, j, m)) count++;
			}
		}
		if (i != 0)	find_side_connection(vec, i, m, count);
	}

	std::cout << endl;
	for (auto& el : vec) {
		for (auto& ell : el) {
			std::cout << ell;
		}
		std::cout << endl;
	}
	std::cout << endl << count << endl;
	return 0;
}