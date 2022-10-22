// Problem link: https://leetcode.com/problems/find-pivot-index/
/*
Given an array of integers nums, calculate the pivot index of this array.
The pivot index is the index where the sum of all the numbers strictly to the left
of the index is equal to the sum of all the numbers strictly to the index's right.
If the index is on the left edge of the array, then the left sum is 0 because there
are no elements to the left. This also applies to the right edge of the array.
Return the leftmost pivot index. If no such index exists, return -1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // Approach 1: using prefix and suffix sum arrays
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();
        vector<long long> frwdSum(n, 0);
        frwdSum[0] = (long long)nums[0];
        vector<long long> bcwdSum(n, 0);
        bcwdSum[n - 1] = (long long)nums[n - 1];
        for (int i = 1; i < n; i++)
        {
            frwdSum[i] = frwdSum[i - 1] + nums[i];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            bcwdSum[i] = bcwdSum[i + 1] + nums[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (frwdSum[i] == bcwdSum[i])
            {
                return i;
            }
        }
        return -1;
    }
};