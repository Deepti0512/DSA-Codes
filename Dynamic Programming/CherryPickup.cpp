#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void print(vector<vector<int>> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[n - 1][n - 1] = grid[n - 1][n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (grid[i][n - 1] != -1)
                dp[i][n - 1] = dp[i + 1][n - 1] + grid[i][n - 1];
            if (grid[n - 1][i] != -1)
                dp[n - 1][i] = dp[n - 1][i + 1] + grid[n - 1][i];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                if (grid[i][j] == -1)
                    dp[i][j] = 0;
                else
                {
                    int down = dp[i + 1][j];
                    int right = dp[i][j + 1];
                    if (down > right)
                        grid[i + 1][j] = 0;
                    else if (right > down)
                        grid[i][j + 1] = 0;
                    dp[i][j] = max(down, right);
                    dp[i][j] += grid[i][j];
                    if (right == 0 && down == 0)
                    {
                        dp[i][j] = 0;
                    }
                }
            }
        }
        int ans = dp[0][0];
        if (ans == 0)
            return 0;
        grid[0][0] = grid[n - 1][n - 1] = 0;
        // print(dp);
        // print(grid);
        dp[0][0] = grid[0][0];
        for (int i = 1; i < n; i++)
        {
            if (grid[i][0] == -1)
                dp[i][0] = 0;
            else
                dp[i][0] = dp[i - 1][0] + grid[i][0];
            if (grid[0][i] == -1)
                dp[0][i] = 0;
            else
                dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                int up = dp[i - 1][j];
                int left = dp[i][j - 1];
                dp[i][j] = max(up, left);
                dp[i][j] += grid[i][j];
            }
        }
        ans += dp[n - 1][n - 1];
        return ans;
    }
};
static int maxi = 0;
// method 1: using backtracking
void helper(int row, int col, int n, vector<vector<int>> &grid, vector<vector<int>> &dp1, vector<vector<int>> &dp2, int ans)
{
    if (row < 0 || row >= n || col >= n || col < 0 || grid[row][col] == -1)
    {
        return;
    }
    if (row == 0 && col == 0)
    {
        maxi = max(maxi, ans);
        return;
    }
    int cherries = grid[row][col];
    grid[row][col] = 0;
    helper(row, col - 1, n, grid, dp1, dp2, ans + cherries);
    helper(row - 1, col, n, grid, dp1, dp2, ans + cherries);
    grid[row][col] = cherries;
}
void cherryPickup1(int row, int col, int n, vector<vector<int>> &grid, vector<vector<int>> &dp1, vector<vector<int>> &dp2, int ans)
{
    if (row < 0 || row >= n || col >= n || col < 0 || grid[row][col] == -1)
    {
        return;
    }
    if (row == n - 1 && col == n - 1)
    {
        helper(row, col, n, grid, dp1, dp2, ans);
        return;
    }
    int cherries = grid[row][col];
    grid[row][col] = 0;
    cherryPickup1(row, col + 1, n, grid, dp1, dp2, ans + cherries);
    cherryPickup1(row + 1, col, n, grid, dp1, dp2, ans + cherries);
    grid[row][col] = cherries;
}
// dp solution of pepcoding
int cp(int r1, int c1, int r2, int n, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    int c2 = r1 + c1 - r2;
    if (r1 >= n || r2 >= n || c2 >= n || c1 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1)
    {
        return 0;
    }
    if (r1 == n - 1 && c1 == n - 1)
    {
        return grid[r1][c1];
    }
    if (dp[r1][c1][r2] != -1)
        return dp[r1][c1][r2];
    int cherries = 0;
    if (r1 == r2 && c1 == c2)
    {
        cherries += grid[r1][c1];
    }
    else
    {
        cherries += grid[r1][c1] + grid[r2][c2];
    }

    int f1 = cp(r1, c1 + 1, r2, n, grid, dp);     // right, right
    int f2 = cp(r1 + 1, c1, r2, n, grid, dp);     // down,right
    int f3 = cp(r1 + 1, c1, r2 + 1, n, grid, dp); // down,down
    int f4 = cp(r1, c1 + 1, r2 + 1, n, grid, dp); // right,down

    cherries += max(max(f1, f2), max(f3, f4));
    dp[r1][c1][c2] = cherries;
    return cherries;
}
int main()
{
    int n = 7;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    vector<vector<int>> dp1(n, vector<int>(n, 0));
    vector<vector<int>> dp2(n, vector<int>(n, 0));
    grid = {
        {1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1}};
    Solution obj;
    cout << obj.cherryPickup(grid) << "\n";
    // cherryPickup1(0, 0, n, grid, dp1, dp2, 0);
    // cout << maxi << "\n";
}