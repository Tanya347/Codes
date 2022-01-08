#include <iostream>
using namespace std;

// Compare adjacent elements right from the beginning of the array
// Sort them manually by swapping. Then compare the next two elements
// And do the same. This way the largest element will get placed in
// the end on its own. And that is why we run the second loop till
// n - i - 1. Why subtracting 1? Because if we reach the last element
// don't have anything to compare it with.

void bubbleSort(int *arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
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

	bubbleSort(input, size);

	for (int i = 0; i < size; ++i)
	{
		cout << input[i] << " ";
	}

	delete[] input;
	cout << endl;
}
