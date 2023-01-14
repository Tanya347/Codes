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

// iterative preorder using stack

class Solution {
public:

    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL)
            return {};
        
        stack<TreeNode*> st;
        st.push(root);

        vector<int> ans;

        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            ans.push_back(node -> val);

            if(node -> right) st.push(node -> right);
            if(node -> left) st.push(node -> left);
        }

        return ans;
    }
};

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

// iterative inorder using stack
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        if(root == NULL)
            return {};
        
        stack<TreeNode*> st;
        TreeNode* node = root;
        vector<int> ans;

        while(true) {
            if(node) {
                st.push(node);
                node = node -> left;
            } else {
                if(st.empty()) break;
                node = st.top();
                ans.push_back(node -> val);
                st.pop();
                node = node -> right;
            }
        }

        return ans;
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root == NULL)
            return {};
            
        queue<TreeNode*> nodes;
        nodes.push(root);
        vector<vector<int>> ans;
        
        while(!nodes.empty()) {
            int s = nodes.size();
            vector<int> temp;
            while(s--) {
                TreeNode* node = nodes.front();
                nodes.pop();
                temp.push_back(node -> val);

                if(node -> left) 
                    nodes.push(node -> left);
                
                if(node -> right)
                    nodes.push(node -> right);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
