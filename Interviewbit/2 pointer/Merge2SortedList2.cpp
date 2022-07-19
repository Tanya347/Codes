/********************************************************************** QUESTION **************************************************************************************/

/*

Given two sorted integer arrays A and B, merge B into A as one sorted array.

    Note: You have to modify the array A to contain the merge of A and B. Do not output anything in your code.

    TIP: C users, please malloc the result into a new array and return the result.

If the number of elements initialized in A and B are m and n respectively, the resulting size of array A after your code is executed should be m + n

Example :

Input : 
         A : [1 5 8]
         B : [6 9]

Modified A : [1 5 6 8 9]

*/

/********************************************************************** MY APPROACH **************************************************************************************/

// GIVES TLE FOR HARD TEST CASE BECAUSE IT IS O(N^2) IN WORSE CASE BUT THIS IS WHAT THEY WANTED IN THE QUESTION CRIES

void Solution::merge(vector<int> &A, vector<int> &B) {
    
    int i = 0, j = 0;
    while(i < A.size() && j < B.size()) {
        if(A[i] < B[j]) 
            i++;
        else {
            A.insert(A.begin() + i, B[j]);
            i++;
            j++;
        }
    }
    
    while(j < B.size()) {
        A.push_back(B[j++]);
    }
}

/********************************************************************** GENERAL APPROACH **********************************************************************************/

void Solution::merge(vector<int>& A, vector<int> &B) {
    int i = 0, j = 0;
    vector<int> temp;
    
    while(i < A.size() && j < B.size()) {
        if(A[i] < B[j])
            temp.push_back(A[i++]);
        else
            temp.push_back(B[j++]);
    }
    
    while(i < A.size()) temp.push_back(A[i++]);
    while(j < B.size()) temp.push_back(B[j++]);
    
    A = temp;
}

/********************************************************************** TWISTED **************************************************************************************/

void Solution::merge(vector<int> &A, vector<int> &B) {
    
    for(int i = 0; i < B.size(); i++) {
        A.push_back(B[i]);
    }
    
    sort(A.begin(), A.end());
}
