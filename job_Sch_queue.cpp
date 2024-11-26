#include <iostream>
#include <string>

using namespace std;

class job_fcfs
{
    private:
        string jobs[100];
        int front = -1;
        int rear = -1;
    public:

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
        if (rear == 99)
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
            cout<<"Queue is full"<<endl;
            return;
        }
        else if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear += 1;
        }
        cout<<"Enter the job name to insert into the queue: ";
        cin>>jobs[rear];
        cout<<endl;
    }

    void dequeue()
    {
        string data[1];
        if (isEmpty())
        {
            cout<<"No jobs to delete"<<endl;
            return;
        }
        else if (front == rear)
        {
            data[0] = jobs[front];
            front = -1;
            rear = -1;
        }
        else
        {
            data[0]= jobs[front];
            front += 1;
        }
        cout<<data[0]<<" is deleted from queue"<<endl<<endl;
    }

    void display()
    {
        if (isEmpty())
        {
            cout<<"No jobs found"<<endl<<endl;
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout<<jobs[i]<<"<--";
            }
        }
    }
};

int main()
{
    job_fcfs q;
    int choice;

    do
    {
        cout << "\nEnter \n1 for Insert job \n2 for Delete job \n3 for Display jobs \n4 for Exit" << endl;
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
            cout << "Exiting the queue";
            break;

        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    } while (choice != 4);
    return 0;
}