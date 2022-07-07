
Problem Description

Given an one-dimensional unsorted array A containing N integers.

You are also given an integer B, find if there exists a pair of elements in the array whose difference is B.

Return 1 if any such pair exists else return 0.



Problem Constraints

    1 <= N <= 105
    -103 <= A[i] <= 103
    -105 <= B <= 105



Input Format

First argument is an integer array A of size N.

Second argument is an integer B.



Output Format

Return 1 if any such pair exists else return 0.


Example Input

Input 1:

 A = [5, 10, 3, 2, 50, 80]
 B = 78

Input 2:

 A = [-10, 20]
 B = 30



Example Output

Output 1:

 1

Output 2:

 1



Example Explanation

Explanation 1:

 Pair (80, 2) gives a difference of 78.

Explanation 2:

 Pair (20, -10) gives a difference of 30 i.e 20 - (-10) => 20 + 10 => 30




/********************************************************************** APPROACH 1 **************************************************************************************/

// TIME COMPLEXITY = O(nlogn)
  

  
 bool binarySearch(vector<int> &A, int n, int i) {
    int s = 0, e = A.size() - 1;
    
    while(s <= e) {
        int mid = (s + e) / 2;
        if(A[mid] == n) {
            if(mid == i)
            s++;
            else return true;
        }
        else if(A[mid] < n)
            s = mid + 1;
        else 
            e = mid - 1;
    }
    
    return false;
}

//find if a number exists for every element in A such that if we subtract B from that number we get ith element
int Solution::solve(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    
    for(int i = 0; i < A.size(); i++) {
        int diff = A[i] + B; 
        if(binarySearch(A, diff, i)) return 1;   
    }
    
    return 0;
}

/********************************************************************** APPROACH 2 **************************************************************************************/

// TIME COMPLEXITY = O(n)


int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int> mp;
    
    for(int i = 0; i < A.size(); i++) {
        mp[A[i]]++;
    }
    
    for(int i = 0; i < A.size(); i++) {
        if(B == 0) {
            return (mp[A[i]] > 1);
        } else {
            int diff = A[i] + B;
            if(mp.find(A[i] + B) != mp.end())
            return true;
        }
    }
    
    return false;
}

/********************************************************************** APPROACH 3 **************************************************************************************/

// TWO POINTERS
// TIME COMPLEXITY = O(nlogn  + n)


int Solution::solve(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    
    int i = 0, j = 1;
    
    for(int i = 0; i < A.size(); i++) {
        if(A[j] - A[i] == B)
            return 1;
        else if(A[j] - A[i] < B) 
            j++;
        else 
            i++;
    }
    
    return 0;
}
