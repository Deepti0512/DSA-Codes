#include <bits/stdc++.h>
using namespace std;

// (floor) integer value
int sqrt_integer(int n)
{
    int low = 0;
    int high = n;
    int mid = (low + high) / 2;
    while (low <= high)
    {
        long long square = mid * mid;
        if (square == n)
        {
            return mid;
        }
        if (square > n)
        {
            high = mid - 1;
        }
        else if (square < n)
        {
            low = mid + 1;
        }
        mid = (high + low) / 2;
    }
    return mid;
}

// floating point
double morePrecision(int n, int precision, int tempSol)
{
    double factor = 1;
    double ans = tempSol;
    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j < n; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    int n = 47;
    int tempSol = sqrt_integer(n);
    cout << tempSol << "\n";
    double ans = morePrecision(n, 6, tempSol);
    cout << ans << "\n";
    return 0;
}