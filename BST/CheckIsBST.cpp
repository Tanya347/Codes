#include<climits>


//Failed Approach (works for 102 out of 120 test cases on gfg)
bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
    
    if(root == NULL)
        return true;
    
    bool x, y;
    
    if(root -> left != NULL && root -> data < root -> left -> data)
        x = false;
    else 
        x = isBST(root -> left);
    
    if(root -> right != NULL && root -> data > root -> right -> data)
        y = false;
    else
        y = isBST(root -> right);
    
    return (x && y);
}

//Approach 1
bool isBST(BinaryTreeNode<int>* root, int minima, int maxima) {
    if(root == NULL)
        return true;
    
    if(root -> data < minima || root -> data > maxima)
        return false;
    
    bool x = isBST(root -> left, minima, root -> data);
    bool y = isBST(root -> right, root -> data, maxima);
    
    return x && y;
}

bool isBST(BinaryTreeNode<int>* root) {
    return isBST(root, INT_MIN, INT_MAX);
}

//Approach 2
#include<climits>
class isBSTreturn{
    public: 
    int max;
    int min;
    bool isBST;
    
    isBSTreturn() {
        
    }
    
    isBSTreturn(bool isBST, int max, int min) {
        this -> max = max;
        this -> min = min;
        this -> isBST = isBST;
    }
};

isBSTreturn isBST_helper(BinaryTreeNode<int>* root) {
    
    if(root == NULL){
        isBSTreturn output(true, INT_MIN, INT_MAX);
        return output;
    }
    
    isBSTreturn leftOutput = isBST_helper(root -> left);
    isBSTreturn rightOutput = isBST_helper(root -> right);
    
    int minimum = min(root -> data, min(leftOutput.min, rightOutput.min));
    int maximum = max(root -> data, max(leftOutput.max, rightOutput.max));
    
    bool isBST_Final = (root -> data > leftOutput.max) && (root -> data <= rightOutput.min)
                        && (leftOutput.isBST) && (rightOutput.isBST);
    
    isBSTreturn output(isBST_Final, maximum, minimum);
    return output;
}

bool isBST(BinaryTreeNode<int>* root){
    return isBST_helper(root).isBST;
}

//Approach 3

#include<climits>
int maximum(BinaryTreeNode<int>* root){
    
    if(root == NULL)
        return INT_MIN;
    
    return max(root -> data, max(maximum(root -> left),maximum(root -> right)));
    
}

int minimum(BinaryTreeNode<int>* root){
    
    if(root == NULL)
        return INT_MAX;
    
    return min(root -> data, min(minimum(root -> left),minimum(root -> right)));
    
}

bool isBST(BinaryTreeNode<int> *root){
    if(root == NULL)
        return true;
    
    int leftMax = maximum(root -> left);
    int rightMin = minimum(root -> right);
    
    bool output = (root -> data > leftMax) && (root -> data < rightMin) && isBST(root -> left) && isBST(root -> right);
    return output;
}

//Approach 4 (just minor change in Approach 1)

#include <climits>

bool isBST_helper(BinaryTreeNode<int>* root, int min = INT_MIN, int max = INT_MAX) {
    if(root == NULL)
        return true;
    
    if(root -> data < min || root -> data > max) {
        return false;
    }
    
    bool isLeftOK = isBST_helper(root -> left, min, root -> data -1);
    bool isRightOK = isBST_helper(root -> right, root -> data, max);
    
    return isLeftOK && isRightOK;
}


bool isBST(BinaryTreeNode<int>* root){
    return isBST_helper(root);
}

// ANOTHER FAILED APPROACH

/*
bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
    
    if(root == NULL)
        return true;
    
    bool ans;
    if(root -> left != NULL && root -> right != NULL){
        
    if(root -> data < root -> right -> data && root -> data > root -> left -> data)
        ans = true;
    else return false;
    
    bool leftAns = isBST(root -> left);
    
    bool rightAns = isBST(root -> right);
    
    if(leftAns == false || rightAns == false)
        return false;
        
    }
    
    return true;
    
}
*/
