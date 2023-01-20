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

// using two stacks

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        if(!root) return {};

        stack<TreeNode*> s1;
        stack<TreeNode*> s2;

        s1.push(root);
        
        while(!s1.empty()) {
            TreeNode* node = s1.top();
            s1.pop();
            if(node -> left) s1.push(node -> left);
            if(node -> right) s1.push(node -> right);
            s2.push(node);
        }

        vector<int> postorder;
        while(!s2.empty()) {
            postorder.push_back(s2.top() -> val);
            s2.pop();
        }

        return postorder;
    }
};

// using one stack

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        if(!root) return {};

        vector<int> postorder;
        TreeNode* curr = root;
        stack<TreeNode*> st;
        
        while(curr != NULL || !st.empty()) {
            
            if(curr != NULL) {
                st.push(curr);
                curr = curr -> left;
            } else {
                TreeNode* temp = st.top() -> right;
                if(temp == NULL) {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp -> val);

                    while(!st.empty() && temp == st.top() -> right) {
                        temp = st.top();
                        st.pop();
                        postorder.push_back(temp -> val);
                    }
                }
                else
                    curr = temp;
            }
        }

        return postorder;
    }
};

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

/******************************************************************* ALL IN ONE *******************************************************************************/

void AllInOneTraversal(TreeNode* root) {
    
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});
    vector<int> pre, in, post;
    
    while(!st.empty()) {
        TreeNode* node = st.top().first;
        int num = st.top().second;
        st.pop();
        
        if(num == 1) {
            
            pre.push_back(node -> data);
            st.push({node, num + 1});
            
            if(node -> left)
                st.push(node -> left, 1);
            
        } else if(num == 2) {
            
            in.push_back(node -> data);
            st.push({node, num + 1});
            
            if(node -> right)
                st.push(node -> right, 1);
        } else {
            
            post.push_back(node -> data);
        }
    }
}
