#include<bits/stdc++.h>
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
void pushAtBottom(stack<int>&s, int x){
  if(s.empty()){
    s.push(x);
    return;
  }
  int  y= s.top();
  s.pop();
  pushAtBottom(s,x);
  s.push(y);
}
int main(){
  stack<int> s;
  s.push(2);
  s.push(3);
  s.push(4);
  pushAtBottom(s,1);
  Print_Stack(s);
}