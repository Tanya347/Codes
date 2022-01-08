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
};

template <typename T>

class QueueUsingLL
{

    Node<T> *head; // To maintain the front of the Queue
    Node<T> *tail; // To maintain the rear of the queue
    int size;

public:
    QueueUsingLL()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void push(T element)
    {
        Node<T> *newnode = new Node<T>(element);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
            size++;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
            size++;
        }
    }

    int pop()
    {
        if (head == NULL)
            return -1;
        Node<T> *temp;
        temp = head;
        head = head->next;
        temp->next = NULL;
        int pop_data = temp->data;
        size--;
        free(temp);
        return pop_data;
    }

    int front()
    {
        if (head == NULL)
            return -1;
        return head->data;
    }
};

int main()
{
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;
    QueueUsingLL<int> q;

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
            int input;
            cin >> input;
            q.push(input);
            break;
        case 2:
            cout << "Deleted Element: " << q.pop() << "\n";
            break;
        case 3:
            cout << "Front Element: " << q.front() << "\n";
            break;
        case 4:
            cout << "Current Size: " << q.getSize() << "\n";
            break;
        case 5:
            cout << "Queue is " << ((q.isEmpty()) ? "empty\n" : "not empty\n");
            break;
        default:
            cout << "INVALID CHOICE!!";
        }
        cout << "\nPerform more operations? (y/n) : ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
}