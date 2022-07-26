/********************************************************************** QUESTION **************************************************************************************/

/*

Problem Description

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).


Input Format

First and only argument is root node of the binary tree, A.


Output Format

Return a 2D integer array denoting the zigzag level order traversal of the given binary tree.


Example Input

Input 1:

    3
   / \
  9  20
    /  \
   15   7

Input 2:

   1
  / \
 6   2
    /
   3



Example Output

Output 1:

 [
   [3],
   [9, 20],
   [15, 7]
 ]

Output 2:

 [ 
   [1]
   [6, 2]
   [3]
 ]



Example Explanation

Explanation 1:

 Return the 2D array. Each row denotes the traversal of each level.

*/

/********************************************************************** ANSWER **************************************************************************************/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int height(TreeNode* A) {
    if(A == NULL)
    return 0;
    
    return 1 + max(height(A -> left), height(A -> right));
}
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    
    // to know exectly the size of array in order to avoid run time error
    vector<vector<int>> ans(height(A));
    
    queue<TreeNode*> q;
    // to maintain the index where we need to insert the particular node
    unordered_map<TreeNode*, int> mp;
    mp[A] = 0;
    q.push(A);
    
    while(!q.empty()) {
        TreeNode* parent = q.front();
        q.pop();
        int a = parent -> val;
        ans[mp[parent]].push_back(a);
        
        if(parent -> left != NULL) {
            q.push(parent -> left);
            mp[parent -> left] = mp[parent] + 1;
        }
        
        if(parent -> right != NULL) {
            q.push(parent -> right);
            mp[parent -> right] = mp[parent] + 1;
        }
    }
    
    return ans;
}
