#include <iostream>
#include <queue>
using namespace std;

void bfs(int **edges, int n, bool *visited, int sv)
{

    queue<int> vertices;
    visited[sv] = true;
    vertices.push(sv);

    while (!vertices.empty())
    {
        int v = vertices.front();
        vertices.pop();

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

int main()
{
    // Write your code here
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
    
    bfs(edges, n, visited, 0);
    
    bool isConnected = true;
    
    for(int i = 0; i < n; i++) {
        if(visited[i] == false) {
            isConnected = false;
            cout<<"false";
            break;
        }
    }
    
    if(isConnected)
    cout<<"true";
  
    delete [] visited;
  
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }

    delete[] edges;
}
