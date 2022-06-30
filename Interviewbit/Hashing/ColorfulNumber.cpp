/********************************************************************** BRUTE FORCE **************************************************************************************/

/*

For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different

Example:

N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

Output : 1

*/

/********************************************************************** SOLUTION **************************************************************************************/


int Solution::colorful(int A) {
  
    //first extract all numbers
    vector<int> num;
    while(A != 0) {
        num.push_back(A%10);
        A = A/10;
    }
    reverse(num.begin(), num.end());
    
    vector<int> prod;
    
    //then form subarrays and find their products and push into prod array
    for(int i = 0; i < num.size(); i++) {
            int p = num[i];
            prod.push_back(num[i]);
        for(int j = i + 1; j < num.size(); j++) {
            p = p*num[j];
            prod.push_back(p);
        }
    }
    
    sort(prod.begin(), prod.end());
    
    //if there exists two subarrays with same product the number cannot be colourful
    for(int i = 1; i < prod.size(); i++) {
        if(prod[i] == prod[i - 1])
        return 0;
    }
    return 1;
}
