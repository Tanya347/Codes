/********************************************************************** QUESTION **************************************************************************************/


/*

Given a binary search tree, write a function to find the kth smallest element in the tree.

Example :

Input : 
  2
 / \
1   3

and k = 2

Return : 2

As 2 is the second smallest element in the tree.

    NOTE : You may assume 1 <= k <= Total number of nodes in BST

*/

/********************************************************************** SOLUTION **************************************************************************************/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


int countNodes(TreeNode* A) {
    if(A == NULL) {
        return 0;
    }
    return 1 + countNodes(A -> left) + countNodes(A -> right);
}

int Solution::kthsmallest(TreeNode* A, int B) {
    
    //basically smallest nodes can usually be found on the left subtree so we will first get a count of number of nodes in left subtree 
    //this count + 1 (for root) if it is greater than B that means Bth smallest element lies towards left else if it is smaller that means it 
    //lies on the right and we will subtract leftcount + 1 from B because already that amount of nodes is lesser by default since it is a BST
    //and lastly if leftcount + 1 == B that means we have reached desired node we can return its value (this basically means leftcount
    //from left are already B - 1 and the (leftcount + 1)th element corresponds to Bth smallest)
    int left_count = countNodes(A -> left);
    
    if(left_count + 1 > B)
        return kthsmallest(A -> left, B);
    else if(left_count + 1 < B)
        return kthsmallest(A -> right, B - left_count - 1);
    else
        return A -> val; 
}
