#include <iostream>
using namespace std;
int main()
{
    int n = 6;
    int arr[] = {5, 10, 100, 10, 6, 20};
    int inc = arr[0];
    int exc = 0;
    for (int i = 1; i < n; i++)
    {
        int ninc = exc + arr[i];
        int nexc = max(inc, exc);

        inc = ninc;
        exc = nexc;
    }
    int ans = max(inc, exc);
    cout << ans << "\n";
}