#include<bits/stdc++.h>
using namespace std;
vector<int> prev_smaller(int arr[], int n){
    vector<int>ans(n);
    stack<int> s;
    s.push(-1);
    for(int i = 0; i<n ; i++){
        int x = arr[i];
        while(x<=s.top()){
            s.pop();
        }
        ans[i] = s.top();
        s.push(x);
    }
    return ans;
}
int main(){
    int arr[] ={4,6,3,1,5,8,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int>ans = prev_smaller(arr,n);
    for(auto val:ans){
        cout<<val<<" ";
    }cout<<"\n";
    return 0;
}