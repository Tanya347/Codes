/*

LeetCode 1820. Maximum Number of Accepted Invitations


There are m boys and n girls in a class attending an upcoming party.


You are given an m x n integer matrix grid, where grid[i][j] equals 0 or 1. If grid[i][j] == 1, then that means the ith boy can invite the jth girl to the party. A boy can invite at most one girl, and a girl can accept at most one invitation from a boy.


Return the maximum possible number of accepted invitations.


Example 1:


Input: grid = [[1,1,1],
              [1,0,1],
              [0,0,1]]
Output: 3


  Explanation: The invitations are sent as follows:
  - The 1st boy invites the 2nd girl.
  - The 2nd boy invites the 1st girl.
  - The 3rd boy invites the 3rd girl.
Example 2:


Input: grid = [[1,0,1,0],
              [1,0,0,0],
              [0,0,1,0],
              [1,1,1,0]]
Output: 3


Explanation: The invitations are sent as follows:
-The 1st boy invites the 3rd girl.
-The 2nd boy invites the 1st girl.
-The 3rd boy invites no one.
-The 4th boy invites the 2nd girl.
Constraints:


grid.length == m

grid[i].length == n

1 <= m, n <= 200

grid[i][j] is either 0 or 1.

*/


// This is an example of Bipartite Matching where we try to divide the graph into two groups which don't have a common edge internally in each group

bool bipartiteMatch(const vector<vector<int>>& grid, int boy, vector<bool> visited, vector<int>& girls) {
  int m = grid.size();
  int n = grid[0].size();

  for(int girl = 0; girl < n; girl++) {
    if(!visited[girl] && grid[boy][girl]) {
      visited[girl] = true;
      // if the girl has already accepted invitation from a boy we try to shift her to another available boy
      if (girls[v] < 0 || bipartiteMatch(grid, girls[v], visited, girls)) {
        girls[v] = u;
        return true;
      }
    }
  }
  return false;
}

int maximumInvitations(vector<vector<int>>& grid) {

  int m = grid.size();
  int n = grid[0].size();
  vector<int> girls(n, -1);
  int matches = 0;

  for(int i = 0; i < m; i++) {
    vector<bool> visited(n, false);
    if (bipartiteMatch(grid, u, visited, girls)) {
      matches++;
    }
  }
  return matches;
}
