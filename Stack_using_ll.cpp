#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{
public:
    Node *top;

    Stack()
    {
        top = nullptr;
    }

    void push()
    {
        Node *newNode = new Node();
        cout << "Enter the number to insert into the stack: ";
        cin >> newNode->data;
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Underflow";
        }
        else
        {
            Node *temp = top;
            int data = temp->data;
            top = top->next;
            delete temp;
            cout << data << " deleted from stack" << endl;
        }
    }

    void peek()
    {
        if (!isEmpty())
        {
            cout << top->data << " is the peek Element" << endl;
        }
    }

    bool isEmpty()
    {
        if (top == nullptr)
        {
            return true;
        }
        else
        {
            return false;
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
            Node *i = top;
            while (i->next != nullptr)
            {
                cout << i->data << endl;
                i = top->next;
            }
            cout << i->data << endl;
            i = top->next;
        }
    }
};

int main()
{
    Stack s;
    int choice;
    do
    {
        cout << "\nEnter \n1 for Push \n2 for Pop \n3 for Peek \n4 for display \n5 for exit\nChoice: ";
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
