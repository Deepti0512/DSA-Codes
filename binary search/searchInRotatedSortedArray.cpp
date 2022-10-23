// Find given element in a rotated sorted array
// find the index of the min element (pivot) and then search in right or left half according to binary search logic
// eg [7,9,1,3,5] ==> {7,9} & {1,3,5} --> these two halfes are sorted and the element maybe present in one of these.
// to find which part is to be searched just find the pivot(min element) and then search in the segment accordingly.
#include <bits/stdc++.h>
using namespace std;

int getPivot(vector<int> &nums)
{
    int n = nums.size();
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    while (start < end)
    {
        if (nums[mid] >= nums[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    // final check which value is smaller
    return nums[start] < nums[0] ? start : 0;
}
int binarySearch(vector<int> &arr, int start, int end, int key)
{
    int n = arr.size();
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
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
    return -1;
}
int search(vector<int> &nums, int key)
{
    int pivotIndex = getPivot(nums);
    int n = nums.size();
    if (key >= nums[pivotIndex] && key <= nums[n - 1])
    {
        return binarySearch(nums, pivotIndex, n - 1, key);
    }
    else
    {
        return binarySearch(nums, 0, pivotIndex - 1, key);
    }
}
void test()
{
    vector<int> arr(5);
    arr[0] = 7;
    arr[1] = 9;
    arr[2] = 1;
    arr[3] = 3;
    arr[4] = 5;
    cout << search(arr, 1) << "\n";
    cout << search(arr, 7) << "\n";
    cout << search(arr, 5) << "\n";
    cout << search(arr, 2) << "\n";
    cout << search(arr, 9) << "\n";
}
int main()
{
    test();
    return 0;
}