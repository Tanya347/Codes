/******************************************************************* QUESTION *******************************************************************************/

/*

You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

 

Example 1:


Input: grid = [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.
Example 2:


Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation: The final route is shown.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 50
0 <= grid[i][j] < n2
Each value grid[i][j] is unique.

*/

/******************************************************************* UNION *******************************************************************************/


class DisjointSet {

    vector<int> rank, parent;
    
    public:
    DisjointSet(int n) {

        rank.resize(n + 1, 0);
        parent.resize(n + 1);

        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findPar(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }

    void UnionByRank(int u, int v) {
        
        int parent_u = findPar(u);
        int parent_v = findPar(v);

        if(parent_u == parent_v)
            return;
        
        else if(rank[parent_u] < rank[parent_v]) 
            parent[parent_u] = parent_v;
        
        else if(rank[parent_v] < rank[parent_u]) 
            parent[parent_v] = parent_u;
        
        else {
            parent[parent_u] = parent_v;
            rank[parent_u]++;
        }
    }

    bool isConnected(int u, int v) {
        return findPar(u) == findPar(v);
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();
        DisjointSet ds(n*n);
        int time = 0;

        while(!ds.isConnected(0, n*n - 1)) {

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(grid[i][j] > time)
                        continue;

                    // if current elevation is less than equal to time
                    // then we can connect the right and down node if they are also less than
                    // equal to time

                    if(i < n - 1 && grid[i + 1][j] <= time)
                        ds.UnionByRank(i*n + j, (i + 1)*n + j);

                    if(j < n - 1 && grid[i][j + 1] <= time)
                        ds.UnionByRank(i*n + j, i*n + j + 1);
                }
            }

            time += 1;
        }

        // when n*nth node got connected time must've been the actual time but during that
        // while loop we increment time again and then next time we find that 0 and n*nth cell
        // are connected hence time - 1
        return time == 0? 0 : time - 1;
    }
};

/******************************************************************* DJIKSTRA *******************************************************************************/

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        int n = grid.size();

        vector<vector<int>> minHeight(n, vector<int>(n, 1e9));

        pq.push({grid[0][0], {0, 0}});
        minHeight[0][0] = grid[0][0];

        while(!pq.empty()) {
            
            int height = pq.top().first;
            pair<int, int> cell = pq.top().second;
            pq.pop();

            if(cell.first == n - 1 && cell.second == n - 1)
                return height;
            
            int arr[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

            for(int i = 0; i < 4; i++) {

                int x = cell.first + arr[i][0];
                int y = cell.second + arr[i][1];

                if(x >= 0 && y >= 0 && x < n && y < n) {

                    // find max so far
                    int h = max(grid[x][y], height);

                    // if better than previously stored heights
                    if(h < minHeight[x][y]) {
                        minHeight[x][y] = h;
                        pq.push({h, {x, y}});
                    }

                }
            }
        }

        return 0;
    }
};
