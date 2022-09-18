/*
Problem statement: given prices and nutrition of 'n' varieties of fruits, and K disount coupens(50% off), for each variety we can use only one coupen.
Find the maximum nutrition one can get if he have an amount 'm' to buy the fruits using atmost K coupens.
*/

#include <bits/stdc++.h>
using namespace std;

// for k = 0 or k >= n, this problem can be solved using greedy, but for 0 < k < n, we have to use dp
// dp[3][n+1] will be used : 1st row and ith coloum: stores the pair<int,int> (money left,nutrition) after buying ith fruit with coupen
// 2nd row stores the pair(money left,nutrition) aftery buying ith fruit without coupen
// 3rd row stores the maximum of 1st row and 2nd row for that column
// maximum value in 3rd row will be the answer
int fruitSellingDp(int m, int n, int k, vector<int> price, vector<int> nutrition)
{
    vector<vector<pair<int, int>>> dp(3, vector<pair<int, int>>(n + 1, make_pair(0, 0)));
    dp[0][0] = make_pair(m, 0);
    dp[1][0] = make_pair(m, 0);
    dp[2][0] = make_pair(m, 0);
    pair<int, int> ans; // will update with maximum value in dp (3rd row)
    ans.first = m;
    ans.second = 0;
    // we will sort the fruit varieties on the basis of max ratio of nutrition and price
    for (int col = 1; col <= n; col++)
    {
        if (price[col - 1] > 2 * m)
        {
            // if the array is not sorted according to price (in increasing order)
            /*
                for(int i = 0; i < 3; i++){
                    dp[i][col].first = ans.first;
                    dp[i][col].second = ans.second;
                }
            */
            // if the array is sorted then we can just break the loop here with default values
            break;
        }

        for (int row = 0; row < 3; row++)
        {
            if (row == 0)
            {
                // we need to store the max nutrition and money left if ith fruit is bought using coupen
                // upto coloumn number k we can use the coupen without affecting previous values
                // case: 1) coupens are still left
                if (col <= k)
                {
                    // go through the cells which contains money left and nutrition value when bought using coupens
                    for (int index = col - 1; index >= 0; index--)
                    {
                        if (price[col - 1] / 2 <= dp[0][index].first && ((nutrition[col - 1] + dp[0][index].second )> dp[0][col].second))
                        {
                            dp[0][col].first = dp[0][index].first - price[col - 1] / 2;
                            dp[0][col].second = nutrition[col - 1] + dp[0][index].second;
                        }
                    }
                }
                // case: 2) all coupens have been used : kisi ek fruit me coupen use krne ki jagah iss fruit me kro
                else
                {
                    // go through the cells which stores the money left and nutrition if bought without using coupens
                    for (int index = col - 1; index >= 0; index--)
                    {
                        if ((price[col - 1] / 2 <= dp[1][index].first) && ((nutrition[col - 1] + dp[1][index].second) > dp[0][col].second))
                        {
                            dp[0][col].first = dp[1][index].first - price[col - 1] / 2;
                            dp[0][col].second = nutrition[col - 1] + dp[1][index].second;
                        }
                    }
                }
            }
            else if (row == 1)
            {
                // we need to store the max nutrition and money left if ith fruit is bought without using coupen
                // if price of fruit is greater than maximum amount i.e 'm', then we can't buy it without using coupen so we will leave the default values in that cell
                if (price[col - 1] <= m)
                {
                    for (int index = col - 1; index >= 0; index--)
                    {
                        if (price[col - 1] <= dp[0][index].first && nutrition[col - 1] + dp[0][index].second > dp[1][col].second)
                        {
                            dp[1][col].first = (dp[0][index].first - price[col - 1]);
                            dp[1][col].second = nutrition[col - 1] + dp[0][index].second;
                        }
                        if (price[col - 1] <= dp[1][index].first && nutrition[col - 1] + dp[1][index].second > dp[1][col].second)
                        {
                            dp[1][col].first = (dp[1][index].first - price[col - 1]);
                            dp[1][col].second = nutrition[col - 1] + dp[1][index].second;
                        }
                    }
                }
            }
            else
            {
                if (dp[0][col].second > dp[1][col].second)
                {
                    dp[2][col].first = dp[0][col].first;
                    dp[2][col].second = dp[0][col].second;
                }
                else
                {
                    dp[2][col].first = dp[1][col].first;
                    dp[2][col].second = dp[1][col].second;
                }
            }
        }
        if (dp[2][col].second > ans.second)
        {
            ans.first = dp[2][col].first;
            ans.second = dp[2][col].second; // second value in pair stores max possible nutrition
        }
    }
    // let's print the dp and check if it is what we expect it to be
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << dp[i][j].second << " ";
        }
        cout << "\n";
    }
    return ans.second;
}

int main()
{
    int m, n, k;
    vector<int> price(n);
    vector<int> nutrition(n);
    cin >> m >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> price[i];
    for (int i = 0; i < n; i++)
        cin >> nutrition[i];
    int result = fruitSellingDp(m, n, k, price, nutrition);
    cout << result << "\n";
    return 0;
}