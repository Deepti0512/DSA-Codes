#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cin>>k;
    //For kth smallest
    sort(arr,arr+n);
    cout<<k<<"th smallest integer is: "<<arr[k-1]<<endl;
    //For kth largest
    cout<<k<<"th largest integer is: "<<arr[n-k]<<endl;
    return 0;
}