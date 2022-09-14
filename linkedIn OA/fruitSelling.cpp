#include <bits/stdc++.h>
using namespace std;
int getMaximumNutrition(int m, int n, int price[], int nutrition[], int k)
{
    if (k >= n)
    {
        for (int i = 0; i < n; i++)
        {
            price[i] = price[i] / 2;
        }
        vector<pair<int, int>> ratio(n);
        for (int i = 0; i < n; i++)
        {
            ratio[i].first = nutrition[i] / price[i];
            ratio[i].second = i;
        }
        sort(ratio.rbegin(), ratio.rend());
        int maxNutrition = 0;
        for (int i = 0; i < n; i++)
        {
            int index = ratio[i].second;
            if (price[index] <= m)
            {
                maxNutrition += nutrition[index];
                m -= price[i];
            }
            else
            {
                return maxNutrition;
            }
        }
    }
    else
    {
        vector<pair<int, int>> ratio(n);
        for (int i = 0; i < n; i++)
        {
            ratio[i].first = nutrition[i] / price[i];
            ratio[i].second = i;
        }
        sort(ratio.rbegin(), ratio.rend());
        int maxNutrition = 0;
        for (int i = 0; i < n; i++)
        {
            int index = ratio[i].second;
            if (price[index] <= m)
            {
                maxNutrition += nutrition[index];
                m -= price[index];
            }
            else if (k > 0)
            {
                price[index] = price[index] / 2;
                k--;
                if (price[index] <= m)
                {
                    maxNutrition += nutrition[index];
                    m -= price[index];
                }
            }
        }
        return maxNutrition;
    }
}
int main()
{
    int t, n, m, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int price[n];
        int nutrition[n];
        for (int i = 0; i < n; i++)
        {
            cin >> price[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> nutrition[i];
        }
        cin >> k;
        cout << getMaximumNutrition(m, n, price, nutrition, k);
    }
    return 0;
}