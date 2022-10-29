// Problem link: https://cses.fi/problemset/task/2413
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define mod 1000000007

void solve(int n){
    ll dp[n+2][2];
    dp[n+1][0] = dp[n+1][1] = 1;
    for(int i = n; i>=2; i--){
        ll op1 = (dp[i+1][1] + dp[i+1][0])%mod;
        ll op2 = dp[i+1][0];
        ll op3 = 2* dp[i+1][0]%mod;
        ll op4 = (dp[i+1][1])%mod;

        dp[i][0] = (op1 + op2 + op3)%mod;
        dp[i][1] = (op1 + op4)%mod;
    }
    cout<<(dp[2][1] + dp[2][0])%mod<<"\n";
}

int main(){
    solve(1337);
    return 0;
}