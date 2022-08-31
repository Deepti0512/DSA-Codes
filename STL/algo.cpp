#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<int>v;
    for(int i = 1; i<6; i++){
        v.push_back(i);
    }
    
    cout<<"Finding 3 using Binary search STL function: "<<binary_search(v.begin(),v.end(),4)<<"\n";
    cout<<"Lower bound -> "<<lower_bound(v.begin(), v.end(),3)-v.begin()<<endl;
    cout<<"Upper bound -> "<<upper_bound(v.begin(), v.end(),3)-v.begin()<<endl; 
    
    int a = 10;
    int b = 15;
    int c = 20;
    cout<<"max -> "<<max(a,b)<<endl;
    cout<<"min -> "<<min(a,b)<<endl;
    
    swap(a,b);
    cout<<a<<endl;

    string s = "deepti";
    string :: iterator it = s.begin();
    string :: iterator it2 = s.end();
    auto it3 = v.begin();
    cout<<*it3<<endl;
    reverse(it,it2);
    reverse(s.begin(), s.end());
    cout<<s<<endl;
    cout<<"vector before rotation: ";
    for(auto i:v){
        cout<<i<<" ";
    }cout<<endl;
    rotate(v.begin(),v.begin()+2,v.end());
    cout<<"vector after rotation: ";
    for(auto i: v){
        cout<<i<<" ";
    }cout<<endl;
    v.push_back(8);
    v.push_back(7);
    sort(v.begin(),v.end());
    for(auto i: v){
        cout<<i<<" ";
    }cout<<endl;
    return 0;
}