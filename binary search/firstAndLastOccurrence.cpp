#include <iostream>
using namespace std;

int firstOcc(int arr[], int n, int key)
{
    int ans = -1;
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (key < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int lastOcc(int arr[], int n, int key)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (key < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main()
{
    int arr[] = {1, 1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 8, 9, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << firstOcc(arr, n, 3) << "\n";
    cout << lastOcc(arr, n, 3) << "\n";
    return 0;
}