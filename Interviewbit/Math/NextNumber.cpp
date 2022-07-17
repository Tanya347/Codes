/********************************************************************** QUESTION **************************************************************************************/

/*

Problem Description

Given a number A in a form of string.

You have to find the smallest number that has same set of digits as A and is greater than A.

If A is the greatest possible number with its set of digits, then return -1.



Problem Constraints

 1 <= A <= 10100000

 A doesn't contain leading zeroes.



Input Format

First and only argument is an numeric string denoting the number A.


Output Format

Return a string denoting the smallest number greater than A with same set of digits , if A is the largest possible then return -1.


Example Input

Input 1:

 A = "218765"

Input 2:

 A = "4321"



Example Output

Output 1:

 "251678"

Output 2:

 "-1"



Example Explanation

Explanation 1:

 The smallest number greater then 218765 with same set of digits is 251678.

Explanation 2:

 The given number is the largest possible number with given set of digits so we will return -1.


*/

/********************************************************************** ANSWER **************************************************************************************/

string Solution::solve(string nums) {
    int i = nums.size() - 2;
    
    // trying to find the element which is lesser than the ones on its right
    while(i >= 0 && nums[i] >= nums[i + 1]) i--;
    
    if(i >= 0) {
        int j = nums.size() - 1;
        
        // we will try to find the element just greater then the element at i
        while(j >= 0 && nums[j] <= nums[i]) j--;
        
        //swap element at i and j
        swap(nums[i], nums[j]);
        
        // now in order to ensure that it is the shortest element greater than A
        // we need to sort the elements present after A 
        sort(nums.begin() + i + 1, nums.end());
        return nums;
    }
    
    else {
        return "-1";
    }
}
