/************************************************* QUESTION *****************************************************************************/

It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with each other on the cake. Given the size of cake N and the cake, can you find the count of '1's in the biggest piece of '1's for Gary ?
Input Format :
The first line of input contains an integer, that denotes the value of N. 
Each of the following N lines contain N space separated integers.
Output Format :
Print the count of '1's in the biggest piece of '1's, according to the description in the task.
Constraints :
1 <= N <= 1000
Time Limit: 1 sec
Sample Input 1:
2
1 1
0 1
Sample Output 1:
3

/************************************************* ANSWER *****************************************************************************/


int dfs(vector<vector<int>> &cake, int i, int j, int n) {
    if(i < 0 || j < 0 || i >= n || j >= n || cake[i][j] != 1)
        return 0;

    int count = 0;
    int arr[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    cake[i][j] = -1;
    
    for(int k = 0; k < 4; k++) {
        int x = i + arr[k][0];
        int y = j + arr[k][1];
        count += dfs(cake, x, y, n);
    } 

    return 1 + count;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    // Write your code here

    int maxpiece = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(cake[i][j] == 1)
                maxpiece = max(maxpiece, dfs(cake, i, j, n));
        }
    }

    return maxpiece;
}
