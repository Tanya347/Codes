/******************************************************************* PREORDER *******************************************************************************/

//Function to return a list containing the preorder traversal of the tree.
vector <int> preorder(Node* root)
{
  // Your code here
    if(root == NULL)
        return {};

    vector<int> ans;
    ans.push_back(root -> data);
    
    vector<int> left = preorder(root -> left);
    ans.insert(ans.end(), left.begin(), left.end());
    
    vector<int> right = preorder(root -> right);
    ans.insert(ans.end(), right.begin(), right.end());
    
    return ans;
}

/******************************************************************* INORDER *******************************************************************************/

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        
        if(root == NULL)
            return {};
            
        vector<int> left = inOrder(root -> left);
        left.push_back(root -> data);
        vector<int> right = inOrder(root -> right);
        left.insert(left.end(), right.begin(), right.end());
        
        return left;
    }
};

/******************************************************************* POSTORDER *******************************************************************************/

vector <int> postOrder(Node* root)
{
  // Your code here
    if(root == NULL)
        return {};

    vector<int> left = postOrder(root -> left);
    vector<int> right = postOrder(root -> right);
    
    left.insert(left.end(), right.begin(), right.end());
    left.push_back(root -> data);
    return left;
}

/******************************************************************* LEVEL ORDER *******************************************************************************/
