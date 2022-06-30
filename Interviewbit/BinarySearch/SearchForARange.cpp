
/********************************************************************** QUESTION **************************************************************************************/

/*

Given a sorted array of integers A(0 based index) of size N, find the starting and ending position of a given integar B in array A.

Your algorithm’s runtime complexity must be in the order of O(log n).

Return an array of size 2, such that first element = starting position of B in A and second element = ending position of B in A, if B is not found in A return [-1, -1].




Input Format

The first argument given is the integer array A.
The second argument given is the integer B.

Output Format

Return an array of size 2, such that first element = starting position of B in A and second element = ending position of B in A, if B is not found in A return [-1, -1].

For Example

Input 1:
    A = [5, 7, 7, 8, 8, 10]
    B = 8
Output 1:
    [3, 4]
Explanation 1:
    First occurence of 8 in A is at index 3
    Second occurence of 8 in A is at index 4
    ans = [3, 4]

Input 2:
    A = [5, 17, 100, 111]
    B = 3
Output 2:
    [-1, -1]



*/

/********************************************************************** SOLUTION **************************************************************************************/

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int s = 0, e = A.size() - 1;
    vector<int> ans;
    
    while(s <= e) {
        int mid = (s + e) / 2;
        
        if(A[mid] == B) {
            int start = mid, end = mid;
            //if found travel in both directions to find the start and end
            while(end + 1 < A.size() && A[end + 1] == B) {
                end++;
            }
            while(start - 1 >= 0 && A[start - 1] == B) {
                start--;
            }
            ans.push_back(start);
            ans.push_back(end);
            
            return ans;
        } else if(A[mid] < B) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    
    ans.push_back(-1);
    ans.push_back(-1);
    
    return ans;
}
