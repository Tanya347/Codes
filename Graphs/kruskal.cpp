#include <iostream>
#include <algorithm>
using namespace std;

//class edge that maintains all three properties of the edge
class edge {
    public:
    int s;
    int d;
    int w;
};

//comparator function to sort the array according to increasing order of weights
bool comparator(edge e1, edge e2) {
    return e1.w < e2.w;
}

//function that finds the parent and checks
int return_parent(int* parent, int v) {
    while(parent[v] != v)
        v = parent[v];
    return v;
}


//function that populates output array using kruskal's algorithm
void kruskal(edge *edges, int n, int e, edge* output) {
    
    int *parent = new int[n];
    
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }
    
    int count = 0, i = 0;
    
    while(count != n - 1) {
        edge currentEdge = edges[i];
        int v1_parent = return_parent(parent, currentEdge.s);
        int v2_parent = return_parent(parent, currentEdge.d);
        
        //if parents are not equal then assign the output array's count index with the current edge and make the parent of the 
        //first vertex as the parent of the second vertex
        if(v1_parent != v2_parent) {
            output[count] = currentEdge;
            count++;
            parent[v1_parent] = v2_parent;
        }
        
        i++;
    }
}

int main() {
    // Write your code here
    
    //Taking input
    int n, e;
    cin>>n>>e;
    
    edge *edges = new edge[e];
    
    for(int i = 0; i < e; i++) {
        int a, b, c;
        cin>>a>>b>>c;
        
        edges[i].s = a;
        edges[i].d = b;
        edges[i].w = c;
    }
    
    //Output array
    edge *output = new edge[n - 1];
    
    //Sort the array according to weights in increasing order
    sort(edges, edges + e, comparator);
    
    kruskal(edges, n, e, output);
    
    
    for(int i = 0; i < n - 1; i++) {
        cout<<min(output[i].s, output[i].d)<<" "<<max(output[i].s, output[i].d)<<" "<<output[i].w<<endl;
    }
}
