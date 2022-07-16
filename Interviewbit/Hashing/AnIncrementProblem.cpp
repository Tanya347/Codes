/********************************************************************** QUESTION **************************************************************************************/

/*

Problem Description

Given a stream of numbers A. On arrival of each number, you need to increase its first occurence by 1 and include this in the stream.

Return the final stream of numbers.



Problem Constraints

1 <= |A| <= 100000

1 <= A[i] <= 10000



Input Format

First and only argument is the array A.


Output Format

Return an array, the final stream of numbers.


Example Input

Input 1:

A = [1, 1]

Input 2:

A = [1, 2]



Example Output

Output 1:

[2, 1]

Output 2:

[1, 2]



Example Explanation

Explanation 1:

 On arrival of the second element, the other element is increased by 1.

Explanation 2:

No increases are to be done.


*/

/********************************************************************** QUESTION EXPLANATION **************************************************************************************/

/*

The problem states that “increase its first occurrence by 1 and include this in the stream” meaning when you increment the first occurrence by 1, then the array gets updated itself and next time when you are incrementing then you need to increment considering the updated array.
For example: [1,1,1]
When i=0 then array becomes [1]
When i=1 then array becomes [2,1], since the first occurrence of 1 is at index 0, its value is increased by 1
When i=2 then the array becomes [2,2,1] since the first occurrence of 1 in the updated array is at index 1 not at index 0.

Sly, for this example: [5,5,5,6]
at i=0, A=[5]
at i=1, A=[6,5] first occurrence of 5 is at index 0
at i=2, A=[6,6,5] first occurrence of 5 in updated array is at index 1
at i=3, A=[7,6,6,5] first occurrence of 6 in updated array is at index 0

Sly, for this example: [1,2,3,2,3,1,4,2,1,3]
at i=0, A=[1]
at i=1, A=[1,2]
at i=2, A=[1,2,3]
at i=3, A=[1,3,3,2] occurrence of 2 was at index 1
at i=4, A=[1,4,3,2,3] occurrence of 3 was at index 1
at i=5, A=[2,4,3,2,3,1] occurene of 1 was at index 0
at i=6, A=[2,5,3,2,3,1,4] occurrence of 4 was at index 1
at i=7, A=[3,5,3,2,3,1,4,2] occurrence of 2 was at index 0
at i=8, A=[3,5,3,2,3,2,4,2,1] occurrence of 1 was at index 5
at i=9, A=[4,5,3,2,3,2,4,2,1,3] occurrence of 3 was at index 0

*/

/********************************************************************** ANSWER **************************************************************************************/

vector<int> Solution::solve(vector<int> &A) {
    
    unordered_map<int, int> mp;
    
    for(int i = 0; i < A.size(); i++) {
        
        // if the element's index is not included in the map
        if(mp.find(A[i]) == mp.end()) {
            mp[A[i]] = i;
        } 
        
        // if it is
        else {
            // extract index of first occurrence
            int index = mp[A[i]];
            
            // erase whatever is present at the occurrence of this index
            mp.erase(A[index]);
            
            // increment
            A[index] += 1;
            
            // if the incremented value does not exist in map
            if(mp.find(A[index]) == mp.end()) {
                mp[A[index]] = index;
            } 
            
            // if it exists then update only if current index is lesser
            else {
                if(mp[A[index]] >= index) {
                    mp[A[index]] = index;
                }
            }
            
            // include the current element in the map if it doesn't exist
            if(mp.find(A[i]) == mp.end())
                mp[A[i]] = i;
        }
    }
    
    return A;
}
