#include <iostream>
using namespace std;

// IMPLEMENTING THE CLASS LINKED LIST

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// PRINT FUNCTION TO PRINT THE LINKED LIST

void print(Node *head)
{
    if (head == NULL)
    {
        cout << "Linked List Empty";
        return;
    }
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// INPUT FUNCTION THAT CREATES A LINKED LIST

Node *Input()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
        }
        cin >> data;
    }

    return head;
}

// ITERATIVE APPROACH TO INSERT A NODE AT A GIVEN POSITION

void InputNode(Node **head, int i, int data)
{
    Node *temp = *head;
    Node *newnode = new Node(data);
    int count = 0;
    if (head == NULL)
    {
        *head = newnode;
    }
    if (i == 1)
    {
        newnode->next = temp;
        *head = newnode;
    }
    while (count < i - 2 && temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    if (temp != NULL)
    {
        Node *a = temp->next;
        temp->next = newnode;
        newnode->next = a;
    }
}

// RECURSIVE APPROACH

/*
Node *InputNode(Node *head, int i, int data)
{
    if (head == NULL)
        return head;

    if (i == 1)
    {
        Node *NewNode = new Node(data);
        NewNode->next = head;
        head = NewNode;
    }
    else
        head->next = InputNode(head->next, i - 1, data);
    return head;
}*/

// ITERATIVE APPROACH TO DELETE A NODE AT A GIVEN POSITION

void deleteNode(Node **head, int i)
{
    if (head == NULL)
    {
        return;
    }

    Node *temp = *head;

    if (i == 1)
    {
        *head = temp->next;
        delete temp;
    }

    int count = 0;
    while (count < i - 2 && temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        cout << "Node doesn't exist";
        return;
    }
    if (temp != NULL)
    {
        Node *a = temp->next;
        temp->next = a->next;
        delete a;
    }
}

// RECURSIVE APPROACH

/*
Node *deleteNode(Node *head, int pos)
{
    if (head == NULL)
    {
        return head;
    }
    if (pos == 1)
    {
        head = head->next;
        return head;
    }
    head->next = deleteNode(head->next, pos - 1);
    return head;
}*/

// ITERATIVE APPROACH TO FIND THE LENGTH OF A LINKED LIST

int LengthLL(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// RECURSIVE APPROACH

/*
int LengthLL(Node *head)
{
    Node *temp = head;
    if (head == NULL)
        return 0;
    else
        return 1 + LengthLL(temp->next);
}*/

// PRINTING THE NODE DATA AT THE ITH POSITION

void printIthNode(Node *head, int i)
{
    int count = 0;
    Node *temp = head;
    if (temp == NULL)
        return;
    while (count < i - 1 && temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    if (count < i - 1)
    {
        cout << "Node doesn't exist \n";
        return;
    }
    else
        cout << "Data at node " << i << " is: " << temp->data;
}

// FINDING THE POSITION OF A GIVEN NODE

int findNode(Node *head, int n)
{
    if (head == NULL || head->next == NULL)
        return -1;

    if (head->data == n)
        return 1;

    int pos = findNode(head->next, n);

    if (pos == -1)
        return -1;
    else
        return pos + 1;
}

int main()
{

    cout << "LINKED LIST MENU" << endl;
    cout << "1. Create Linked List" << endl;
    cout << "2. Print Linked List" << endl;
    cout << "3. Insert Element at a Position" << endl;
    cout << "4. Delete Element at a Position" << endl;
    cout << "5. Length of LL" << endl;
    cout << "6. View Node at ith Position" << endl;
    cout << "7. Find Position of a Node" << endl;
    cout << endl;
    int choice;
    char ch;
    Node *head = NULL;
    do
    {
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter linked list data: ";
            head = Input();
            break;
        case 2:
            print(head);
            break;
        case 3:
            if (head == NULL)
            {
                cout << "Enter the data of the new node :";
                int data;
                cin >> data;
                InputNode(&head, 1, data);
                cout << "\nLinked list now is: ";
                print(head);
            }
            else
            {
                cout << "Enter the data of the new node :";
                int data;
                cin >> data;
                cout << "Enter the node position :";
                int pos1;
                cin >> pos1;
                InputNode(&head, pos1, data);
                // head = InputNode(head, pos1, data);
                cout << "\nLinked list now is: ";
                print(head);
            }
            break;
        case 4:
            if (head == NULL)
                cout << "Linked List Empty";
            else
            {
                if (LengthLL(head) == 1)
                {
                    deleteNode(&head, 1);
                    cout << "Linked List is Now Empty";
                }
                else
                {
                    cout << "Enter the node position :";
                    int pos2;
                    cin >> pos2;
                    // head = deleteNode(head, pos2);
                    deleteNode(&head, pos2);
                    cout << "\nLinked list now is: ";
                    print(head);
                }
            }
            break;
        case 5:
            cout << "Length of LL is: " << LengthLL(head) << endl;
            break;
        case 6:
            if (head == NULL)
                cout << "Linked List Empty";
            else
            {
                cout << "Enter the node position :";
                int pos3;
                cin >> pos3;
                printIthNode(head, pos3);
            }
            break;
        case 7:
            if (head == NULL)
                cout << "Linked List Empty";
            else
            {
                cout << "Enter the node you want to find:";
                int node;
                cin >> node;
                int position = findNode(head, node);
                if (position == -1)
                    cout << "Node doesn't exist";
                else
                    cout << "Node found at position: " << position << endl;
            }
            break;
        Default:
            cout << "Invalid Choice !";
        }
        cout << endl;
        cout << "Want to perform more operations ? (y/n) :";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}