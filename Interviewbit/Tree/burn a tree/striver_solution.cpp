/*

Problem Description

Given a binary tree denoted by root node A and a leaf node B from this tree.

 It is known that all nodes connected to a given node (left child, right child and parent) get burned in 1 second. Then all the nodes which are connected through one intermediate get burned in 2 seconds, and so on.

You need to find the minimum time required to burn the complete binary tree.



Problem Constraints

2 <= number of nodes <= 105

1 <= node value, B <= 105

node value will be distinct



Input Format

First argument is a root node of the binary tree, A.

Second argument is an integer B denoting the node value of leaf node.



Output Format

Return an integer denoting the minimum time required to burn the complete binary tree.


Example Input

Input 1:

 Tree :      1 
            / \ 
           2   3 
          /   / \
         4   5   6
 B = 4

Input 2:

 Tree :      1
            / \
           2   3
          /     \
         4       5 
 B = 5 



Example Output

Output 1:

 4

Output 2:

 4



Example Explanation

Explanation 1:

 After 1 sec: Node 4 and 2 will be burnt. 
 After 2 sec: Node 4, 2, 1 will be burnt.
 After 3 sec: Node 4, 2, 1, 3 will be burnt.
 After 4 sec: Node 4, 2, 1, 3, 5, 6(whole tree) will be burnt.
 

Explanation 2:

 After 1 sec: Node 5 and 3 will be burnt. 
 After 2 sec: Node 5, 3, 1 will be burnt.
 After 3 sec: Node 5, 3, 1, 2 will be burnt.
 After 4 sec: Node 5, 3, 1, 2, 4(whole tree) will be burnt.
 

*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
/********************************************************************** SOLUTION **************************************************************************************/ 



//this solution will also work when node is not a leaf node 






int findTime(map<TreeNode*, TreeNode*>& parents, TreeNode* start) {
    
    //queue to perform bfs again
    queue<TreeNode*> q;
    q.push(start);
    
    //map to store whether a node was visited
    map<TreeNode*, int> visited;
    visited[start] = 1;
    
    int time = 0;
    
    while(!q.empty()) {
        //since there can be simultaneously many nodes burnt at the same time
        //we need to look at all of them in one iteration
        
        int n = q.size();
        
        //if now neighbors burned then we don't need to increment time
        int neighbors_burned = 0;
        
        for(int i = 0; i < n; i++) {
            TreeNode* top = q.front();
            q.pop();
            
            //check for left node
            if(top -> left && !visited[top -> left]) {
                neighbors_burned = 1;
                q.push(top -> left);
                visited[top -> left] = 1;
            }
            
            //check for right node
            if(top -> right && !visited[top -> right]) {
                neighbors_burned = 1;
                q.push(top -> right);
                visited[top -> right] = 1;
            }
            
            //check for parent node
            if(parents[top] && !visited[parents[top]]) {
                neighbors_burned = 1;
                q.push(parents[top]);
                visited[parents[top]] = 1;
            }
            
        }
        
        //if neighbors were burned then increment time
        if(neighbors_burned) time++;
    }
    
    return time;
}
 
TreeNode* mapParent(TreeNode* root, map<TreeNode*, TreeNode*>& parents, int start) {
    
    //queue to perform level wise traversal
    queue<TreeNode*> q;
    q.push(root);
    
    //node that stores the starting node
    TreeNode* node;
    
    while(!q.empty()) {
        //extract first node present in queue
        TreeNode* top = q.front();
        q.pop();
        
        //if the node is found store it
        if(top -> val == start)
        node = top;
        
        //if left child exists push into queue and also store it in map with parent as top
        //same for right child
        if(top -> left) {
            q.push(top -> left);
            parents[top -> left] = top;
        }
        
        if(top -> right) {
            q.push(top -> right);
            parents[top -> right] = top;
        }
    }
    
    return node;
}
 
int Solution::solve(TreeNode* root, int start) {
    //make a map to store the parents of every TreeNode
    map<TreeNode*, TreeNode*> parents;
    
    //call function to store parents and also to return the node that contains the start value
    TreeNode* node = mapParent(root, parents, start);
    
    //call function to return time to taken to burn the tree
    return findTime(parents, node);
}
