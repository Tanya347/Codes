/******************************************************************* QUESTION *******************************************************************************/

/*

There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

 

Example 1:


Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
Example 2:

Input: n = 2, connections = [[0,1]]
Output: [[0,1]]
 

Constraints:

2 <= n <= 105
n - 1 <= connections.length <= 105
0 <= ai, bi <= n - 1
ai != bi
There are no repeated connections.

*/

/******************************************************************* ANSWER *******************************************************************************/

class Solution {

    int time = 1;

    void dfs(int node, int parent, vector<int> adj[], vector<int>& visited, vector<int>& timeIn, vector<int>& lowTime, vector<vector<int>>& bridges) {

        visited[node] = 1;

        // initially the time taken to reach the node is same as lowest time 
        // as we haven't explored its neighbours yet
        timeIn[node] = lowTime[node] = time;
        time++;

        for(auto it: adj[node]) {

            // prevents us from checking for parent node unnecessarily
            if(it == parent) continue;

            if(!visited[it]) {
                dfs(it, node, adj, visited, timeIn, lowTime, bridges);

                // if the adjacent has lower time make it the low for this node
                lowTime[node] = min(lowTime[node], lowTime[it]);


                // if the adjacent node has higher lowest time then it means the two nodes
                // are part of a bridge because there's no other way to reach the 
                // adjacent node without this edge
                if(lowTime[it] > timeIn[node])
                    bridges.push_back({node, it});
            }
            else {
                lowTime[node] = min(lowTime[node], lowTime[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<int> adj[n];

        for(auto it: connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> visited(n, 0);
        vector<int> timeIn(n);
        vector<int> lowTime(n);
        vector<vector<int>> bridges;

        dfs(0, -1, adj, visited, timeIn, lowTime, bridges);
        return bridges;
    }
};
