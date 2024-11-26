#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Queue
{
public:
    Node *front;
    Node *rear;

    Queue()
    {
        rear = nullptr;
        front = nullptr;
    }

    bool isEmpty()
    {
        if (front == nullptr && rear == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue()
    {
        Node *newNode = new Node();
        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enter the number to insert into the queue: ";
        cin >> rear->data;
        rear->next = nullptr;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
        }
        else if (front == rear)
        {
            Node *temp = front;
            int data = temp->data;
            delete temp;
            front = nullptr;
            rear = nullptr;
            cout << data << " is deleted" << endl;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            int data = temp->data;
            delete temp;
            cout << data << " is deleted from queue" << endl;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            Node *i = front;
            while (i->next != nullptr)
            {
                cout << i->data << "<--";
                i = i->next;
            }
            cout << i->data;
        }
    }
};

int main()
{
    Queue q;
    int choice;
    do
    {
        cout << "\nEnter \n1 for enqueue \n2 for dequeue \n3 for display \n4 for exit \nChoice: ";
        cin >> choice;
        switch (choice)
        {

        case 1:
            q.enqueue();
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            break;

        default:
            cout << "Invalid";
        }
    } while (choice != 4);
    return 0;
}