#include <iostream>
using namespace std;

// Traverse the whole array and insert each element in its
// right position

void InsertionSort(int *arr, int n)
{
	int curr, j;
	for (int i = 1; i < n; i++)
	{
		curr = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (curr < arr[j])
			{
				arr[j + 1] = arr[j];
			}
			else
				break;
		}
		arr[j + 1] = curr;
	}
}

int main()
{
	int size;
	cin >> size;
	int *input = new int[size];

	for (int i = 0; i < size; i++)
	{
		cin >> input[i];
	}
	InsertionSort(input, size);

	for (int i = 0; i < size; i++)
	{
		cout << input[i] << " ";
	}

	delete[] input;
	return 0;
}