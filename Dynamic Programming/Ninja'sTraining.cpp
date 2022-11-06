// Problem link: https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003
#include <bits/stdc++.h>
using namespace std;

// memoization
int func(int day, int index, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != index)
            {
                maxi = max(maxi, points[day][task]);
            }
        }
        return maxi;
    }
    if (dp[day][index] != -1)
        return dp[day][index];
    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != index)
        {
            maxi = max(maxi, points[day][i] + func(day - 1, i, points, dp));
        }
    }
    return dp[day][index] = maxi;
}

// tabulation
int tabu(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));
    // base cases
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(max(points[0][0], points[0][1]), points[0][2]);

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            int maxi = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = points[day][task] + dp[day - 1][task];
                    maxi = max(maxi, point);
                }
            }
            dp[day][last] = maxi;
        }
    }

    return dp[n - 1][3];
}

// space optimisation
int SpO(int n, vector<vector<int>> &points){
    vector<int>dp(4,0);
    dp[0] = max(points[0][1], points[0][2]);
    dp[1] = max(points[0][0], points[0][2]);
    dp[2] = max(points[0][0], points[0][1]);
    dp[3] = max(max(points[0][0], points[0][1]), points[0][2]);

    for(int day = 1; day < n; day++){
        vector<int>temp(4,0);
        for(int last = 0; last < 4; last++){
            temp[last] = 0;

            for(int task = 0; task < 3; task++){
                if(task!=last){
                    temp[last] = max(temp[last],points[day][task] + dp[task]);
                }
            }
        }
        dp = temp;
    }
    return dp[3];
}

// Driver function
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return func(n - 1, 3, points, dp);
}

int main()
{
    int n;
    cout << "Enter the number of days: \n";
    cin >> n;
    vector<vector<int>> points(n, vector<int>(3));
    int val;
    cout << "Enter the elements of points vector: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> val;
            points[i][j] = val;
        }
    }
    cout << ninjaTraining(n, points) << "\n";
    return 0;
}

/* 
Sample Input1:
3
10 40 70
20 50 80
30 60 90
output: 11
Sample input 2:
3
10 40 70
20 50 80
30 60 90
output: 210
*/ 