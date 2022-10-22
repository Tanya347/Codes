/********************************************************************** QUESTION **************************************************************************************/

/*
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

Example 1:

Input:
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}
Output:
1
Explanation:
grid[][] = {{1, 1, 0, 0, 0}, 
            {1, 1, 0, 0, 0}, 
            {0, 0, 0, 1, 1}, 
            {0, 0, 0, 1, 1}}
Same colored islands are equal.
We have 2 equal islands, so we 
have only 1 distinct island.

Example 2:

Input:
grid[][] = {{1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1}}
Output:
3
Explanation:
grid[][] = {{1, 1, 0, 1, 1}, 
            {1, 0, 0, 0, 0}, 
            {0, 0, 0, 0, 1}, 
            {1, 1, 0, 1, 1}}
Same colored islands are equal.
We have 4 islands, but 2 of them
are equal, So we have 3 distinct islands.

Your Task:

You don't need to read or print anything. Your task is to complete the function countDistinctIslands() which takes the grid as an input parameter and returns the total number of distinct islands.

Expected Time Complexity: O(n * m)
Expected Space Complexity: O(n * m)

Constraints:
1 ≤ n, m ≤ 500
grid[i][j] == 0 or grid[i][j] == 1
*/

/********************************************************************** SOLUTION **************************************************************************************/


//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool check(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] != 1)
            return false; 
        return true;
    }
    
    void dfs(vector<vector<int>>& grid, string &str, int i, int j) {
        
        grid[i][j] = 0;
        
        if(check(grid, i + 1, j)) {
            str += "d";
            dfs(grid, str, i + 1, j);
        }
        
        if(check(grid, i - 1, j)) {
            str += "u";
            dfs(grid, str, i - 1, j);
        }
        
        if(check(grid, i, j + 1)) {
            str += "r";
            dfs(grid, str, i, j + 1);
        }
        
        if(check(grid, i, j - 1)) {
            str += "l";
            dfs(grid, str, i, j - 1);
        }
        
        str += "z";
        
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        
        unordered_map<string, int> hash;
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                
                if(grid[i][j] == 1) {
                    string str = "x";
                    dfs(grid, str, i, j);
                    if(hash.find(str) == hash.end())
                        hash[str] = 1;
                }
            }
        }
        
        return hash.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
