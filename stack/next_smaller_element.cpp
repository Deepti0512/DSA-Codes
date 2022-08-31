#include<bits/stdc++.h>
using namespace std;
vector<int>next_smaller(int arr[], int n){
    vector<int>ans(n);
    stack<int>s;
    s.push(-1);
    for(int i = n-1; i>=0; i--){
        int curr = arr[i];
        while(curr<=s.top()){
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}
void print(vector<int>ans){
    for(auto val:ans){
        cout<<val<<" ";
    }
    cout<<"\n";
}
int main(){
    int arr[] = {4,6,3,1,5,8,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int>ans = next_smaller(arr,n);
    print(ans);
    return 0;
}