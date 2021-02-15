#include <vector>
#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;

template <typename T>
void quickSort(T& array, int low, int high)
{
	int i = low;
	int j = high;
	int pivot = array[(i + j) / 2];
	int temp;

	while (i <= j)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i <= j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	}
	if (j > low)
		quickSort(array, low, j);
	if (i < high)
		quickSort(array, i, high);
}

void foo(vector<int>& arr, int n)
{
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

template <typename T>
void print(T arr, int n)
{
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int n;
	cin >> n;

	vector<int> arr;

	foo(arr, n);

	quickSort(arr, 0, n - 1);

	if (arr[n - 1] == 1)
	{
		arr[n - 1] = 2;
		print(arr, n);
		return 0;
	}
	else
		arr[n - 1] = 1;

	quickSort(arr, 0, n - 1);
	print(arr, n);

	return 0;
}