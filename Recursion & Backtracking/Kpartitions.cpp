#include <iostream>
#include <vector>
using namespace std;

int count = 0;

void Kpartitions(vector<vector<int>> &ans, int n, int k, int i, int no_parts)
{

    if (i > n)
    {
        if (no_parts == k)
        {

            count++;
            cout << count << ".";

            for (int x = 0; x < ans.size(); x++)
            {
                cout << "[";
                for (int y = 0; y < ans[x].size(); y++)
                {
                    if (y == ans[x].size() - 1)
                        cout << ans[x][y];
                    else
                        cout << ans[x][y] << ", ";
                }
                cout << "] ";
            }
            cout << endl;
        }
        return;
    }

    for (int j = 0; j < ans.size(); j++)
    {
        if (ans[j].size() > 0)
        {
            ans[j].push_back(i);
            Kpartitions(ans, n, k, i + 1, no_parts);
            ans[j].pop_back();
        }
        else
        {
            ans[j].push_back(i);
            Kpartitions(ans, n, k, i + 1, no_parts + 1);
            ans[j].pop_back();
            break;
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> ans(k);
    Kpartitions(ans, n, k, 1, 0);
}
