#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  private:
    vector<int> prevSmallerindex(int *arr, int n)
    {
       stack<int> s;
       s.push(-1);
       vector<int> ans(n);
       for (int i = 0; i < n; i++)
       {
         int curr = arr[i];
         while (s.top() != -1 && (arr[s.top()] >= curr))
         {
            s.pop();
         }
        // ans is stack ka top element
         ans[i] = s.top();
         s.push(i);
     }
     return ans;
    }
    vector<int> nextSmallerindex(int *arr, int n)
    {
       stack<int> s;
       s.push(-1);
       vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            // ans is stack ka top element
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    //Function to find largest rectangular area possible in a given histogram.
    int getMaxArea(int arr[], int n)
    {
       int area = INT_MIN;
       vector<int> prev(n);
       vector<int> next(n);
       prev = prevSmallerindex(arr, n);
       next = nextSmallerindex(arr, n);
       for (int i = 0; i < n; i++)
        {
           int l = arr[i];
           if (next[i] == -1)
           {
              next[i] = n;
           }
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
    }
    
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        int area = getMaxArea(M[0],m);
        for(int i = 1; i<n;i++){
            for(int j = 0; j<m;j++){
                if(M[i][j]!=0){
                    M[i][j] = M[i-1][j] + M[i][j];
                }
                else M[i][j] = 0;
            }
            area = max(area,getMaxArea(M[i],m));
        }
        return area;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
// } Driver Code Ends