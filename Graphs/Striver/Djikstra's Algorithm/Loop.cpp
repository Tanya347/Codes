#include <iostream>
#include <climits>
using namespace std;

//function to find the vertex with minimum distance
int findMinVertex(bool* visited, int* dist, int n) {
    
    int minVertex = -1;
    for(int i = 0; i < n; i++) {
        if(!visited[i] && (minVertex == -1 || dist[i] < dist[minVertex]))
            minVertex = i;
    }
    
    return minVertex;
}

//function that finds min distance of all the vertices from the 0 vertex
void dijkstra(int** edges, int n, int e) {
    
    bool* visited = new bool[n];
    int* dist = new int[n];
    
    for(int i = 0; i < n; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
    }
    
    dist[0] = 0;
    
    for(int i = 0; i < n; i++) {
        
        int vertex = findMinVertex(visited, dist, n);
        visited[vertex] = true;
        
        for(int j = 0; j < n; j++) {
            if(edges[vertex][j] != 0 && !visited[j]) {
                //calculate distance of the neighbour from the chosen vertex 
                int distance = edges[vertex][j] + dist[vertex];
                if(distance < dist[j])
                    dist[j] = distance;
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        cout<<i<<" "<<dist[i]<<endl;
    }
    
}

int main() {
    // Write your code here
    
    int n, e;
    cin>>n>>e;
    
    int** edges = new int*[n]; 
    
    for(int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for(int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }
    
    for(int i = 0; i < e; i++) {
        int f, s, w;
        cin>>f>>s>>w;
        edges[f][s] = w;
        edges[s][f] = w;
    }
    
    dijkstra(edges, n, e);
    
    for(int i = 0; i < n; i++) {
        delete [] edges[i];
    }
    
    delete [] edges;
}
