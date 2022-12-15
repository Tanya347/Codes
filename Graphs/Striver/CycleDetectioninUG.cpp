/********************************************************************** QUESTION **************************************************************************************/

/*

Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 

Example 1:

Input:  
V = 5, E = 5
adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} 
Output: 1
Explanation: 

1->2->3->4->1 is a cycle.

Example 2:

Input: 
V = 4, E = 2
adj = {{}, {2}, {1, 3}, {2}}
Output: 0
Explanation: 

No cycle in the graph. 

Your Task:
You don't need to read or print anything. Your task is to complete the function isCycle() which takes V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the undirected graph contains any cycle or not, return 1 if a cycle is present else return 0.

NOTE: The adjacency list denotes the edges of the graph where edges[i] stores all other vertices to which ith vertex is connected.


Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)
 

Constraints:
1 ≤ V, E ≤ 105


*/

/********************************************************************** BFS **************************************************************************************/

class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int i, int j, int color, int initial) {
        if(i >= 0 && j >= 0 && i < image.size() && j < image[0].size() && image[i][j] == initial) {
            image[i][j] = color;
            dfs(image, i+1, j, color, initial);
            dfs(image, i, j+1, color, initial);
            dfs(image, i, j-1, color, initial);
            dfs(image, i-1, j, color, initial);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // DFS
        int initial = image[sr][sc];
        
        if(initial == color) return image;

        dfs(image, sr, sc, color, initial);
        return image;
    }
};

/********************************************************************** DFS **************************************************************************************/

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool dfs(vector<int> adj[], vector<pair<int, int>>& visited, int i) {
        
        bool ans = false;
        for(auto it:adj[i]) {
            if(!visited[it].first) {
                visited[it].first = 1;
                visited[it].second = i;
                
                // we should store answer rather than directly returning it as we are missing out 
                // on further iterations
                ans = dfs(adj, visited, it);
            }
            
            // same concept as bfs, if the node is visited and not the parent of i then it means there's
            // cycle
            else if(visited[i].second != it) {
                return true;
            }
                
        } 
        
        return ans;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<pair<int, int>> visited(V, {0, -1});
        
        
        for(int i = 0; i < V; i++) {
            if(!visited[i].first) {
                // mark very first element visited and perform dfs on it
                visited[i].first = 1;
                if(dfs(adj, visited, i))
                    return true;
            }
        }
        
        return false;
    }
};

