vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	// Write your code here
    if(root == NULL)
        return NULL;
    
    vector<int> *output = new vector<int>();
    
    if (root -> data == data)
    {
        output -> push_back(root->data);
    }
    
    else if(root -> data > data) {
        output = getPath(root -> left, data);
        if(output != NULL) {
            output -> push_back(root -> data);
        }
    }
    
    else if (root -> data < data) {
        output = getPath(root -> right, data);
        if(output != NULL) {
            output -> push_back(root -> data);
        }
    }
    
	return output;
}
