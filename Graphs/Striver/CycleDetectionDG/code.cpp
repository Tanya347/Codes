/********************************************************************** QUESTION **************************************************************************************/

/*

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.


Example 1:

Input:



Output: 1
Explanation: 3 -> 3 is a cycle


Example 2:

Input:


Output: 0
Explanation: no cycle in the graph


Your task:
You dont need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.


Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)


Constraints:
1 ≤ V, E ≤ 105


*/

/********************************************************************** ANSWER **************************************************************************************/

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool checkCycle(vector<int> adj[], vector<int>& visited, vector<int>& curr_visit, int sv) {
        
        // mark sv visited in both arrays as it is visited once and also visited in current call
        visited[sv] = curr_visit[sv] = 1;
        
        for(auto it:adj[sv]) {
            
            // if not visited then call dfs on it
            if(!visited[it]) {
                if(checkCycle(adj, visited, curr_visit, it))
                    return true;
            }
            
            // if it is visited once check whether it has also been visited in the current call or not
            // if it has been visited once before in the current call that means cycle exists
            else if(curr_visit[it])
                return true;
        }
        
        
        // mark unvisited in current call as we backtrack
        curr_visit[sv] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        
        // maintain two arrays
        
        // first one is for overall visit
        vector<int> visited(V, 0);
        
        // second one is visit in current dfs call
        vector<int> curr_visit(V, 0);
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(checkCycle(adj, visited, curr_visit, i))
                    return true;
            }
        }
        
        return false;
    }
};
