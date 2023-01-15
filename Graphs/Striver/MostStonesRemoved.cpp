/******************************************************************* QUESTION *******************************************************************************/

/*

On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

 

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.
Example 3:

Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it.
 

Constraints:

1 <= stones.length <= 1000
0 <= xi, yi <= 104
No two stones are at the same coordinate point.

*/

/******************************************************************* ANSWER *******************************************************************************/

// disjoint set data structure

class DisjointSet {
    vector<int> parent, size;
    public:
    
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
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
        
        if (parent_u == parent_v) return;
        
        if (size[parent_u] < size[parent_v]) {
            parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
        }
        
        else {
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;

        // find the dimensions of the matrix that we will form 
        for(auto it: stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        
        // we are representing the columns as columns + rows + 1 so that it doesn't clash with the rows in case they are same
        DisjointSet ds(maxCol + maxRow + 1);
      
        // this map is just to store the nodes that are present in the graph we are creating so that we can trace the number of components
        unordered_map<int, int> stoneNodes;

        for(auto it: stones) {
            int row = it[0];
            int col = it[1] + maxRow + 1; // adding maxRow + 1 to give the column a unique identity
            ds.unionBySize(row, col); // treating rows and columns as nodes
            stoneNodes[row] = 1;
            stoneNodes[col] = 1;
        }

        // finding the number of components
        int components = 0;
        for(auto it: stoneNodes) {
            if(ds.findPar(it.first) == it.first)
                components++;
        }
        
        // suppose there x1, x2, x3 ... xk nodes in the respective k components, so the number of stones to be removed will be x1 - 1, x2 - 1 and so on
        // now clubbing terms together (x1 + x2 + x3 + x4 ... + xk) - (1 + 1 + 1 .... k times)
        // (x1 + x2 + x3 + x4 ... + xk) = n i.e. total number of stones
        // (1 + 1 + 1 .... k times) = k i.e. total number of components
        return n - components;
    }
};
