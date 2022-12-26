/******************************************************************* QUESTION *******************************************************************************/

/*

Given a Directed Acyclic Graph of N vertices from 0 to N-1 and a 2D Integer array(or vector) edges[ ][ ] of length M, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i, 0<=i

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.

 

Example:

Input:
n = 6, m= 7
edge=[[0,1,2],[0,4,1],[4,5,4]
,[4,2,2],[1,2,3],[2,3,6],[5,3,1]]

Output:
0 2 3 6 1 5
 

Your Task:

You don't need to print or input anything. Complete the function shortest path() which takes an integer N as number of vertices, an integer M as number of edges and a 2D Integer array(or vector) edges as the input parameters and returns an integer array(or vector), denoting the list of distance from src to all nodes.

 

Constraint:

1 <= n,m <= 100
0 <= edgei,0,edgei,1 < n
 
 

Expected Time Complexity: O(N+E), where N is the number of nodes and E is edges

Expected Space Complexity: O(N)

*/

/******************************************************************* ANSWER *******************************************************************************/

class Solution {
  public:
  
    void dfs(int N, vector<pair<int, int>> adj[], stack<int>& st, vector<int>& vis, int n) {
        
        vis[n] = 1;
        
        for(auto it: adj[n]) {
            if(!vis[it.first])
            dfs(N, adj, st, vis, it.first);
        }
        
        st.push(n);
    }
  
    stack<int> topoSort(int N, vector<pair<int, int>> adj[]) {
        
        stack<int> st;
        vector<int> vis(N, 0);
        
        for(int i = 0; i < N; i++) {
            if(!vis[i])
                dfs(N, adj, st, vis, i);
        }
        
        return st;
    }
  
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        
        vector<pair<int, int>> adj[N];
        
        for(int i = 0; i < M; i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        
        stack<int> st = topoSort(N, adj);
        
        vector<int> dist(N, 1e9);
        
        dist[0] = 0;
        
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            
            for(auto it: adj[node]) {
                if(dist[node] + it.second < dist[it.first]) 
                    dist[it.first] = dist[node] + it.second;
            }
        }
        
        vector<int> ans(N, -1);
        for(int i = 0; i < N; i++) {
            if(dist[i] != 1e9)
            ans[i] = dist[i];
        }
        
        return ans;
    }
};

