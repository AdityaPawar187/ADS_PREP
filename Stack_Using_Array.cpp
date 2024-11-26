#include <iostream>

using namespace std;

class Stack
{
public:
    int arr[5];
    int size = 5;
    int top = -1;

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if (top == size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push()
    {
        if (isFull())
        {
            cout << "Stack is Overflow" << endl;
        }
        else
        {
            top += 1;
            cout << "Enter the number to insert into the stack: ";
            cin >> arr[top];
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is UnderFlow" << endl;
        }
        else
        {
            int data;
            data = arr[top];
            top -= 1;
            cout << data << " is deleted from the stack" << endl;
        }
    }

    void peek()
    {
        if (!isEmpty())
        {
            cout << arr[top] << " is the peek element" << endl;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << "\n";
            }
        }
    }
};

int main()
{
    Stack s;
    int choice;
    do
    {
        cout << "Enter \n1 for Push \n2 for Pop \n3 for Peek \n4 for display \n5 for exit\nChoice: ";
        cin >> choice;
        switch (choice)
        {

        case 1:
            s.push();
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            s.display();
            break;

        case 5:
            break;

        default:
            cout << "Invalid";
        }
    } while (choice != 5);
    return 0;
}
