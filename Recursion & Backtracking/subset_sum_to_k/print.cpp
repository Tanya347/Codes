/******************************************************************* QUESTION ************************************************************************/

Given an array A and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.


Note :
The order of subsets are not important. Just print them in different lines.


Input format :
Line 1 : Size of input array
Line 2 : Array elements separated by space
Line 3 : K 
Sample Input:
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output:
3 3
5 1

/******************************************************************* ANSWER ************************************************************************/

void print_helper(int input[], int size, int* output, int m, int k) {
    
    if(size == 0) {
        if(k == 0) {
            for(int i = 0; i < m; i++) 
            	cout<<output[i]<<" ";
        	cout<<endl;
        	return;
        }
        else
            return;
    }
    
    int* newoutput = new int[m + 1];
    
    for(int i = 0; i < m; i++) {
        newoutput[i] = output[i];
    }
    newoutput[m] = input[0];
    print_helper(input + 1, size - 1, output, m, k);
    print_helper(input + 1, size - 1, newoutput, m + 1, k - input[0]);
    
    delete [] newoutput;
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    
    int *output = new int[size];
    print_helper(input, size, output, 0, k);
    delete [] output;
}
