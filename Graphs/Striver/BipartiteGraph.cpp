/********************************************************************** QUESTION **************************************************************************************/

/*

There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

    There are no self-edges (graph[u] does not contain u).
    There are no parallel edges (graph[u] does not contain duplicate values).
    If v is in graph[u], then u is in graph[v] (the graph is undirected).
    The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.

A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.

 

Example 1:

Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.

Example 2:

Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true
Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.

 

Constraints:

    graph.length == n
    1 <= n <= 100
    0 <= graph[u].length < n
    0 <= graph[u][i] <= n - 1
    graph[u] does not contain u.
    All the values of graph[u] are unique.
    If graph[u] contains v, then graph[v] contains u.



*/

/********************************************************************** EXPLANATION **************************************************************************************/

- The explanation for leetcode is kinda complex. What it basically says is that in the two sets each node in every set should be connected to one node in the other set. 
- Each and every edge should have one node in one set and one node in the other set
- It can also be put this way that connections only between the set is allowed and not within a set

Now a more easier way of putting it is that a bipartite graph is the one where it can be colored with two colors, with no adjacent nodes with same color. 
    Any linear graph with no cycle is always a bipartite graph. With a cycle, any graph with an even cycle length can also be a bipartite graph. 
    So, any graph with an odd cycle length can never be a bipartite graph.
    
/********************************************************************** APPROACH **************************************************************************************/

- Perform normal dfs and bfs
- Just ensure that no two adjacent nodes have the same color
- If two adjacent nodes with same color are detected return false
    
/********************************************************************** BFS **************************************************************************************/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        queue<int> q;

        for(int i = 0; i < V; i++) {
            if(color[i] < 0) {
                color[i] = 0;
                q.push(i);

                while(!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for(auto it: graph[node]) {
                        if(color[it] < 0) {
                            color[it] = !color[node];
                            q.push(it);
                        } else if(color[it] == color[node])
                            return false;
                    }
                }
            }
        }

        return true;
    }
};

/********************************************************************** DFS **************************************************************************************/

class Solution {
public:

    bool dfs(vector<vector<int>>& graph, vector<int>& color, int node, int col) {

        color[node] = col;
        
        for(auto it: graph[node]) {
            if(color[it] < 0) {
                if(!dfs(graph, color, it, !col))
                    return false;
            } else {
                if(color[node] == color[it])
                    return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int V = graph.size();
        vector<int> color(V, -1);

        for(int i = 0; i < V; i++) {
            if(color[i] < 0) {
                if(!dfs(graph, color, i, 0))
                    return false;
            }
        }

        return true;
    }
};
