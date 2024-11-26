#include <iostream>

using namespace std;

class Queue
{
public:
    int arr[5];
    int front = -1;
    int rear = -1;
    int size = 5;

    bool isEmpty()
    {
        if (rear == -1 && front == -1)
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
        if (((rear + 1) % size) == front)
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
        if (isFull())
        {
            cout << "Queue is Full" << endl;
            return;
        }
        else if (front == -1 && rear == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        cout << "Enter the number to insert into the queue: ";
        cin >> arr[rear];
    }

    void dequeue()
    {
        int data;
        if (isEmpty())
        {
            cout << "Queue is Empty can't pop" << endl;
        }
        else if (front == rear)
        {
            data = arr[front];
            front = rear = -1;
        }
        else
        {
            data = arr[front];
            front = (front + 1) % size ;
        }
        cout << data << " is deleted from queue" << endl;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            if (rear >= front)
            {
                for (int i = front; i <= rear; i++)
                {
                    cout << arr[i] << "<--";
                }
            }
            if (front > rear)
            {
                for (int i = front; i <= size - 1; i++)
                {
                    cout << arr[i] << "<--";
                }
                for (int j = 0; j <= rear; j++)
                {
                    cout << arr[j] << "<--";
                }
            }
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
