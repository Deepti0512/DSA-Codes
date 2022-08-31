#include<iostream>
#include<queue>
using namespace std;

// Priority is a data structure which gives the maximum element on fetching i.e it is based on max heap by default
// and it can be made min heap as well

int main(){
    // max heap
    priority_queue<int> p;
    p.push(5);
    p.push(2);
    p.push(10);
    p.push(12);
    p.push(3);
    int n = p.size();
    cout<<"Priority queue as max heap: \n";
    for(int i = 0; i<n ; i++){
        cout<<p.top()<<" ";
        p.pop();
    } cout<<endl;

    //min heap
    priority_queue<int,vector<int>,greater<int>> mini;
    mini.push(5);
    mini.push(2);
    mini.push(10);
    mini.push(12);
    mini.push(3);
    int m = mini.size();
    cout<<"Priority queue as min heap: \n";
    for(int i = 0; i<m ; i++){
        cout<<mini.top()<<" ";
        mini.pop();
    } cout<<endl;

    return 0;
}