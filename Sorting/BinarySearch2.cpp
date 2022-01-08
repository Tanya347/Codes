#include <iostream>
using namespace std;

int bSearch(int *input, int si, int ei, int element)
{
    if (si <= ei)
    {
        int mid = (si + ei) / 2;
        if (input[mid] == element)
            return mid;
        else if (input[mid] < element)
            bSearch(input, mid + 1, ei, element);
        else
            bSearch(input, si, mid - 1, element);
    }
    return -1;
}

int binarySearch(int input[], int size, int element)
{
    return bSearch(input, 0, size - 1, element);
}

int main()
{
    int input[100000], length, element, ans;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> input[i];
    }

    cin >> element;
    ans = binarySearch(input, length, element);
    cout << ans << endl;
}