/******************************************************************* QUESTION *******************************************************************************/

/*

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1

*/

/******************************************************************* ANSWER *******************************************************************************/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        int sum = 0;

        // fill the first row and column with 1s where they are present 
        // because they can individually form only 1 square and add the count to sum
        for(int i = 1; i < m; i++) {
            dp[i][0] = matrix[i][0];
            sum += matrix[i][0];
        }

        for(int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
            sum += matrix[0][j];
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {

                // if the cell is 0 it cannot participate in making a square in any form
                if(matrix[i][j] == 0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                
                // each cell represents the number of squares it is present in hence
                // the count will be unique for every cell hence we add every cell's count
                sum += dp[i][j];
            }
        }

        return sum;
    }
};
