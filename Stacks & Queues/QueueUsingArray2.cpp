#include <iostream>
using namespace std;

template <typename T>

// Dynamic Queue
class QueueUsingArray
{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

public:
    QueueUsingArray(int s)
    {
        data = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = s;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void push(T element)
    {
        if (size == capacity)
        {
            T *newData = new T[2 * capacity];
            int j = 0;
            for (int i = firstIndex; i < capacity; i++)
            {
                newData[j] = data[i];
                j++;
            }
            for (int i = 0; i < firstIndex; i++)
            {
                newData[j] = data[i];
                j++;
            }
            delete[] data;
            data = newData;
            firstIndex;
            nextIndex = capacity;
            capacity = 2 * capacity;
        }

        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if (firstIndex == -1)
            firstIndex = 0;
        size++;
    }

    T front()
    {
        if (firstIndex == -1)
        {
            cout << "Queue empty !!";
            return 0;
        }
        return data[firstIndex];
    }

    T pop()
    {
        if (firstIndex == -1)
        {
            cout << "Queue empty !!";
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        if (size == 0)
        {
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }
};

int main()
{
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;
    QueueUsingArray<int> q(size);

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