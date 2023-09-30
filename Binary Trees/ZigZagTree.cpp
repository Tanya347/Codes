/************************************************* QUESTION *****************************************************************************/

Given a binary tree, print the zig zag order. In zigzag order, level 1 is printed from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output Format:
The binary tree is printed level wise, as described in the task. Each level is printed in new line.
Constraints
Time Limit: 1 second
Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
5
10 6
2 3
9

/************************************************* ANSWER *****************************************************************************/

void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
	int level = 0;

	queue<BinaryTreeNode<int>*> nodes;
	nodes.push(root);

	while(!nodes.empty()) {

		vector<int> temp;
		int s = nodes.size();
		
		while(s--) {
			BinaryTreeNode<int>* top = nodes.front();
			nodes.pop();

			temp.push_back(top -> data);

			if(top -> left != NULL)
				nodes.push(top -> left);

			if(top -> right != NULL)
				nodes.push(top -> right);
		}

		if(level % 2 == 0) {
			for(int i = 0; i < temp.size(); i++)
				cout<<temp[i]<<" ";
		}
		else {
			for(int i = temp.size() - 1; i >= 0; i--)
				cout<<temp[i]<<" ";
		}
		cout<<endl;

		level++;
	}
}
