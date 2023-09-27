/******************************************************************* QUESTION ************************************************************************/

Given an array A of size n and an integer K, return all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.


Note :
The order of subsets are not important.


Input format :
Line 1 : Integer n, Size of input array
Line 2 : Array elements separated by space
Line 3 : K 
Constraints :
1 <= n <= 20
Sample Input :
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output :
3 3
5 1

/******************************************************************* ANSWER ************************************************************************/

int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
    
    //base case
    if(n==0){
        if(k==0){
            output[0][0]=0;
            return 1;
        }
        else
            return 0;
    }
    
    //with first element
    int s1 = subsetSumToK(input + 1, n - 1, output, k - input[0]);
    int s2 = subsetSumToK(input + 1, n - 1, output + s1, k);
    
    //shift elements
    for(int i=0;i<s1;i++){
        for(int j=output[i][0];j>=1;j--)
            output[i][j+1]=output[i][j];
    }
    
    for(int i=0;i<s1;i++){
        output[i][0]++;
        output[i][1]=input[0];
    }
    
    //without first element
    return s1+s2;
}

/******************************************************************* EXPLANATION ************************************************************************/

Recursion Idea:
The main idea behind this approach is the principle of inclusion-exclusion. For each number in the array, you have two choices:

Include the number in the subset.
Exclude the number from the subset.
You recursively process the array and check both of these possibilities.

Dry Run:

Consider the sample input:

css
Copy code
n = 9 
input[] = 5 12 3 17 1 18 15 3 17 
K = 6
Let's dry run the function for a few steps to understand its behavior.

When the function is called for the first time:
input[] = 5 12 3 17 1 18 15 3 17
n = 9
k = 6

First, we'll explore the subsets that include the first element, 5.
So, the new call becomes: input + 1, n - 1, k - input[0]
i.e., for input 12 3 17 1 18 15 3 17 and k = 1 (because 6 - 5 = 1)

On the second level, now we'll see the subsets that include the first element, 12.
But 12 is greater than 1, so no valid subset can be formed. We only explore the excluding part now.

So, the next call will be: input + 1, n - 1, k for input 3 17 1 18 15 3 17 and k = 1.

Continuing this process, the third level will include 3 and look for subsets summing to -2, which is invalid. So, we'll explore the excluding part for input 17 1 18 15 3 17 and k = 1.

At the fourth level, we'll skip 17 (since it's greater than the target) and look at the subset with the next element: 1 18 15 3 17 and k = 1.

At this point, we reach the number 1 which is equal to our target. So, one of the valid subsets we've found is [5, 1].

This process continues until the end of the array.

Output Formulation:
For each valid subset, the code maintains an array where the first index tells you how many elements are there in that subset (let's call it size) and the next indexes (from 1 to size) contain the actual elements of the subset.

The recursive calls essentially bifurcate the output array: one half where the first element is included (output) and the other half where it's excluded (output + s1). After each recursion, the code modifies the size (the first index) of each subset and inserts the current element at the beginning of the subset if it's included.

After recursively processing the entire array, the function will have populated the output array with all subsets that sum to K.

In our dry run, the function will find [5, 1] and [3, 3] as the subsets of the input array that sum to 6.
