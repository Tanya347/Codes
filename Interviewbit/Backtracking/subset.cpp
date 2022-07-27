/********************************************************************** QUESTION **************************************************************************************/

/*

Given a set of distinct integers, S, return all possible subsets.

    Note:

        Elements in a subset must be in non-descending order.
        The solution set must not contain duplicate subsets.
        Also, the subsets should be sorted in ascending ( lexicographic ) order.
        The list is not necessarily sorted.

Example :

If S = [1,2,3], a solution is:

[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]

*/

/********************************************************************** ANSWER **************************************************************************************/


void subsets_helper(vector<int> &A, vector<vector<int> >&ans, vector<int>& temp, int i, int k) {
    if(i == k) {
        ans.push_back(temp);
        return;
    }
    
    for(int j = i; j < A.size(); j++) {
        temp.push_back(A[j]);
        subsets_helper(A, ans, temp, j + 1, k);
        temp.pop_back();
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int> > ans;
    vector<int> temp;
    sort(A.begin(), A.end());
    for(int k = 0; k <= A.size(); k++) {
        subsets_helper(A, ans, temp, 0, k);
    }
    sort(ans.begin(), ans.end());
    return ans;
}


