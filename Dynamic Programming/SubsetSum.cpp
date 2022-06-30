/********************************************************************** PROBLEM **************************************************************************************/

/*

Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 

Example 1:

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
Output: 1 
Explanation: Here there exists a subset with
sum = 9, 4+3+2 = 9.

Example 2:

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 30
Output: 0 
Explanation: There is no subset with sum 30.

*/

/********************************************************************** BRUTE FORCE **************************************************************************************/


bool isSubsetSum_Helper(vector<int>arr, int sum, int i) {
        
        //if we have reached end of array and sum is 0 as well then return true else return false
        if(i == arr.size()) {
            if(sum == 0)
                return true;
            else return false;
        }
        
        //if sum has become 0 return true
        if(sum == 0)
            return true;
        
        //if current element less than or equal to sum then only consider including
        if(arr[i] <= sum)
            return isSubsetSum_Helper(arr, sum, i + 1) || 
                    isSubsetSum_Helper(arr, sum - arr[i], i + 1);
        else
            return isSubsetSum_Helper(arr, sum, i + 1);
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        
        return isSubsetSum_Helper(arr, sum, 0);
    }


/********************************************************************** MEMOIZATION **************************************************************************************/


bool isSubsetSum_Helper(vector<int>arr, int sum, int i, vector<vector<int>>& mem) {
        if(i == arr.size()) {
            if(sum == 0)
                return true;
            else return false;
        }
        
        if(sum == 0)
            return true;
        
        if(mem[i][sum] != -1)
            return mem[i][sum];
        
        if(arr[i] <= sum)
            mem[i][sum] = isSubsetSum_Helper(arr, sum, i + 1, mem) || 
                    isSubsetSum_Helper(arr, sum - arr[i], i + 1, mem);
        else
            mem[i][sum] = isSubsetSum_Helper(arr, sum, i + 1, mem);
            
        return mem[i][sum];
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
      
        vector<vector<int>> mem(arr.size() + 1, vector<int>(sum + 1, -1));
        return isSubsetSum_Helper(arr, sum, 0, mem);
    }


/********************************************************************** DP **************************************************************************************/


bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int m = arr.size() + 1;
        int n = sum + 1;
        vector<vector<bool>> dp(m, vector<bool>(n));
        
        //if required sum is 0 then any array can provide that
        for(int i = 0; i < m; i++) {
            dp[i][0] = true;
        }
        
        //if array is empty then it cannot cater to sum > 0
        for(int j = 1; j < n; j++) {
            dp[0][j] = false;
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                //check what is present at i - 1th row i.e when we are not including then whatever the value of i - 1th row is for
                //this particular sum will be taken into consideration 
                //check what is present at j - arr[i - 1]th column in i - 1th row i.e. check what the value of sum was when this element was not present
                //and only those before the ith element were present for the sum = sum - ith element
                if(arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[m - 1][n - 1];
    }

/********************************************************************** THE END **************************************************************************************/


