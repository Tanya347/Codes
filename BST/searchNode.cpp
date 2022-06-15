bool searchInBST(BinaryTreeNode<int> *root , int k) {
	// Write your code here
    
    if(root == NULL)
        return false;
    
    if(root -> data == k)
        return true;
    
    else if(root -> data < k)
        return searchInBST(root -> right, k);
    
    else
        return searchInBST(root -> left, k);
}

