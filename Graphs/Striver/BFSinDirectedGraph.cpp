/********************************************************************** QUESTION **************************************************************************************/

/*

Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v and find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.

*/

/********************************************************************** ANSWER **************************************************************************************/

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        vector<bool> visited(V, false);
        
        queue<int> vertices;
        vertices.push(0);
        visited[0] = true;
        
        vector<int> bfs;
        
        while(!vertices.empty()) {
            
            // get topmost node
            int n = vertices.front();
            vertices.pop();
            bfs.push_back(n);
            
            // traverse elements for all neighbours
            for(auto it:adj[n]) {
                if(!visited[it]) {
                    visited[it] = true;
                    vertices.push(it);
                }
            }
        }
        
        return bfs;
    }
};
