#include<iostream>
#include<list>
using namespace std;

// STL List is a doubly linked list

int main(){
    list<int>l;
    l.push_back(10);
    l.push_front(5);
    l.push_back(15);
    l.push_back(20);
    cout<<"List size "<<l.size()<<endl;
    cout<<"Print list: \n";
    for(int i:l){
        cout<<i<<" ";
    }
    cout<<endl;
    l.erase(l.begin());
    cout<<"Print list after earsing an element from front: \n";
    for(int i:l){
        cout<<i<<" ";
    }
    cout<<endl;

    l.pop_back();
    l.pop_front();
    for(int i:l){
    cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
