/******************************************************************* QUESTION *******************************************************************************/

/*

There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

 

Example 1:


Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
Example 2:


Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2
Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.
 

Constraints:

1 <= n <= 105
1 <= connections.length <= min(n * (n - 1) / 2, 105)
connections[i].length == 2
0 <= ai, bi < n
ai != bi
There are no repeated connections.
No two computers are connected by more than one cable.

*/

/******************************************************************* MY ANSWER *******************************************************************************/

class Solution {
public:

    void dfs(vector<int>& visited, int node, vector<int> adj[]) {
        visited[node] = 1;
        for(auto it: adj[node]) {
            if(!visited[it])
                dfs(visited, it, adj);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n - 1)
            return -1;
        
        vector<int> adj[n];
        int components = 0;

        for(auto it: connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> visited(n, 0);
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(visited, i, adj);
                components++;
            }
        }
        
        return components - 1;
    }
};

/******************************************************************* STRIVER ANSWER *******************************************************************************/

class DisjointSet {
    public:
    vector<int> size, parent;

    DisjointSet(int n) {
        size.resize(n + 1);
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findPar(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int parent_u = findPar(u);
        int parent_v = findPar(v);

        if(parent_u == parent_v) return;
        
        if(size[parent_u] < size[parent_v]) {
            parent[u] = parent_v;
            size[v] += size[u];
        } else {
            parent[v] = parent_u;
            size[u] += size[v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        int countExtras = 0;
        DisjointSet ds(n);

        for(auto it: connections) {
            int u = it[0];
            int v = it[1];

            // if nodes belong to same component then that means there's an extra edge here
            if(ds.findPar(u) == ds.findPar(v))
                countExtras++;
            else
                ds.unionBySize(u, v);
        }

        int components = 0;

        // nodes whose parents are the nodes itself can be the seen as representatives for a component
        for(int i = 0; i < n; i++) {
            if(ds.parent[i] == i) components++;
        }

        // if extra edges are greater or equal to required edges then return answer
        // if it is less that means we do not have sufficient edges to connect all components 
        // hence return -1
        return (countExtras >= components - 1) ? components - 1 : -1;
    }
};
