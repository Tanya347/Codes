#include <iostream>
#include <queue>
#include <climits>
using namespace std;

// Implementation of Binary Tree
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

/*********************************  PRINT AND TAKE INPUT  ***********************************/

// Take input recursively
BinaryTreeNode<int> *takeInputRecursive()
{
    int data;

    cin >> data;
    BinaryTreeNode<int> *root;
    if (data != -1)
        root = new BinaryTreeNode<int>(data);
    else
        return NULL;
    cout << "Enter left child of " << data << endl;
    root->left = takeInputRecursive();
    cout << "Enter right child of " << data << endl;
    root->right = takeInputRecursive();

    return root;
}

// Print the tree recursively
void printTreeRecursive(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " : ";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data;
    }

    if (root->right != NULL)
    {
        cout << " R" << root->right->data;
    }
    cout << endl;
    printTreeRecursive(root->left);
    printTreeRecursive(root->right);
}

// Take input level wise
BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;

    if (rootData == -1)
        return NULL;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> nodes;
    nodes.push(root);

    while (!nodes.empty())
    {
        BinaryTreeNode<int> *parent = nodes.front();
        nodes.pop();

        int leftData, rightData;
        cout << "Enter left child data of " << parent->data << endl;
        cin >> leftData;
        if (leftData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftData);
            parent->left = leftChild;
            nodes.push(leftChild);
        }

        cout << "Enter right child data of " << parent->data << endl;
        cin >> rightData;
        if (rightData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightData);
            parent->right = rightChild;
            nodes.push(rightChild);
        }
    }

    return root;
}

// print the tree level wise
void printLevelWise(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> nodes;
    nodes.push(root);

    while (!nodes.empty())
    {
        BinaryTreeNode<int> *parent = nodes.front();
        nodes.pop();

        cout << parent->data << ":";
        if (parent->left != NULL)
        {
            BinaryTreeNode<int> *leftChild = parent->left;
            cout << "L:" << leftChild->data << ",";
            nodes.push(leftChild);
        }
        else
        {
            cout << "L:-1"
                 << ",";
        }

        if (parent->right != NULL)
        {
            BinaryTreeNode<int> *rightChild = parent->right;
            cout << "R:" << rightChild->data;
            nodes.push(rightChild);
        }
        else
        {
            cout << "R:-1";
        }

        cout << endl;
    }
}

/*********************************  PROPERTIES OF TREES  ***********************************/

// Counts the number of nodes
int countNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    return countNodes(root->left) + countNodes(root->right) + 1;
}

// checks if a data value is preset in the tree or not
bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
    if (root == NULL)
        return false;

    if (root->data == x)
        return true;

    return isNodePresent(root->left, x) || isNodePresent(root->right, x);
}

// Height of the binary tree
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

// Diameter of Binary Tree using pure recursion
int diameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return max(option1, max(option2, option3));
}

// Diamter of Binary Tree using pairs
pair<int, int> diameterBetter(BinaryTreeNode<int> *root)
{
    pair<int, int> hd;
    if (root == NULL)
    {
        hd = make_pair(0, 0);
        return hd;
    }

    pair<int, int> leftAns = diameterBetter(root->left);
    pair<int, int> rightAns = diameterBetter(root->right);
    int lh = leftAns.first, ld = leftAns.second;
    int rh = rightAns.first, rd = rightAns.second;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));

    hd = make_pair(height, diameter);
    return hd;
}

// Function to make a mirror of the Binary Tree
void mirrorBinaryTree(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return;

    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);

    BinaryTreeNode<int> *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

// function to find max and min both of a tree
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root)
{

    pair<int, int> minmax;
    // Base case
    if (root == NULL)
    {
        minmax = make_pair(INT_MAX, 0);
        return minmax;
    }

    pair<int, int> leftMinmax = getMinAndMax(root->left);
    pair<int, int> rightMinmax = getMinAndMax(root->right);

    int minimum = min(root->data, min(leftMinmax.first, rightMinmax.first));
    int maximum = max(root->data, max(leftMinmax.second, rightMinmax.second));

    minmax = make_pair(minimum, maximum);
    return minmax;
}

/*********************************  TRAVERSALS  ***********************************/

// inorder
void inorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// preorder
void preorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    inorder(root->left);
    inorder(root->right);
}

// postorder
void postorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    inorder(root->right);
    cout << root->data << " ";
}

/*********************************  MENU OF TREE  ***********************************/

int main()
{
    // BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
    // root->left = node1;
    // root->right = node2;

    // cout << "Enter root data" << endl;
    // BinaryTreeNode<int> *root = takeInputRecursive();
    // cout << endl;
    // printTreeRecursive(root);

    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTreeRecursive(root);
    // cout << "\nNumber of nodes : " << countNodes(root) << endl;
    cout << "\nDiameter of Tree : " << diameterBetter(root).second << endl;
}

// 1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
// 1 2 3 4 5 -1 -1 6 7 -1 10 -1 -1 8 -1 11 12 -1 9 -1 -1 13 -1 -1 -1 -1 -1
