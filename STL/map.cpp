#include<iostream>
#include<map>
using namespace std;

int main(){
    
    map<int,string>m;
    m[0]="Deepti";
    m[2]="Mummy";
    m[1]="Papa";
    m[11]="pranshu";
    m[8]="naina";
    m[0]="hello"; //previous value will be replaced by new value
    m.insert({12,"life"});

    for(auto val:m){
        cout<<val.first<<" "<<val.second<<endl;
    }
    m.erase(12);
    cout<<"Finding 11 -> "<<m.count(11)<<endl;

    map<int,string>:: iterator it = m.find(1);
    // or we can write auto it = m.find(1)
    for(auto i=it; i!=m.end(); i++ ){
        cout<<(*i).first<<" ";
    }cout<<endl;
    
    // Time complexity of insert , count , erase and find is O(logn)
    // unordered map me search ki complexity O(1) hoti h

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	int n,k;
// 	cin>>n>>k;
// 	int arr[n];
// 	map<int,int>indices;
// 	for(int i=0;i<n;i++){
// 	    cin>>arr[i];
// 	    indices[arr[i]] = i;
// 	}
// 	sort(arr,arr+n);
// 	int m = 0;
// 	while(k>0 && i<n){
// 	    k =  k-arr[i];
// 	    m++;
// 	}
// 	vector<int>ans;
// 	iterator it:indices
// 	map<int,int> :: iterator it = m.find(arr[0]);
// 	for(int i;i<=m;i++){
	     
// 	}
// 	return 0;
// }