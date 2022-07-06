int helper(TreeNode* root, int& time, int B) {
    if(!root) return 0;
    
    if(root -> left == NULL && root -> right == NULL && root -> val == B) return 10000000;
    
    int l = helper(root -> left, time, B);
    int r = helper(root -> right, time, B);
    
    int temp = 1 + max(l, r);
    
    int ans = max(temp, l + r + 1);
    
    time = max(ans, time);
    
    return temp;

}
 
int Solution::solve(TreeNode* A, int B) {
    
    int time = 0;
    helper(A, time, B);
    
    return time - 10000000;
}
