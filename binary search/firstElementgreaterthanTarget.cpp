#include <bits/stdc++.h>
using namespace std;

// this function returns first occurence of the target itself if found or the first greater element otherwise
// and if all elements are strictly less than given number then it returns -1
int firstElementGreaterThanEqualtoTarget(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    int ans = -1;
    int mid = low + (high - low) / 2;
    while (low < high)
    {
        if (arr[mid] >= target)
        {
            ans = mid;
            high = mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        mid = low + (high - low) / 2;
    }
    if(high == low && arr[low] >= target && ans == -1)ans = low;
    return ans;
}

// method 2 : use STL upper bound function
int upperBound(int arr[], int n, int target)
{
    int *ptr = upper_bound(arr, arr + n, target);
    if (ptr == arr + n){
        return -1;
    }
    else
    {
        cout << "The first element greater is " << *ptr << " at position " << ptr - arr << "\n";
        return ptr - arr;
    }
}

int main()
{
    int arr[] = {7, 7, 7, 8, 8, 10, 11, 12, 13, 13, 13, 15, 18, 20, 25, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = firstElementGreaterThanEqualtoTarget(arr, n, 13);
    cout << ans << "\n";
    int ans2 = upperBound(arr, n, 13);
    int a[2] = {1,7};
    cout<<firstElementGreaterThanEqualtoTarget(a,2,2)<<"\n";
    return 0;
}