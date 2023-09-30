/************************************************* QUESTION *****************************************************************************/

Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format :
Each level linked list is printed in new line (elements are separated by space).
Constraints:
Time Limit: 1 second
Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
5 
6 10 
2 3 
9

/************************************************* ANSWER *****************************************************************************/

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here

	if(root == NULL)
		return {};

	queue<BinaryTreeNode<int>*> nodes;

	nodes.push(root);

	vector<Node<int>*> ans;

	while(!nodes.empty()) {

		int s = nodes.size();

		Node<int>* head = NULL;
		Node<int>* tail = NULL;

		while(s--) {
			BinaryTreeNode<int>* top = nodes.front();
			nodes.pop();
			Node<int>* newNode = new Node<int>(top -> data);
			if(head == NULL) {
				head = newNode;
				tail = newNode;
			}
			else {
				tail -> next = newNode;
				tail = newNode;
			}

			if(top -> left != NULL)
				nodes.push(top -> left);
			
			if(top -> right != NULL)
				nodes.push(top -> right);
		}

		ans.push_back(head);
	}

	return ans;
}
