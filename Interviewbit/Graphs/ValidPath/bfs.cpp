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

    

    // if(dfs(rect, 0, 0))

    //     return "YES";

    // else 

    //     return "NO";

    

    //bfs

    

    queue<pair<int, int>> q;

    q.push({0, 0});

    rect[0][0] = 1;

    

    while(!q.empty()) {

        int x = q.front().first;

        int y = q.front().second;

        q.pop();

        

        if(x == A && y == B) {

            return "YES";

        }

        

        int directions[8][2] = {{1,1}, {1,-1}, {-1,1}, {-1,-1}, {0,-1}, {0,1}, {1,0}, {-1,0}};

        

        for(int i = 0; i < 8; i++) {

            int newX = directions[i][0] + x;

            int newY = directions[i][1] + y;

            

            if(newX >= 0 && newY >= 0 && newX <= A && newY <= B && rect[newX][newY] == 0) {

                rect[newX][newY] = 1;

                q.push({newX, newY});

            }

        }

    }

    

    return "NO";
}
