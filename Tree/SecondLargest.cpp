/************************************************* QUESTION *****************************************************************************/

Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space. Also, value of data at each level is distinct.
Output Format :
The first and only line of output contains data of the node with second largest data.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
40

/************************************************* ANSWER *****************************************************************************/

/************************************************************

    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data) {
            this->data = data;
        }

        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/

pair<TreeNode<int>*, TreeNode<int>*> secondLargest(TreeNode<int>* root) {
    if(root == NULL) {
        return {NULL, NULL};
    }

    TreeNode<int>* first = root;
    TreeNode<int>* second = NULL;

    for(int i = 0; i < root -> children.size(); i++) {
        pair<TreeNode<int>*, TreeNode<int>*> child = secondLargest(root -> children[i]);

        if(child.first -> data > first -> data) {
            if(child.second == NULL || child.second -> data < first -> data) {
                second = first;
                first = child.first;
            }
            else {
                first = child.first;
                second = child.second;
            }
        }
        else {
            if(first -> data != child.first -> data && (second == NULL || child.first -> data > second -> data)) {
                second = child.first;
            }
        }
    }

    return {first, second};
}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here

    if(root == NULL) return NULL;

    return secondLargest(root).second;
}
