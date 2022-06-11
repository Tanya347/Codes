#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int **edges, int n, bool *visited, int sv, vector<int>& temp)
{
    temp.push_back(sv);
    
    visited[sv] = true;

    for (int i = 0; i < n; i++)
    {
        if (i != sv && !visited[i] && edges[sv][i] == 1)
        {
            dfs(edges, n, visited, i, temp);
        }
    }
}

vector<vector<int>> dfs_connected(int **edges, int n, bool* visited)
{
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            vector<int> temp;
            dfs(edges, n, visited, i, temp);
            ans.push_back(temp);
        }
    }
    
    return ans;
}

int main()
{
    int n, e;
    cin >> n >> e;

    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int s, f;
        cin >> s >> f;
        edges[s][f] = 1;
        edges[f][s] = 1;
    }
    
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    vector<vector<int>> ans = dfs_connected(edges, n, visited);
    
    sort(ans.begin(), ans.end());
    
    for(int i = 0; i < ans.size(); i++) {
        
        sort(ans[i].begin(), ans[i].end());
        
        for(int j = 0; j < ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    delete[] visited;

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }

    delete[] edges;
}
