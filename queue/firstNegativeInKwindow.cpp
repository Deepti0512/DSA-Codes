#include <bits/stdc++.h>
using namespace std;
vector<int> firstNegative(int arr[], int n, int k)
{
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
    }
    if (!dq.empty())
    {
        ans.push_back(arr[dq.front()]);
    }
    else
        ans.push_back(0);
    for (int i = k; i < n; i++)
    {
        // step1 : removal of deque elements if not in range of window
        if (!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front();
        }
        // step2 : add next element if negetaive
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
        // push value in ans array
        if (!dq.empty())
        {
            ans.push_back(arr[dq.front()]);
        }
        else
            ans.push_back(0);
    }
    return ans;
}
void print(vector<int>arr){
    for(auto val:arr){
        cout<<val<<" ";
    }
    cout<<"\n";
}
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans = firstNegative(arr, n, k);
    print(ans);
    return 0;
}