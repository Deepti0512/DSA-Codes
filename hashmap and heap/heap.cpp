#include <bits/stdc++.h>
using namespace std;

class max_heap
{
public:
    int arr[100];
    int size;
    max_heap()
    {
        this->size = 0;
        this->arr[0] = -1;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    int peek()
    {
        return arr[1];
    }
    void Delete()
    {
        if (size == 0)
        {
            cout << "Underflow Error" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i < size)
        {
            int leftChild = 2 * i;
            int rightChild = 2 * i + 1;

            int large;

            if (leftChild <= size && rightChild <= size)
            {
                large = arr[leftChild] < arr[rightChild] ? rightChild : leftChild;
            }

            if (arr[i] < arr[large])
            {
                swap(arr[i], arr[large]);
                i = large;
            }
            else
            {
                return;
            }
        }
    }
};
// Heapify Algorithm
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }
    // if largest is modified then place it at the right position
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }
}
void print(int arr[], int n)
{

    for (int i = 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
void test()
{
    max_heap h;
    h.insert(35);
    h.insert(32);
    h.insert(40);
    h.insert(25);
    h.insert(30);
    h.print();
    h.Delete();
    h.print();
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    int m = sizeof(arr) / sizeof(arr[0]);
    print(arr,m);
    heapSort(arr, n);
    print(arr,m);
}
int main()
{
    test();
    return 0;
}