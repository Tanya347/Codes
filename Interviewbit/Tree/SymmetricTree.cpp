/********************************************************************** QUESTION **************************************************************************************/

/*

Problem Description
 
 

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).


Problem Constraints

1 <= number of nodes <= 105


Input Format

First and only argument is the root node of the binary tree.


Output Format

Return 0 / 1 ( 0 for false, 1 for true ).


Example Input

Input 1:

    1
   / \
  2   2
 / \ / \
3  4 4  3

Input 2:

    1
   / \
  2   2
   \   \
   3    3



Example Output

Output 1:

 1

Output 2:

 0



Example Explanation

Explanation 1:

 The above binary tree is symmetric. 

Explanation 2:

The above binary tree is not symmetric.

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
 
bool check(TreeNode *a, TreeNode *b) {
    
    if(a == NULL || b == NULL) return a == b;
    
    if(a -> val != b -> val) return false;
    
    return check(a -> left, b -> right) && check(a -> right, b -> left);
}

int Solution::isSymmetric(TreeNode* A) {
       
    return check(A -> left, A -> right);
}
