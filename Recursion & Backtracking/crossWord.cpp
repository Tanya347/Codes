#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<char>> arr)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool possibleHorizontal(vector<vector<char>> arr, int r, int c, string word)
{
    if (c - 1 >= 0 && arr[r][c - 1] != '+')
        return false;
    else if (c + word.length() < 10 && arr[r][c + word.length()] != '+')
        return false;

    for (int j = 0; j < word.length(); j++)
    {
        if (c + j >= 10)
            return false;

        if (arr[r][c + j] == '-' || arr[r][c + j] == word[j])
            continue;
        else
            return false;
    }
}

bool possibleVertical(vector<vector<char>> arr, int r, int c, string word)
{
    if (r - 1 >= 0 && arr[r - 1][c] != '+')
        return false;
    else if (r + word.length() < 10 && arr[r + word.length()][c] != '+')
        return false;

    for (int i = 0; i < word.length(); i++)
    {
        if (r + i >= 10)
            return false;

        if (arr[r + i][c] == '-' || arr[r + i][c] == word[i])
            continue;
        else
            return false;
    }
}

void placeHorizontal(vector<vector<char>> &arr, int r, int c, string word, vector<bool> &visited)
{
    for (int j = 0; j < word.length(); j++)
    {
        if (arr[r][c + j] == '-')
        {
            visited[j] = true;
            arr[r][c + j] = word[j];
        }
    }
}

void placeVertical(vector<vector<char>> &arr, int r, int c, string word, vector<bool> &visited)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (arr[r + i][c] == '-')
        {
            visited[i] = true;
            arr[r + i][c] = word[i];
        }
    }
}

void unplaceHorizontal(vector<vector<char>> &arr, int r, int c, vector<bool> &visited)
{
    for (int j = 0; j < visited.size(); j++)
    {
        if (visited[j] == true)
        {
            arr[r][c + j] = '-';
        }
    }
}

void unplaceVertical(vector<vector<char>> &arr, int r, int c, vector<bool> &visited)
{
    for (int i = 0; i < visited.size(); i++)
    {
        if (visited[i] == true)
        {
            arr[r + i][c] = '-';
        }
    }
}

void solution(vector<vector<char>> &arr, vector<string> words, int idx)
{

    if (idx == words.size())
    {
        print(arr);
        return;
    }

    string word = words[idx];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i][j] == '-' || arr[i][j] == word[0])
            {
                if (possibleHorizontal(arr, i, j, word))
                {
                    vector<bool> visited(word.length(), false);
                    placeHorizontal(arr, i, j, word, visited);
                    solution(arr, words, idx + 1);
                    unplaceHorizontal(arr, i, j, visited);
                }

                if (possibleVertical(arr, i, j, word))
                {
                    vector<bool> visited(word.length(), false);
                    placeVertical(arr, i, j, word, visited);
                    solution(arr, words, idx + 1);
                    unplaceVertical(arr, i, j, visited);
                }
            }
        }
    }
}

int main()
{
    vector<vector<char>> arr(10, vector<char>(10));
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> arr[i][j];
        }
    }
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    solution(arr, words, 0);
}
