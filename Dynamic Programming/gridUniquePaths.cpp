// Problem Link: https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470

#include <bits/stdc++.h>
using namespace std;

//memoization
int f(int row, int col, int m, int n, vector<vector<int>> &dp)
{
    if (row == 0 || col == 0)
    {
        return 1;
    }
    if (dp[row][col] != -1)
        return dp[row][col];

    if (row < 0 || col < 0)
    {
        return 0;
    }
    return dp[row][col] = f(row - 1, col, m, n, dp) + f(row, col - 1, m, n, dp);
}

//tabulation
int tabu(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

// space optimisation
int spo(int m, int n)
{
    vector<int> prev(n, 1);
    for (int i = 1; i < m; i++)
    {
        vector<int> curr(n, 1);
        for (int j = 1; j < n; j++)
        {
            curr[j] = prev[j] + curr[j - 1];
        }
        prev = curr;
    }
    return prev[n - 1];
}

// most optimal ==> combinatorics
int combinatorics_Sol(int m, int n){
    int N = n + m - 2;
    int r = m - 1;
    double res = 1;

    // logic for nCr
    for(int i = 1; i <= r; i++){
        res = res * (N-r+i)/i;
    }
    return (int)res;
}
int uniquePaths(int m, int n)
{
    //  vector<vector<int>>dp(m,vector<int>(n,-1));
    // 	return f(m-1,n-1,m,n,dp);
    return tabu(m, n);
    return spo(m, n);
}
int main()
{
    int t;
    cin >> t;
    int m, n;
    int cnt = 0;
    while (cnt != t)
    {
        cin >> m >> n;
        cout << "case# " << cnt + 1 << ": ";
        cout << uniquePaths(m, n) << "\n";
        cnt++;
    }
    return 0;
}