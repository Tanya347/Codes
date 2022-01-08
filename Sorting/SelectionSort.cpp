#include <iostream>
using namespace std;

// Run a for loop to traverse each element of the array
// Run another for loop to traverse the remaining array
// and find the minimum element and swap it with the current node
void selectionSort(int *arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = arr[i], minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				minIndex = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
}

int main()
{
	int size;
	cin >> size;

	int *input = new int[size];

	for (int i = 0; i < size; ++i)
	{
		cin >> input[i];
	}

	selectionSort(input, size);

	for (int i = 0; i < size; ++i)
	{
		cout << input[i] << " ";
	}

	delete[] input;
	cout << endl;
}