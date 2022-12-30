/******************************************************************* QUESTION *******************************************************************************/

/*

Given a weighted, directed and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
Note: If the Graph contains a negative cycle then return an array consisting of only -1.

Example 1:

Input:

E = [[0,1,9]]
S = 0
Output:
0 9
Explanation:
Shortest distance of all nodes from
source is printed.
Example 2:

Input:

E = [[0,1,5],[1,0,3],[1,2,-1],[2,0,1]]
S = 2
Output:
1 6 0
Explanation:
For nodes 2 to 0, we can follow the path-
2-0. This has a distance of 1.
For nodes 2 to 1, we cam follow the path-
2-0-1, which has a distance of 1+5 = 6,
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function bellman_ford( ) which takes a number of vertices V and an E-sized list of lists of three integers where the three integers are u,v, and w; denoting there's an edge from u to v, which has a weight of w and source node S as input parameters and returns a list of integers where the ith integer denotes the distance of an ith node from the source node.

If some node isn't possible to visit, then its distance should be 100000000(1e8). Also, If the Graph contains a negative cycle then return an array consisting of only -1.

 

Expected Time Complexity: O(V*E).
Expected Auxiliary Space: O(V).

 

Constraints:
1 ≤ V ≤ 500
1 ≤ E ≤ V*(V-1)
-1000 ≤ adj[i][j] ≤ 1000
0 ≤ S < V

*/

/******************************************************************* ANSWER *******************************************************************************/

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        
        // TC = V X E
        
        // Relax the nodes V - 1 times
        for(int i = 0; i < V-1; i++) {
            for(auto it: edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                
                if(dist[u] + wt < dist[v])
                    dist[v] = dist[u] + wt;
            }
        }
        
        // nth relaxation to check negative cycle
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            // if distance has already been updated and still relaxes the node
            // that means there's a cycle
            if(dist[u] != 1e8 && dist[u] + wt < dist[v])
                return {-1};
        }
        
        return dist;
            
    }
};

/******************************************************************* EXPLANATION *******************************************************************************/

- Relaxation means : if(dist[u] + wt < dist[v]) dist[v] = dist[u] + wt;
- We relax V - 1 times because consider a graph like 1 -> 2 -> 3 -> 4 -> 5 with unit weights, now in every iteration only one node gets update because only source
node has distance marked in distance array. Hence we need to run the iterations V - 1 times
- Now after the V - 1 iterations the graph should be in optimal state, but if it still performs relaxations on Nth iteration that means it contains a negative cycle
- To detect a negative cycle we perform relaxtion on nodes one more time and check if the distance of nodes is not infinite and it is still relaxing its neighbouring 
nodes, then we simply return -1

