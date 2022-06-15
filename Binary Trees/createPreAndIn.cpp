//method 1 using helper function
BinaryTreeNode<int>* buildTree(int* preorder, int* inorder, int preStart, int preEnd, int inStart, int inEnd) {
    
    if(inStart > inEnd || preStart > preEnd) {
        return NULL;
    }
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[preStart]);
    
    if(inStart == inEnd)
		return root;
    
    //finding the index or root in inorder
    int rootIndex;
    for(int i = inStart; i <= inEnd; i++) {
        if(inorder[i] == preorder[preStart]) {
            rootIndex = i;
            break;
        }
    }
    
    int length = rootIndex - inStart;
    root -> left = buildTree(preorder, inorder, preStart + 1, preStart + length, inStart, rootIndex - 1);
    root -> right = buildTree(preorder, inorder, preStart + length + 1, preEnd, rootIndex + 1, inEnd);
    
    return root;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Helper function
    return buildTree(preorder, inorder, 0, preLength - 1, 0, inLength - 1);
}

//method 2 
BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    
    if(inLength == 0) {
        return NULL;
    }
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[0]);
    
    if(inLength == 1)
        return root;
    
    int rootIndex;
    for(int i = 0; i <= inLength; i++) {
        if(inorder[i] == preorder[0]) {
            rootIndex = i;
            break;
        }
    }
    
    int leftLength = rootIndex;
    int rightLength = preLength - rootIndex - 1;
    root -> left = buildTree(preorder + 1, leftLength, inorder, leftLength);
    root -> right = buildTree(preorder + leftLength + 1, rightLength, inorder + leftLength + 1, rightLength);
    
    return root;
    
}
