#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

class ThreadWrapper
{
	thread t;
public:
	ThreadWrapper(thread m_t)
		: t(move(m_t))
	{}

	void join()
	{
		if (t.joinable())
			t.join();
	}

	~ThreadWrapper()
	{
		t.detach();
	}
};

mutex m;
void Scal(vector<int> v1, vector<int> v2,int& res, int position, int range, int N, int& counter) {
	if (position + range != N)
		ThreadWrapper(thread(Scal, v1, v2, ref(res), position + range, range, N, ref(counter)));

	int tmpRes = 0;
	for (int i = position; i < position + range; i++) {
		tmpRes += v1[i] * v2[i];
	}

	m.lock();
	res += tmpRes;
	counter++;
	m.unlock();
}

void Filling(vector<int>& v, int n) {
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
}

int main()
{
	int N; //vector length
	cout << "Enter the length of the vectors: ";
	cin >> N;
	cout << endl;

	vector<int> v1;
	vector<int> v2;
	int res = 0;

	cout << "Enter the first vector coordinates: ";
	Filling(v1, N);
	cout << "Enter the second vector coordinates: ";
	Filling(v2, N);
	
	int maxTreads = thread::hardware_concurrency();
	maxTreads = (maxTreads > 1) ? maxTreads : 1;

	int oneTread = (N + maxTreads - 1) / maxTreads;
	int counter = 0;

	Scal(v1, v2, res, 0, oneTread, N, counter);

	while (counter != N) {
		cout << "In progress... " << res << endl;
	}
	cout << "Result:  " << res << endl;

	return 0;
}