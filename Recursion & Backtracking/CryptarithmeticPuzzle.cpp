#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int getNum(string s, unordered_map<char, int> letters)
{
    string num = "";

    for (int i = 0; i < s.length(); i++)
    {
        num += (letters[s[i]] + '0');
    }

    return stoi(num);
}

void solution(string unique, int idx, unordered_map<char, int> &letters, vector<bool> &usedNumbers, string s1, string s2, string s3)
{

    if (idx == unique.length())
    {
        int num1 = getNum(s1, letters);
        int num2 = getNum(s2, letters);
        int num3 = getNum(s3, letters);

        if (num1 + num2 == num3)
        {
            for (int i = 0; i < 26; i++)
            {
                char ch = 'a' + i;
                if (letters.find(ch) != letters.end())
                {
                    cout << ch << "-" << letters[ch] << " ";
                }
            }
            cout << endl;
        }

        return;
    }

    char ch = unique[idx];

    for (int i = 0; i <= 9; i++)
    {
        if (usedNumbers[i] == false)
        {
            letters[ch] = i;
            usedNumbers[i] = true;
            solution(unique, idx + 1, letters, usedNumbers, s1, s2, s3);
            usedNumbers[i] = false;
            letters[ch] = -1;
        }
    }
}

int main()
{
    string s1, s2, s3;

    cin >> s1;
    cin >> s2;
    cin >> s3;

    unordered_map<char, int> letters;
    string unique = "";

    for (int i = 0; i < s1.length(); i++)
    {
        if (letters.find(s1[i]) == letters.end())
            letters[s1[i]] = -1;
        unique += s1[i];
    }

    for (int i = 0; i < s2.length(); i++)
    {
        if (letters.find(s2[i]) == letters.end())
            letters[s2[i]] = -1;
        unique += s2[i];
    }

    for (int i = 0; i < s3.length(); i++)
    {
        if (letters.find(s3[i]) == letters.end())
            letters[s3[i]] = -1;
        unique += s3[i];
    }

    vector<bool> usedNumbers(10, false);

    solution(unique, 0, letters, usedNumbers, s1, s2, s3);
}
