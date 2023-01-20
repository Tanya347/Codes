/******************************************************************* HEIGHT *******************************************************************************/

// Recursion

class Solution {
public:
    int maxDepth(TreeNode* root) {
        
        if(root == nullptr)
            return 0;
        
        return 1 + max(maxDepth(root -> left), maxDepth(root -> right));
    }
};

// Queue

class Solution {
public:
    int maxDepth(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        
        queue<TreeNode*> q;
        q.push(root);

        int level = 0;

        while(!q.empty()) {
            int n = q.size();
            level++;
            
            while(n--) {
                TreeNode* node = q.front();
                q.pop();

                if(node -> left)
                    q.push(node -> left);

                if(node -> right)
                    q.push(node -> right);
            }
        }

        return level;
    }
};

/******************************************************************* QUESTION *******************************************************************************/

/*

Given a binary tree, determine if it is 
height-balanced
.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104

*/

/******************************************************************* ANSWER *******************************************************************************/

class Solution {
public:

    pair<int, bool> helper(TreeNode* root) {

        if(root == NULL) {
            pair<int, bool> p = make_pair(0, true);
            return p;
        }

        pair<int, bool> l = helper(root -> left);
        pair<int, bool> r = helper(root -> right);
        int height = max(l.first, r.first) + 1;
        bool balanced = false;

        if(abs(l.first - r.first) <= 1 && l.second && r.second)
            balanced = true;

        pair<int, bool> ans = make_pair(height, balanced);
        return ans;
    }

    bool isBalanced(TreeNode* root) {
        
        return helper(root).second;
    }
};
