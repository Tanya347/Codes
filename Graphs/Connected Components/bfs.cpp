#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void bfs(int **edges, int n, bool *visited, int sv, vector<int>& temp)
{
    queue<int> vertices;
    visited[sv] = true;
    vertices.push(sv);

    while (!vertices.empty())
    {
        int v = vertices.front();
        vertices.pop();
        temp.push_back(v);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && edges[v][i] == 1 && i != sv)
            {
                visited[i] = true;
                vertices.push(i);
            }
        }
    }
}

vector<vector<int>> bfs_connected(int **edges, int n, bool* visited)
{
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            vector<int> temp;
            bfs(edges, n, visited, i, temp);
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

    vector<vector<int>> ans = bfs_connected(edges, n, visited);
    
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
