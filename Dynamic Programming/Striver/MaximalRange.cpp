/******************************************************************* QUESTION *******************************************************************************/

/*

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1
 

Constraints:

rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.

*/

/******************************************************************* ANSWER *******************************************************************************/

class Solution {
public:

    int maxAreaFunction(vector<int> heights) {
        int n = heights.size();
        vector<int> leftSmall(n), rightSmall(n);
        stack<int> st;

        // find the smaller elements on the left of each bar
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if(st.empty())
                leftSmall[i] = 0;
            else
            // we need to find the upper limit of the bar
                leftSmall[i] = st.top() + 1;
            
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // find the smaller elements on the right of each bar
        for(int j = n - 1; j >= 0; j--) {
            while(!st.empty() && heights[st.top()] >= heights[j])
                st.pop();
            
            if(st.empty())
                rightSmall[j] = n - 1;
            else
            // we need to find the lower limit of the bar
                rightSmall[j] = st.top() - 1;
            
            st.push(j);
        }

        int maxArea = 0;
        
        for(int i = 0; i < n; i++) {
            
            // subtracting indices of the first and last bar will give 1 less than
            // the actual length hence we need to add 1
            int area = (rightSmall[i] - leftSmall[i] + 1)*heights[i];
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        int maxArea = 0;
        vector<int> hist(n, 0);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1')
                    hist[j]++;
                else
                    hist[j] = 0;
            }
            int area = maxAreaFunction(hist);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
