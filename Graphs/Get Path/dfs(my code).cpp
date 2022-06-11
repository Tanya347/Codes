#include <iostream>
#include <vector>
using namespace std;

vector<int> getPath(int **edges, int n, int s, int e, bool* visited) {
    vector<int> ans;
    
	if(s == e) {
        ans.push_back(e);
        return ans;
    }
    
    visited[s] = true;
    
    for(int i = 0; i < n; i++) {
        if(!visited[i] && edges[i][s] == 1) {
            vector<int> temp = getPath(edges, n, i, e, visited);
            if(temp.size() != 0) {
                ans = temp;
                ans.push_back(s);
                return ans;
            }
        }
    }
        
    return ans;
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
    
    vector<int> ans = getPath(edges, n, v1, v2, visited);
    
    if(ans.size() != 0) {
        for(int i = 0; i < ans.size(); i++) 
        	cout<<ans[i]<<" ";
    }
    
    delete [] visited;
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }

    delete[] edges;
}
