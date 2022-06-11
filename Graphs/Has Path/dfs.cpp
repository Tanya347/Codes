#include <iostream>
using namespace std;

bool has_path(int **edges, int n, int sv, int v2, bool* visited) {
    if(sv == v2)
        return true;
    
    visited[sv] = true;
    
    for(int i = 0; i < n; i++) {
        if(i != sv && !visited[i] && edges[i][sv] == 1) {
            if(has_path(edges, n, i, v2, visited)) 
                return true;
        }
    }
    
    return false;
}

int main() {
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
    
    int v1, v2;
    cin>>v1>>v2;
    
    bool *visited = new bool[n];
    
    for(int i = 0; i < n; i++) {
        visited[i] = false;
    }
    
    if(has_path(edges, n, v1, v2, visited))
       cout<<"true";
    else
       cout<<"false";
    
    delete [] visited;
    
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }

    delete[] edges;
    
}
