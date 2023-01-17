/******************************************************************* QUESTION *******************************************************************************/

/*

Problem Statement: You are given an n, m which means the row and column of the 2D matrix, and an array of size k denoting the number of operations. Matrix elements are 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator(s) and each operator has two integers A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many islands are there in the matrix after each operation. You need to return an array of size k.

Sample Input 1:
2
3 3
4
0 0
0 1
1 2
2 1
4 5
4
1 1
0 1
3 3
3 4
Sample Output 1:
1 1 2 3
1 1 2 2
Explanation Of Sample Output 1:
In test case 1, 

0.  000
    000
    000

1.  100
    000
    000

2.  110
    000
    000

 3. 110
    001
    000

 4. 110
    001
    100

So, the answer is 1, 1, 2, 3.

In test case 2,

0.  00000
    00000
    00000
    00000

1.  00000
    01000
    00000
    00000

2.  01000
    01000
    00000
    00000

 3. 01000
    01000
    00000
    00010

 4. 01000
    01000
    00000
    00011

So, the answer is 1, 1, 2, 2.

*/

/******************************************************************* ANSWER *******************************************************************************/


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

    void unionSize(int u, int v) {
        int parent_u = findPar(u);
        int parent_v = findPar(v);

        if(parent_u == parent_v)
            return;

        if(size[parent_u] < size[parent_v]) {
            parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
        } else {
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
        }
    }
};

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){
    
    // creating disjoint data structure of size m*n as m*n nodes are possible in the graph
    DisjointSet ds(n*m);
    
    // to mark visited and reduce time complexity
    vector<vector<int>> visited(n, vector<int>(m, 0));
    
    // keeps a count of number of current islands
    int counter = 0;
    
    // stores the number of islands after every query
    vector<int> ans;
    
    for(int i = 0; i < q.size(); i++) {
        
        // get the row and column for current query
        int x = q[i][0];
        int y = q[i][1];
        
        // if this node has already been marked we can simply store the current number  
        if(visited[x][y]) {
            ans.push_back(counter);
            continue;
        }
            
        // mark visited and increase counter as we are assuming a new node is introduced which
        // may or may not get connected
        visited[x][y] = 1;
        counter++;
            
        // traverse all the neighbours
        int arr[4][2] = {{-1, 0}, {1, 0}, {0, 1},{0, -1}};
            
        for(int j = 0; j < 4; j++) {
            int row = x + arr[j][0];
            int col = y + arr[j][1];
                
            // check for validity of the indices
            if(row >= 0 && col >= 0 && row < n && col < m) {
                if(visited[row][col]) {
                    // calculate the number according to the rows and columns for disjoint data structure
                    int value_i = x*m + y;
                    int value_j = row*m + col;
                        
                    // if nodes aren't connected then connect them and decrease counter
                    if(ds.findPar(value_i) != ds.findPar(value_j)) {
                        counter--;
                        ds.unionSize(value_i, value_j);
                    }
                }
            }
        }
            
        ans.push_back(counter);
      
    }
    
    return ans;
}
