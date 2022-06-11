#include <iostream>
using namespace std;

#include<vector>

vector<int>* getPath(int **edges, int n, int start, int end, bool *visited) {
    
    if(start == end){
        vector<int> *v = new vector<int>;
        v -> push_back(start);
        return v;
    }
    
    vector<int>* result = NULL;
    
    visited[start] = true;
    
    for(int i = 0; i < n; i++) {
        if(edges[start][i] == 1 && !visited[i]) {
                vector<int>* temp = getPath(edges, n, i, end, visited);
                
                if(temp != NULL) {
                    result = temp;
                    break;
                }
            }
        
    }
    
    if(result != NULL)
        result -> push_back(start);
    return result;
}

int main() {
    // Write your code here
    int n,e;
    cin >> n >> e;
    int** edges = new int*[n];
    for(int i = 0;i < n; i++)
    {
        edges[i] = new int[n];
        for(int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }

    }
    
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = false;

    }
    
    for(int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;

    }
    
    int v1,v2;
    cin >> v1 >> v2;

	vector<int> *v = getPath(edges, n, v1, v2, visited);

  	for(int i=0; i < v -> size(); i++) {
    	cout<<v -> at(i)<<" ";
    }
  
  delete [] visited;
  for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }

    delete[] edges;
}
