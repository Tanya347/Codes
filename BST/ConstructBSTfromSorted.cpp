BinaryTreeNode<int>* TreeHelper(int *input, int si, int ei){
    
    while(si <= ei) {
        
    	int mid = (si + ei) / 2;
    	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(input[mid]);
    
    	BinaryTreeNode<int>* leftSubTree = TreeHelper(input, si, mid - 1);
    	BinaryTreeNode<int>* rightSubTree = TreeHelper(input, mid + 1, ei);
    
    	root -> left = leftSubTree;
    	root -> right = rightSubTree;
    
    	return root;
        
    }
    
    return NULL;
}


BinaryTreeNode<int>* constructTree(int *input, int n) {
	// Write your code here
    return TreeHelper(input, 0, n - 1);
}
