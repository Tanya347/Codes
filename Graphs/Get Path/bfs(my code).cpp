#include <queue>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> getPath(int **edges, int n, int v1, int v2, bool* visited) {
    
    vector<int> ans;
     
    queue<int> vertices;
    vertices.push(v1);
    
    visited[v1] = true;
    
    unordered_map <int, int> parent;
    
    int flag = 0;
    
    while(!vertices.empty()) {
        
        int v = vertices.front();
        vertices.pop();
        
        if(v == v2) {
            flag = 1;
            break;
        }
        
        for(int i = 0; i < n; i++) {
            if(!visited[i] && edges[v][i] == 1) {
                visited[i] = true;
                parent[i] = v;
                vertices.push(i);
            }
        }
    }
    
    if(flag) {
        int current = v2;
        ans.push_back(v2);
        while(current != v1) {
            current = parent[current];
            ans.push_back(current);
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
    
    for (int i = 0; i < n; i++) { 
		delete [] edges[i]; 
	} 
    
    delete [] edges; 
    
}
