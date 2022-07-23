/********************************************************************** QUESTION **************************************************************************************/

/*

Given a binary tree, flatten it to a linked list in-place.

Example :

Given


         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

Note that the left child of all nodes should be NULL.

*/

/********************************************************************** ANSWER **************************************************************************************/

TreeNode* Solution::flatten(TreeNode* A) {
    if(A == NULL)
        return A;
    
    TreeNode* root = A;
    flatten(A -> left);
    flatten(A -> right);
    
    if(A -> left) {
        TreeNode* r = A -> right;
        A -> right = A -> left;
        A -> left = NULL;
        while(A -> right) {
            A = A -> right;
        }
        A -> right = r;
    }
    
    return root;
}
