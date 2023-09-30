/************************************************* QUESTION *****************************************************************************/

Given a binary tree, return the longest path from leaf to root. Longest means, a path which contain maximum number of nodes from leaf to root.
Input format :
Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Output format :
Line 1 : Binary Tree 1 (separated by space)
Sample Input 1 :
 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Input Graph

Sample Output 1 :
9
3
6
5
Input Graph

/************************************************* ANSWER 1 *****************************************************************************/

void longest(BinaryTreeNode<int>* root, vector<int>*& ans, vector<int>*& temp) {

    if(root == NULL) {
        if(temp -> size() > ans -> size())
            *ans = *temp;
        return;
    }
    
    temp -> push_back(root -> data);

    longest(root -> left, ans, temp);
    longest(root -> right, ans, temp);
    
    temp -> pop_back();
}

vector<int>* longestPath(BinaryTreeNode<int>* root) {
	// Write your code here

    vector<int> *ans = new vector<int>();
    vector<int> *temp = new vector<int>();
    longest(root, ans, temp);
    reverse(ans -> begin(), ans -> end());
    return ans;
}

/************************************************* ANSWER 2 *****************************************************************************/

vector<int>* longestPath(BinaryTreeNode<int>* root) {
	// Write your code here
    
    if(root == NULL)
        return NULL;
    
    if(root -> left == NULL && root -> right == NULL) {
        
        vector<int>* path = new vector<int>();
        path -> push_back(root -> data);
        return path;
        
    }
    
    vector<int>* leftPath = longestPath(root -> left);
    vector<int>* rightPath = longestPath(root -> right);
    
    if(!leftPath) {
        rightPath -> push_back(root -> data);
        return rightPath;
    }
    
    else if(!rightPath) {
        leftPath -> push_back(root -> data);
        return leftPath;
    }
    
    else {
        
        if(leftPath -> size() > rightPath -> size()) {
            
            leftPath -> push_back(root -> data);
            delete rightPath;
            return leftPath;
        }
        
        else {
            rightPath -> push_back(root -> data);
            delete leftPath;
            return rightPath;
        }
    }

}
