// Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which adds to a given number S.
// In case of multiple subarrays, return the subarray which comes first on moving from left to right.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        int l = 0, r = 1;
        long long currSum = arr[0];
        vector<int> ans;

        while (l < n && r <= n)
        {
            if (l == r || currSum < s)
            {
                currSum += arr[r++];
            }
            else if (currSum > s)
            {
                currSum -= arr[l++];
            }
            else
            {
                ans.push_back(l + 1);
                ans.push_back(r);
                return ans;
            }
        }
        return {-1};
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long s;
        cin >> n >> s;
        int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}