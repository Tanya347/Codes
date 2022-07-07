/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class BT {
    
    public:
    int height;
    bool balanced;
    
    BT(int h, bool b) {
        height = h;
        balanced = b;
    }
};

BT helper(TreeNode* A) {
    if(A == NULL) {
        BT ans(0, true);    
        return ans;
    }
    
    if(A -> left == NULL && A -> right == NULL) {
        BT ans(1, true);
        return ans;
    }
    
    BT l = helper(A -> left);
    BT r = helper(A -> right);
    
    int h = 1 + max(l.height, r.height);
    int b = false;
    
    if(abs(l.height - r.height) <= 1 && l.balanced && r.balanced) b = true;
    
    BT ans(h, b);
    
    return ans;
}

int Solution::isBalanced(TreeNode* A) {
    
    return helper(A).balanced;
}
