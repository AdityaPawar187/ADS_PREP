#include <iostream>
using namespace std;


class HeapOperations {
private:
    int* marks; 
    int size;   

    // Heapify function for Min-Heap
    void minHeapify(int arr[], int n, int i) {
        int smallest = i; 
        cout<<endl<<"value of i="<<i<<endl;
        // Initialize smallest as root
        int left = 2 * i + 1;  // Left child
        int right = 2 * i + 2; // Right child

        // If left child is smaller than root
        if (left < n && arr[left] < arr[smallest])
            smallest = left;

        // If right child is smaller than smallest so far
        if (right < n && arr[right] < arr[smallest])
            smallest = right;

        // If smallest is not root
        cout<<endl<<"smallest element is"<<arr[smallest]<<endl;
        if (smallest != i) {
            swap(arr[i], arr[smallest]);
        cout<<endl;
        for(int k=0;k<n;k++)
        {
            cout<<"|  "<<arr[k]<<"  |";
        }
            // Recursively heapify the affected sub-tree
            cout<<endl<<"affected element is "<<arr[smallest]<<" apply recursive heapify onit"<<endl;      
            minHeapify(arr, n, smallest);
            cout<<endl<<"after recursive call"<<endl;
        for(int k=0;k<n;k++)
        {
            cout<<"|  "<<arr[k]<<"  |";
        }
        }
    }

    // Heapify function for Max-Heap
    void maxHeapify(int arr[], int n, int i) {
        int largest = i;   // Initialize largest as root
         cout<<endl<<"value of i="<<i<<endl;
        int left = 2 * i + 1;  // Left child
        int right = 2 * i + 2; // Right child

        // If left child is larger than root
        if (left < n && arr[left] > arr[largest])
            largest = left;

        // If right child is larger than largest so far
        if (right < n && arr[right] > arr[largest])
            largest = right;
        cout<<endl<<"largest element is"<<arr[largest]<<endl;
        // If largest is not root
        if (largest != i) {
            swap(arr[i], arr[largest]);
         cout<<endl;
        for(int k=0;k<n;k++)
        {
            cout<<"|  "<<arr[k]<<"  |";
        }
        cout<<endl<<"affected element is "<<arr[largest]<<" apply recursive heapify onit"<<endl;
            // Recursively heapify the affected sub-tree
            maxHeapify(arr, n, largest);
         cout<<endl;
        for(int k=0;k<n;k++)
        {
            cout<<"|  "<<arr[k]<<"  |";
        }
        }
    }

public:
    // Constructor to initialize the array and its size
    HeapOperations(int inputMarks[], int n) {
        marks = inputMarks;
        size = n;
    }

    // Function to find minimum marks using Min-Heap
    int findMinMarks() {
        // Build the Min-Heap (heapify all non-leaf nodes)
        for (int i = size / 2 - 1; i >= 0; i--) {
            minHeapify(marks, size, i);
        }
        // The minimum value will be at the root (marks[0])
        return marks[0];
    }

    // Function to find maximum marks using Max-Heap
    int findMaxMarks() {
        // Build the Max-Heap (heapify all non-leaf nodes)
        for (int i = size / 2 - 1; i >= 0; i--) {
            maxHeapify(marks, size, i);
        }
        // The maximum value will be at the root (marks[0])
        return marks[0];
    }
};

int main() {
    // Input: Marks obtained by students in the second year
    int n;
    cout<<"enter number of students in class"<<endl;
    cin>>n;
    int studentMarks[n];
  
   for(int k=0;k<n;k++)
   {
       cout<<"enter the marks of "<<k+1<<" th student"<<endl;
       cin>>studentMarks[k];
   }

    // Create an object of the HeapOperations class
    HeapOperations heapOps(studentMarks, n);

    // Find and display the minimum marks
    int minMarks = heapOps.findMinMarks();
    cout <<endl<< "Minimum Marks: " << minMarks << endl;

    // Find and display the maximum marks
    int maxMarks = heapOps.findMaxMarks();
    cout <<endl<< "Maximum Marks: " << maxMarks << endl;

    return 0;
}
