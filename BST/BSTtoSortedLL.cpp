class HeadTail {
  
    public:
    Node<int>* head;
    Node<int>* tail;
};

HeadTail helper(BinaryTreeNode<int>* root) {
    
    if(root == NULL) {
        HeadTail ans;
        ans.head = NULL;
        ans.tail = NULL;
        return ans; 
    }
    
    if(root -> left == NULL && root -> right == NULL) {
        Node<int>* node = new Node<int>(root -> data);
        HeadTail ans;
        ans.head = node;
        ans.tail = node;
        return ans;
    }
    
    Node<int>* node = new Node<int>(root -> data);
    HeadTail leftAns = helper(root -> left);
    HeadTail rightAns = helper(root -> right);
    
    if(leftAns.head != NULL && rightAns.head == NULL) {
        leftAns.tail -> next = node;
        leftAns.tail = node;
        return leftAns;
        
    } else if(leftAns.head == NULL && rightAns.head != NULL) {
        node -> next = rightAns.head;
        rightAns.head = node;
        return rightAns;
        
    } else {
        leftAns.tail -> next = node;
        node -> next = rightAns.head;
        leftAns.tail = rightAns.tail;
        return leftAns;
    }
    
}
Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
    return helper(root).head;
}
