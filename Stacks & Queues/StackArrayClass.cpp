#include <iostream>
#include <climits>
using namespace std;

template <typename T>
class StackArrayClass
{
private:
    T *data;       // Dynamically Allocated Array for storing the stack
    int nextIndex; // the index of the topmost element
    int capacity;  // the total size of the stack

public:
    StackArrayClass(int size)
    {
        data = new T[size];
        nextIndex = 0;
        capacity = size;
    }

    // return current size of the stack

    int getSize()
    {
        return nextIndex;
    }

    // checks whether array is empty or not

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    // insert element into the stack

    void push(T element)
    {
        if (nextIndex == capacity)
        {
            /*cout<< "Stack full"<<endl;
            return;*/

            T *newData = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
                capacity = 2 * capacity;
                delete[] data;
                data = newData;
            }
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    // delete element from stack

    T pop()
    {

        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    // top element

    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }
};

// 5 y 1 8 y 1 4 y 1 3 y 3 y 2 y 4 y 5

int main()
{
    cout << "Enter the size of the stack you want to create: " << endl;
    int size;
    cin >> size;
    StackArrayClass<int> st(size);

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
        cout << "\nEnter your choice: \n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element you want to insert: ";
            int element;
            cin >> element;
            st.push(element);
            break;
        case 2:
            cout << "The deleted Element: " << st.pop() << "\n";
            break;
        case 3:
            cout << "The top Element: " << st.top() << "\n";
            break;
        case 4:
            cout << "The current Size: " << st.getSize() << "\n";
            break;
        case 5:
            cout << "The array is " << ((st.isEmpty()) ? "Empty\n" : "Non-Empty\n");
            break;
        default:
            cout << "INVALID CHOICE!!";
        }
        cout << "\nPerform more operations? (y/n) : ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
}
