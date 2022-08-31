#include <bits/stdc++.h>
using namespace std;
void Print_Stack(stack<int>s){
    //base case
    if(s.empty()){
        return;
    }
    int x = s.top();
    s.pop();
    Print_Stack(s); //recursive call
    cout<<x<<" ";
    s.push(x);
}
void del_mid(stack<int>&s, int count, int size)
{
    // base case
    if (count == size / 2){
        s.pop();
        return;
    }
    int val = s.top();
    s.pop();
    del_mid(s,count+1,size);
    s.push(val);
}
int main()
{
    stack<int> s;
    for (int i = 1; i < 7; i++)
    {
        s.push(i);
    }
    Print_Stack(s);
    cout<<"\n";
    del_mid(s, 0, s.size());
    Print_Stack(s);
    return 0;
}