/********************************************************************** QUESTION **************************************************************************************/

/*

Given a collection of numbers, return all possible permutations.

Example:

[1,2,3] will have the following permutations:

[1,2,3]
[1,3,2]
[2,1,3] 
[2,3,1] 
[3,1,2] 
[3,2,1]

    NOTE

        No two entries in the permutation sequence should be the same.
        For the purpose of this problem, assume that all the numbers in the collection are unique.

    Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS.

    Example : next_permutations in C++ / itertools.permutations in python.

    If you do, we will disqualify your submission retroactively and give you penalty points.

*/

/********************************************************************** ANSWER **************************************************************************************/


void permutations(vector<vector<int>>& ans, vector<int> temp, vector<int> &A, vector<bool>& visited) {
    if(temp.size() == A.size()) {
        ans.push_back(temp);
        return;
    }
    
    for(int i = 0; i < A.size(); i++) {
        if(!visited[i]) {
            temp.push_back(A[i]);
            visited[i] = true;
            permutations(ans, temp, A, visited);
          
          //backtrack
            temp.pop_back();
            visited[i] = false;
        }
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> ans;
    vector<int> temp;
  
  // this array maintains whether we have included an index or not
    vector<bool> visited(A.size(), false);
    
    permutations(ans, temp, A, visited);
    
    return ans;
    
}
