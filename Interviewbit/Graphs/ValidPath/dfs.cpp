
int directions[8][2] = {{1,1}, {1,-1}, {-1,1}, {-1,-1}, {0,-1}, {0,1}, {1,0}, {-1,0}};


bool dfs(vector<vector<int>>& rect, int i, int j, int A, int B) {
        
    if(i == A && j == B) {
        return true;
    }
    
    rect[i][j] = 1;
    
    for(int k = 0; k < 8; k++) {
        
        int x = i + directions[k][0];
        int y = j + directions[k][1];
        
        if(x >= 0 && y >= 0 && x <= A && y <= B && rect[x][y] == 0) {
            
            if(dfs(rect, x, y, A, B)) {
                return true;
            }
            
        }  
    }
    
    rect[i][j] = 0;
        
    return false;
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    
    vector<vector<int>> rect(A + 1, vector<int>(B + 1, 0));
    
    // mark all cells that lie in a circle as visited
    for(int i = 0; i <= A; i++) {
        for(int j = 0; j <= B; j++) {
            
            // travel each circle and find whether this cell is present in that circle
            for(int k = 0; k < C; k++) {
                if(sqrt(pow(E[k] - i, 2) + pow(F[k] - j, 2)) <= D) {
                    
                    // if it is present mark it as 1 and then break from circle loop 
                    // and move onto the next cell
                    rect[i][j] = 1;
                    break;
                }
            }
        }
    }
    
    // if starting and ending path is blocked we don't have a path 
    if(rect[0][0] == 1 || rect[A][B] == 1)
        return "NO";
    
    // perform dfs on the cells
    
    if(dfs(rect, 0, 0, A, B))
        return "YES";
    else 
        return "NO";
    
 
}
