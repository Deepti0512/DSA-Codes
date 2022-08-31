#include<bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q)
{
    stack<int>s;
    while(!q.empty()){
        int x = q.front();
        s.push(x);
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    return q;
}
void display(queue<int>q){
    if(q.empty()){
        cout<<"\n";
        return;
    }
    int n = q.size();
    int element = q.front();
    cout<<element<<" ";
    q.pop();
    display(q);
    q.push(element);
}
int main(){
    queue<int> q;
    q.push(45);
    q.push(30);
    q.push(25);
    q.push(20);
    cout<<"Original queue:\n";
    display(q);
    q = rev(q);
    cout<<"Reversed queue (using O(n) space i.e stack):\n";
    display(q);
    return 0;
}