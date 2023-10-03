/************************************************* QUESTION *****************************************************************************/

/*
Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
Note:
1. Assume the given binary tree contains all unique elements.
2. In a pair, print the smaller element first. Order of different pairs doesn't matter.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line of input contains an integer, that denotes the value of S.
Output Format :
Print each pair in a new line, as described in the task. 
Constraints:
Time Limit: 1 second
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
15
Sample Output 1:
5 10
6 9
*/

/************************************************* ANSWER 1 *****************************************************************************/

#include<stack>

int countNodes(BinaryTreeNode<int> *root) {
    if(root == NULL)
        return 0;
    
    return countNodes(root -> left) + countNodes(root -> right) + 1;
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    // Write your code here
    
    if(root == NULL)
        return;
    
    int totalCount = countNodes(root);
    int count = 0;
    
    stack<BinaryTreeNode<int>*> inorder;
    stack<BinaryTreeNode<int>*> revInorder;
    
    BinaryTreeNode<int>* currentNode = root;
    
    while(currentNode != NULL) {
        inorder.push(currentNode);
        currentNode = currentNode -> left;
    }
    
    currentNode = root;
    
    while(currentNode != NULL) {
        revInorder.push(currentNode);
        currentNode = currentNode -> right;
    }
    
    while(count < totalCount - 1) {
        BinaryTreeNode<int>* inorderTop = inorder.top();
        BinaryTreeNode<int>* revInorderTop = revInorder.top();
        
        if(inorderTop -> data + revInorderTop -> data == s){
            cout<< inorderTop -> data << " " << revInorderTop -> data <<endl;
            
            BinaryTreeNode<int> *top = inorderTop;
            inorder.pop();
            count++;
            
            if(top -> right != NULL) {
                top = top -> right;
                while(top != NULL) {
                    inorder.push(top);
                    top = top -> left;
                }
            }
        }
            
        else if(inorderTop -> data + revInorderTop -> data > s) {
                BinaryTreeNode<int> *top = revInorderTop;
                revInorder.pop();
                count++;
                
                if(top -> left != NULL) {
                    top = top -> left;
                    while(top != NULL) {
                        revInorder.push(top);
                        top = top -> right;
                    }
                }
        }
                
            else {
                BinaryTreeNode<int> *top = inorderTop;
                inorder.pop();
                count++;
                
                if(top -> right != NULL) {
                    top = top -> right;
                    while(top != NULL) {
                        inorder.push(top);
                        top = top -> left;
                    }
                }
            }
        }
}

/************************************************* ANSWER 2 *****************************************************************************/

#include<algorithm>

void PrintPairSum(vector<int> TreeEle, int sum) {
    
    sort(TreeEle.begin(), TreeEle.end());
    
    int i = 0 , j = TreeEle.size()-1 ;
    
    while( i < j )
    {
        if( TreeEle[i] + TreeEle[j] == sum){
                cout << TreeEle[i] << " " << TreeEle[j];
                cout << endl;
                i++;
                j--;
        }
        
        else if( TreeEle[i] + TreeEle[j] > sum)
            j--;  
        
        else if( TreeEle[i] + TreeEle[j] < sum)
            i++;
            
    }
}

vector<int> convertIntoArray(BinaryTreeNode<int> *root) {
    
   vector<int> Elements;
    
   if(root == NULL)
        return Elements;
    
   Elements.push_back(root -> data);
    
   int j = 0, k = 0;
    
   vector<int> leftEle = convertIntoArray(root -> left);
    
   vector<int> rightEle = convertIntoArray(root -> right);
    
   for(int i = 0; i < leftEle.size(); i++)
       Elements.push_back(leftEle[j++]);
    
   for(int i = 0; i < rightEle.size(); i++)
       Elements.push_back(rightEle[k++]);
    
   return Elements;
}

void printNodesSumToS(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    
    if(root == NULL )
    return;
    
    vector<int> Elements;
    Elements = convertIntoArray(root);
    
    PrintPairSum(Elements, sum);
    
}
