/********************************************************************** QUESTION **************************************************************************************/


/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Example 2:

Input: nums = [1]
Output: 1

Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23

*/


/********************************************************************** APPROACH 1 **************************************************************************************/


int maxSubArray(vector<int>& nums) {
        //initially take maxSum as -infinite and sum as 0
        int maxSum = INT_MIN;
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            //if sum becomes greater than maxSum update it 
            if(sum > maxSum) maxSum = sum;
            //if sum becomes negative that means we don't need this subarray and make it 0 again for fresh subarray
            if(sum < 0) sum = 0;
        }
        
        //don't worry for the case where all are negative since maxSum will store the required value :)
        return maxSum;
    }


/********************************************************************** APPROACH 2 **************************************************************************************/


//Kadane's Algorithm
    
    int maxSubArray(vector<int>& nums) {
        
        int currSum = nums[0], maxSum = nums[0];
        
        //taken first element assuming size of current subarray to be 1
        for(int i = 1; i < nums.size(); i++) {
            
            //check whether adding the current element adds any value to the subarray being carried so far
            //and also check whether current element itself is bigger than currSum
            
            //basically seeing whether we should continue with previous subarray or move forward with the
            //element
            currSum = max(currSum + nums[i], nums[i]);
            
            //now after getting the optimal curr sum compare it with the maximum sum we have encountered
            //so far
            maxSum = max(currSum, maxSum);
        }
        
        
        return maxSum;
    }


/********************************************************************** END **************************************************************************************/
