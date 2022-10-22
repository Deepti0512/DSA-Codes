// Problem link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
#include <bits/stdc++.h>
using namespace std;

// note: the following approach works perfect if the array is rotated atleast once
// but if we have a testcase when the no.of rotations is either 0 or is multiple of total array elements, i.e
// when the array is already sorted and min lies at index 0, nums[start] won't give the right answer.
// To prevent this, we have made a final check (compare nums[start] and nums[0])
int findMin(vector<int> &nums)
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
    return nums[start] < nums[0] ? nums[start] : nums[0];
}

// binary search with another check condition
int findPivot_min(vector<int> &nums)
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    int mid = left + (right - left) / 2;
    while (left < right)
    {
        if (nums[mid] > nums[right])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
        mid = left + (right - left) / 2;
    }
    return nums[left];
}