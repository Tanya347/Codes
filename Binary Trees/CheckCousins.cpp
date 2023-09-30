/************************************************* QUESTION *****************************************************************************/

Given the binary Tree and two nodes say ‘p’ and ‘q’. Determine whether the two nodes are cousins of each other or not. Two nodes are said to be cousins of each other if they are at same level of the Binary Tree and have different parents.
Do it in O(n).
Input format :
Line 1 : Nodes in level order form (separated by space). If any node does not have left or right child, take -1 in its place
Line 2 : integer value of p 
Line 3 : Integer value of q
Output format :
true or false
Constraints :
1 <= N <= 10^5
Sample Input :
5 6 10 2 3 4 -1 -1 -1 -1 9 -1 -1 -1 -1
2
4
Sample Output :
true

/************************************************* ANSWER1 *****************************************************************************/

bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
    // Write your code here

    queue<BinaryTreeNode<int>*> nodes;
    nodes.push(root);

    while(!nodes.empty()) {

        bool foundp = false, foundq = false;

        int s = nodes.size();

        while(s--) {
            BinaryTreeNode<int>* top = nodes.front();
            nodes.pop();

            // Check for siblings
            if (top->left && top->right) {
                if ((top->left->data == p && top->right->data == q) || 
                    (top->left->data == q && top->right->data == p)) {
                    return false; // they are siblings
                }
            }

            if(top -> left != NULL) {
                if (top->left->data == p) foundp = true;
                if (top->left->data == q) foundq = true;
                nodes.push(top->left);
            }
            
            if (top->right != NULL) {
                if (top->right->data == p) foundp = true;
                if (top->right->data == q) foundq = true;
                nodes.push(top->right);
            }
        }

        if(foundp && foundq)
            return true;
    }

    return false;
}

/******************************************************************** ANSWER 2 *******************************************************************/


int Depth(BinaryTreeNode<int> *root, int node) {
    if(root == NULL)
        return 0;
    
    if(root -> data == node)
        return 1;
    
    int leftD = Depth(root -> left, node);
    
    if(leftD != 0) 
        return leftD + 1;
    else {
        int rightD = Depth(root -> right, node);
        
        if(rightD != 0)
            return rightD + 1;
        
        else return 0;
    }
}

bool isSibling(BinaryTreeNode<int> *root, int p, int q) {
    if(root == NULL)
        return false;
    
    if(root -> left != NULL && root -> right != NULL) {
        
        if(root -> left -> data == p && root -> right -> data == q)
            return true;
        
        else if(root -> left -> data == q && root -> right -> data == p)
            return true;
        
        else return isSibling(root -> left, p, q) || isSibling(root -> right, p, q);
    }
    
    if(root -> left == NULL)
        
        return isSibling(root -> right, p, q);
    
    else 
        
        return isSibling(root -> left, p, q);
}

bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
    // Write your code here
    
    return ((Depth(root, p) == Depth(root, q)) && (!isSibling(root, p, q)));

}
