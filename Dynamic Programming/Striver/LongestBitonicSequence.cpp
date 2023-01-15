/******************************************************************* QUESTION *******************************************************************************/

/*

Given an array of positive integers. Find the maximum length of Bitonic subsequence. 
A subsequence of array is called Bitonic if it is first strictly increasing, then strictly decreasing.
 

Example 1:

Input: nums = [1, 2, 5, 3, 2]
Output: 5
Explanation: The sequence {1, 2, 5} is
increasing and the sequence {3, 2} is 
decreasing so merging both we will get 
length 5.
Example 2:

Input: nums = [1, 11, 2, 10, 4, 5, 2, 1]
Output: 6
Explanation: The bitonic sequence 
{1, 2, 10, 4, 2, 1} has length 6.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function LongestBitonicSequence() which takes the array nums[] as input parameter and returns the maximum length of bitonic subsequence.
 

Expected Time Complexity: O(n2)
Expected Space Complexity: O(n)
 

Constraints:
1 ≤ length of array ≤ 103
1 ≤ arr[i] ≤ 106

*/

/******************************************************************* ANSWER *******************************************************************************/

class Solution{
	public:
	int LongestBitonicSequence(vector<int>arr)
	{
	    // code here
	    int n = arr.size();
	    vector<int> dp1(n, 1);
	    vector<int> dp2(n, 1);
	    
	    // lis in forward direction for increasing sequence
	    for(int i = 1; i < n; i++) {
	        for(int j = 0; j < i; j++) {
	            if(arr[j] < arr[i])
	                dp1[i] = max(dp1[i], dp1[j] + 1);
	        }
	    }
	    
	    // lis in backward direction for decreasing sequence
	    for(int i = n - 2; i >= 0; i--) {
	        for(int j = n - 1; j > i; j--) {
	            if(arr[j] < arr[i])
	                dp2[i] = max(dp2[i], dp2[j] + 1);
	        }
	    }
	    
	    int maxi = -1;
	    
	    // i is that point where the sequence takes a turn towards decreasing side
	    // as we move from 0 to n - 1 in both dp arrays
	    // they represent the size of sequences from front and back respectively hence 
	    // we add them and subtract 1 cause ith element will be counted twice
	    for(int i = 0; i < n; i++) {
	        maxi = max(maxi, dp1[i] + dp2[i] - 1);
	    }
	    
	    return maxi;
	    
	}
};
