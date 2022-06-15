//Method 1 using helper function
BinaryTreeNode<int>* buildTree(int *post, int* in, int postS, int postE, int inS, int inE) {
    
    if(postS > postE || inS > inE)
        return NULL;
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(post[postE]);
    
    if(postS == postE)
        return root;
    
    int i;
    for(i = inS; i <= inE; i++) {
        if(in[i] == post[postE]) {
            break;
        }
    }
    
    int leftLength = i - inS;
    root -> left = buildTree(post, in, postS, postS + leftLength - 1, inS, i - 1);
    root -> right = buildTree(post, in, postS + leftLength, postE - 1, i + 1, inE);
    
    return root;
}

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    
    return buildTree(postorder, inorder, 0, postLength - 1, 0, inLength - 1);
    
}

//Method 2
BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    
    if(postLength == 0 || inLength == 0)
        return NULL;
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(postorder[postLength - 1]);
    
    if(postLength == 1)
        return root;
    
    int i;
    for(i = 0; i <= inLength; i++) {
        if(inorder[i] == postorder[postLength - 1]) {
            break;
        }
    }
    
    int leftLength = i;
    int rightLength = postLength - i - 1;
    
    root -> left = buildTree(postorder, leftLength, inorder, leftLength);
    root -> right = buildTree(postorder + leftLength, rightLength, inorder + leftLength + 1, rightLength);
    
    return root;
    
}
