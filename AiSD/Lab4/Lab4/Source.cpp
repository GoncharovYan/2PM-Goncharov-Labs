#include <iostream>

using namespace std;

void swap(int arr[], int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void heapify(int arr[], int n, int i)
{
	int largest = i;

	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		swap(arr, i, largest);
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr, i, 0);
		heapify(arr, i, 0);
	}
}


int main()
{
	int x, k, hours = 0;
	cin >> k;
	cin >> x;

	int* parts = new int[k];

	for (int i = 0; i < k; i++)
	{
		cin >> parts[i];
	}
	
	heapSort(parts, k);

	for (int i = 0; i < k; i++)
	{
		hours += x * parts[i];
		if (x > 1)
			x--;
	}

	cout << hours;

	delete[] parts;

	return 0;
}