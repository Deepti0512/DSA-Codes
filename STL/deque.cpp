#include<iostream>
#include<deque>
using namespace std;

// Deque is a double ended queue

int main(){
    deque<int>d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(5);
    d.push_back(25);
    cout<<"Empty or not: "<<d.empty()<<endl;
    for(int i:d){
        cout<<i<<" ";
    }cout<<endl;
    cout<<"Print element at index 1: "<<d.at(1)<<endl;
    cout<<"Element at front: "<<d.front()<<endl;
    cout<<"Element at last: "<<d.back()<<endl;
    //d.pop_front();
    
    d.erase(d.begin(),d.begin()+2);
    cout<<"Values after erasing: "<<endl;
    for(int i:d){
        cout<<i<<" ";
    }cout<<endl;
    cout<<"size: "<<d.size()<<endl;
    d.clear();
    cout<<"Empty or not: ";
    string ans = d.empty()==1?"yes":"no";
    cout<<ans<<endl;
    return 0;
}