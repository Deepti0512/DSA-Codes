#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007; // 1e9 + 7

class mazePaths
{
public:
    int f(int row, int col, int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp)
    {
        if (row < 0 || col < 0 || mat[row][col] == -1)
        {
            return 0;
        }
        if (row == 0 && col == 0)
        {
            return 1;
        }
        if (dp[row][col] != -1)
            return dp[row][col];
        return dp[row][col] = ((f(row - 1, col, n, m, mat, dp) % mod) + (f(row, col - 1, n, m, mat, dp) % mod)) % mod;
    }

    int tabu(int n, int m, vector<vector<int>> &mat)
    {
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int left = 0;
        int up = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                up = 0;
                left = 0;
                if (mat[i][j] == -1)
                    dp[i][j] = 0;
                else if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else
                {
                    if (i > 0)
                        up = (dp[i - 1][j]) % mod;
                    if (j > 0)
                        left = (dp[i][j - 1]) % mod;
                    dp[i][j] = (up % mod + left % mod) % mod;
                }
            }
        }
        return dp[n - 1][m - 1];
    }
    int mazeObstacles(int n, int m, vector<vector<int>> &mat)
    {
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return f(n-1,m-1,n,m,mat,dp);
        return tabu(n, m, mat);
    }
    // space optimisation
    int spo(int n, int m,vector<vector<int>> &mat)
    {
        vector<int> prev(m, 0);
        for (int i = 0; i < n; i++)
        {
            vector<int> curr(m, 0);
            for (int j = 0; j < m; j++)
            {
                if(mat[i][j] == -1) curr[j] = 0;
                else if(i==0 && j == 0)curr[j] = 1;
                else{
                    int up = 0,left = 0;
                    if(i>0) up = prev[j];
                    if(j>0) left = curr[j-1];
                    curr[j] = (up + left)%mod;
                }
            }
            prev = curr;
        }
        return prev[m - 1];
    }
};

void test()
{
    int n, m;
    n = 3;
    m = 5;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    mat[0][3] = -1;
    mat[1][3] = -1;
    mat[0][2] = -1;
    mazePaths obj;
    cout << obj.mazeObstacles(n, m, mat);
}
int main()
{
    test();
    return 0;
}