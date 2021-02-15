#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int a[1000 * 100 + 5];
vector <int> pr;
typedef pair <int, int> p;
vector <p> v;

void prost(int n) {
	pr.push_back(2);
	int bag = 0;
	for (int j = 3; j <= n; ++j) {
		bag = 0;
		for (int i = 2; i * i <= j; ++i) {
			if (j % i == 0) {
				bag++;
				break;
			}
		}
		if (bag == 0) pr.push_back(j);
	}
}

int main() {
	int n;
	cin >> n;
	prost(n);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	int k = 0;
	for (int i = 1; i <= n; ++i) {
		int num = a[i], pos = i;
		while (pos != num) {
			int prost = num - pos + 1, bag = 0;
			for (int j = prost; j > 1; --j) {
				bag = 0;
				for (int k = 2; k * k <= j; ++k) {
					if (j % k == 0) {
						bag++;
						break;
					}
				}
				if (bag == 0) {
					prost = j;
					break;
				}
			}

			swap(a[pos], a[prost + pos - 1]);
			v.push_back(make_pair(pos, prost + pos - 1));
			pos = prost + pos - 1;
		}
		if (a[i] != i) i--;
	}


	cout << v.size() << endl;
	k = v.size();
	for (int i = 0; i < k; ++i) {
		cout << v[i].first << " " << v[i].second << endl;
	}
}