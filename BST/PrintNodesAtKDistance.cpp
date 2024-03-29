/************************************************* QUESTION *****************************************************************************/

You are given a Binary Tree of type integer, a target node, and an integer value K.
Print the data of all nodes that have a distance K from the target node. The order in which they would be printed will not matter.
Example:
For a given input tree(refer to the image below):
1. Target Node: 5
2. K = 2
alt txt

Starting from the target node 5, the nodes at distance K are 7 4 and 1.
Input Format:
The first line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

The second line of input contains two integers separated by a single space, representing the value of the target node and K, respectively.
Output Format:
All the node data at distance K from the target node will be printed on a new line.

The order in which the data is printed doesn't matter.
Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
3 1
Sample Output 1:
9
6
Sample Input 2:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
3 3
Sample Output 2:
4
5

/************************************************* ANSWER *****************************************************************************/

void printNodesAtDepth(BinaryTreeNode<int> *root, int depth) {
    
    if(root == NULL or depth < 0)
        return;
    
    if(depth == 0)
        cout<<root -> data<<endl;
    
    printNodesAtDepth(root -> left, depth -1);
    printNodesAtDepth(root -> right, depth -1);
}

int print(BinaryTreeNode<int> *root, int node, int k) {
    
    if(root == NULL)
        return -1;
    
    if(root -> data == node) {
        printNodesAtDepth(root, k);
        return 0;
    }
    
    int leftDistance = print(root -> left, node, k);
    
    if(leftDistance != -1) {
        
    if(leftDistance + 1 == k)
        cout<< root -> data << endl;
    
    else printNodesAtDepth(root -> right, k - leftDistance - 2);
        
        return leftDistance + 1;
    }
    
    
    int rightDistance = print(root -> right, node, k);
    
    if(rightDistance != -1) {
        
    if(rightDistance + 1 == k)
        cout<< root -> data << endl;
    
    else printNodesAtDepth(root -> left, k - rightDistance - 2);
        
        return rightDistance + 1;
    }
    
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code herez
    
    print (root, node, k);
}
