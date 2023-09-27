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
