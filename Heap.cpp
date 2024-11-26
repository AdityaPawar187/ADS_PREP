#include <iostream>

using namespace std;

class minHeap
{
public:
    int *marks;
    int size;

    minHeap(int arr[], int n)
    {
        marks = arr;
        size = n;
    }

    void minheapify(int arr[], int n, int i)
    {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        cout << "value of i = " << i << endl;

        if (left < n && arr[left] < arr[smallest])
        {
            smallest = left;
        }

        if (right < n && arr[right] < arr[smallest])
        {
            smallest = right;
        }

        cout << "For now smallest is " << arr[smallest] << endl;

        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);

            for (int k = 0; k < n; k++)
            {
                cout << " | " << arr[k];
            }
            cout << endl;

            minheapify(arr, n, smallest);
            cout << "After recursive call: " << endl;

            for (int k = 0; k < n; k++)
            {
                cout << " | " << arr[k];
            }
            cout << endl;
        }
    }

    int minmark()
    {
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            minheapify(marks, size, i);
        }
        return marks[0];
    }
};

int main()
{
    int n;
    cout << "Enter total students: ";
    cin >> n;
    int arr[n];
    cout << "Enter marks:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    minHeap m(arr, n);
    int min = m.minmark();
    cout << "Min = " << min;
    return 0;
}