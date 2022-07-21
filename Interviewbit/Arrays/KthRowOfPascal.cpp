/********************************************************************** QUESTION **************************************************************************************/

/*

Problem Description
Given an index k, return the kth row of the Pascal's triangle.

Pascal's triangle: To generate A[C] in row R, sum up A'[C] and A'[C-1] from previous row R - 1.

Example:

Input : k = 3



Return : [1,3,3,1]

Note: k is 0 based. k = 0, corresponds to the row [1]. 

Note: Could you optimize your algorithm to use only O(k) extra space?

*/

/********************************************************************** ANSWER **************************************************************************************/

vector<int> Solution::getRow(int A) {
    vector<vector<int>> ans;
    
    ans.push_back({1});
    ans.push_back({1, 1});
        
    for(int i = 2; i <= A; i++) {
        vector<int> temp(i + 1, 1);
        
        for(int j = 1; j < i; j++) {
            temp[j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
        
        ans.push_back(temp);
    }
    
    return ans[A];
}
