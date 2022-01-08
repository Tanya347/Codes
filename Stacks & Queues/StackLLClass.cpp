#include <iostream>
using namespace std;

template <typename T>

class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
    ~Node()
    {
        delete next;
    }
};

template <typename T>

class StackUsingLL
{

    Node<T> *head; // head that stores the stack
    int size;

public:
    StackUsingLL()
    {
        head = NULL;
        size = 0;
    }

    // Return the current size of the stack
    int getSize()
    {
        return size;
    }

    // Check whether stack is empty or not
    bool isEmpty()
    {
        return head == NULL;
    }

    // Insert element at the end of the list
    void push(T element)
    {
        Node<T> *newnode = new Node<T>(element);
        if (head == NULL)
        {
            head = newnode;
            size++;
        }
        else
        {
            newnode->next = head;
            head = newnode;
            size++;
        }
    }

    // Pop element from stack
    int pop()
    {
        if (head == NULL)
        {
            cout << "Stack is Empty\n";
            return -1;
        }
        Node<T> *temp;
        temp = head;
        head = head->next;
        temp->next = NULL;
        int pop_data = temp->data;
        size--;
        free(temp);
        return pop_data;
    }

    int top()
    {
        if (head == NULL)
        {
            cout << "Stack is Empty\n";
            return -1;
        }
        return head->data;
    }
};

// 1 8 y 1 9 y 4 y 2 y 3 y 1 7 y 1 9 y 3 y 5
int main()
{
    StackUsingLL<int> st;
    cout << "MENU" << endl;
    cout << "1. INSERT ELEMENT" << endl;
    cout << "2. POP ELEMENT" << endl;
    cout << "3. DISPLAY TOP ELEMENT" << endl;
    cout << "4. SIZE" << endl;
    cout << "5. CHECK EMPTY OR NOT" << endl;
    int choice;
    char ch;
    do
    {
        cout << "\nInsert Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Insert Element: ";
            int element;
            cin >> element;
            st.push(element);
            break;
        case 2:
            cout << "Deleted Element: " << st.pop() << "\n";
            break;
        case 3:
            cout << "Top Element: " << st.top() << "\n";
            break;
        case 4:
            cout << "Current Size: " << st.getSize() << "\n";
            break;
        case 5:
            cout << "Stack is " << ((st.isEmpty()) ? "empty\n" : "not empty\n");
            break;
        default:
            cout << "INVALID CHOICE!!";
        }
        cout << "\nPerform more operations? (y/n) : ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
}