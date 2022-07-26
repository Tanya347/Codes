/********************************************************************** QUESTION **************************************************************************************/

/*

Find the lowest common ancestor in an unordered binary tree given two values in the tree.

    Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) is the lowest (i.e. deepest) node that has both v and w as descendants.

Example :


        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2_     0        8
         /   \
         7    4

For the above tree, the LCA of nodes 5 and 1 is 3.

    LCA = Lowest common ancestor

Please note that LCA for nodes 5 and 4 is 5.

        You are given 2 values. Find the lowest common ancestor of the two nodes represented by val1 and val2
        No guarantee that val1 and val2 exist in the tree. If one value doesn’t exist in the tree then return -1.
        There are no duplicate values.
        You can use extra memory, helper functions, and can modify the node struct but, you can’t add a parent pointer.

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
 
TreeNode* helper(TreeNode* root, int &B, int &C) {
    if(root == NULL)
    return NULL;
    
    TreeNode* leftLca = helper(root -> left, B, C);
    TreeNode* rightLca = helper(root -> right, B, C);
    
    // if both are not null this means that B and C were found in its subtrees
    // hence return this root cause this is the lcs
    if(leftLca != NULL && rightLca != NULL) 
        return root;
    
    // marking B or C as -1 if they were found
    if(root -> val == B || root -> val == C) {
        B = (root -> val == B)? -1 : B;
        C = (root -> val == C)? -1 : C;
        return root;
    }
    
    // if either is NULL that means either lca was already found below 
    // or the other one isn't found yet so just return the not null one 
    return (leftLca != NULL)? leftLca : rightLca;
}

int Solution::lca(TreeNode* A, int B, int C) {
    TreeNode* root = helper(A, B, C);
    
    // only if root is not null and both B and C were found return val
    if(root && B == -1 && C == -1)
        return root -> val;
        
    // otherwise return -1
    return -1;
}
