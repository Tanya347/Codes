#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int> &arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void wiggleSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (i % 2 == 0)
        {
            if (arr[i] > arr[i + 1])
                swap(arr, i, i + 1);
        }
        else
        {
            if (arr[i] < arr[i + 1])
                swap(arr, i, i + 1);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    wiggleSort(arr);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
