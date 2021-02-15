//fix: Знаки < и > где0то перепутаны

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Treap {
	struct Node {
		int key, priority;
		Node* l, * r;
		Node(int key) : key(key), priority(rand()), l(NULL), r(NULL) {}
	}	*root = nullptr;

	static Node* merge(Node* a, Node* b) {
		if (a == NULL) return b;
		if (b == NULL) return a;

		if (a->priority < b->priority) {
			b->l = merge(a, b->l);
			return b;
		}
		else {
			a->r = merge(a->r, b);
			return a;
		}
	}

	static void split(Node* n, int key, Node*& a, Node*& b) {
		if (n == NULL) {
			a = b = nullptr;
			return;
		}
		if (n->key < key) {
			split(n->r, key, n->r, b);
			a = n;
		}
		else {
			split(n->l, key, a, n->l);
			b = n;
		}
	}

	int next(int key, Node* point) {
		if (point != NULL) {
			next(key, point->l);
			if (point->key >= key)
				return point->key;

			next(key, point->r);
		}
	}

	int _max;
public:
	bool contains(int key) {
		Node* less, * equal, * greater;
		split(root, key, less, greater);
		split(greater, key + 1, equal, greater);
		bool result = equal;
		root = merge(merge(less, equal), greater);
		return result;
	}

	void insert(int key) {
		if (contains(key)) return;
		else if (root == NULL) _max = key;
		else if (key > _max)	_max = key;
		Node* less, * greater;
		split(root, key, less, greater);
		root = merge(merge(less, new Node(key)), greater);
	}

	/*void erase(int key) {
		Node* less, * equal, * greater;
		split(root, key, less, greater);
		split(greater, key + 1, equal, greater);
		root = merge(less, greater);
	}*/

	int next(int key) {
		if (key > _max) return -1;
		return next(key, root);
	}

};

int main()
{
	Treap t;
	int n;
	//cout << "Enter the symbol of transactions: ";
	cin >> n;
	cout << endl;

	int Num;
	char Oper;
	vector <pair<char, int>> trans;
	for (int i = 0; i < n; i++) {
		//cout << "Enter the symbol of transaction and number (" << i + 1 << "/" << n << "): ";
		cin >> Oper >> Num;
		trans.push_back(make_pair(Oper, Num));
		cout << endl;
	}

	stack<int> ans;
	for (int i = 0; i < trans.size(); i++) {
		if (i > 0 && trans[i].first == '+' && trans[i - 1].first == '?')
			t.insert(trans[i].second + ans.top());
		else if (trans[i].first == '+')
			t.insert(trans[i].second);
		else if (trans[i].first == '?')
			ans.push(t.next(trans[i].second));
		//else
			//cout << "Incorrect enter" << endl;
	}

	/*for (auto p : trans) {
		cout << p.first << " " << p.second << endl;
	}
	cout << endl << endl;*/

	stack<int> sna;
	while (!ans.empty()) {
		sna.push(ans.top());
		ans.pop();
	}
	while (!sna.empty()) {
		cout << sna.top() << endl;
		sna.pop();
	}

	return 0;
}