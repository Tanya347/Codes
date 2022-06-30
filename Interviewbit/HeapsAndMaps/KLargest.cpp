/********************************************************************** QUESTION **************************************************************************************/

/*
Given an 1D integer array A of size N you have to find and return the B largest elements of the array A.

NOTE:

    Return the largest B elements in any order you like.

Example Input

Input 1:

 A = [11, 3, 4]
 B = 2

Input 2:

 A = [11, 3, 4, 6]
 B = 3



Example Output

Output 1:

 [11, 4]

Output 2:

 [4, 6, 11]

    
*/

/********************************************************************** ANSWER **************************************************************************************/

vector<int> Solution::solve(vector<int> &A, int B) {
  //min heap
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < B; i++) {
        pq.push(A[i]);
    }
    
    for(int i = B; i < A.size(); i++) {
      //topmost element will be smallest so we can swap it out with elements that are greater
        if(pq.top() < A[i]) {
            pq.pop();
            pq.push(A[i]);
        }
    }
    
    vector<int> ans;
    for(int i = 0; i < B; i++) {
      //as we kept size of pq as B it will contain exactly B number of elements that are largest
        ans.push_back(pq.top());
        pq.pop();
    }
    
    return ans;
}
