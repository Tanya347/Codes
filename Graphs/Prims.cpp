#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

//find minimun vertex

int findMinVertex(vector<int> weights, vector<bool> visited, int n) {
    
    int minVertex = -1;
    //if vertex is not visited and weight of is minimum
    for(int i = 0; i < n; i++) {
        
        //we are keeping the -1 condition for those cases where the array elements ahead have not been visited and contain
        //INT_MAX, it is basically for getting the very first vertex that has not been visited. If there exist any further
        //vertices that may have populated weights we use the second condition and find the minimum most
        if(!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex])) {
            minVertex = i;
        }
    }

    return minVertex;
}

void prims(int **edges, int n, int e) {
    
    //array to mark visited vertices
    vector<bool> visited(n, false);
    
    //weights array that stores minimum weight of a given vertex
    vector<int> weights(n, INT_MAX);
    
    //array that stores the parent of the vertex we chose
    vector<int> parent(n);
    
    //first vertex that gets selected contains no parent, hence -1 and weight 0 so that it gets selected by minvertex function
    weights[0] = 0;
    parent[0] = -1;
    
    int count = 0;
    
    while(count != n - 1) {
        
        int i = findMinVertex(weights, visited, n);
        
        visited[i] = true;
        
        //checking all the neighbouring vertices of the current selected vertex to find the path with minimum weight
        for(int j = 0; j < n; j++) {
            if(!visited[j] && edges[i][j] > 0) {
                if(edges[i][j] < weights[j]) {
                    weights[j] = edges[i][j];
                    parent[j] = i;
                }
            }
        }
        
        count++;
    }
    
    for(int i = 1; i < n; i++) {
        cout<<min(parent[i], i)<<" "<<max(parent[i], i)<<" "<<weights[i]<<endl;
    }
}

int main() {
    // Write your code here
    
    //Taking input
    int n, e;
    cin >> n >> e;
    int** edges = new int*[n];
    for(int  i = 0; i < n; i++) {
        edges[i] = new int[n];
        for(int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }
    
    for(int i = 0; i < e; i++) {
        int f, s, weight;
        cin >> f >> s >> weight;
        edges[f][s] = weight;
        edges[s][f] = weight;
    }
    
    //prims function that uses prims algorithm to populate the output array
    prims(edges, n, e);
    
}
