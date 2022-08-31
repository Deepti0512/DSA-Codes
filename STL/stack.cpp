#include<iostream>
#include<stack>
using namespace std;

void Print_Stack(stack<string> s){
    //base case
    if(s.empty()){
        return;
    }
    string x = s.top();
    s.pop();
    Print_Stack(s); //recursive call
    cout<<x<<" ";
    s.push(x);
}

int main(){
    
stack<string>s;
s.push("Deepti");
s.push("Mittal");
s.push("loves");
s.push("her");
s.push("family!");
cout<<"Is stack empty or not? "<<s.empty()<<"\n";
cout<<"Top element in stack: "<<s.top()<<endl;
cout<<"Size of stack: "<<s.size()<<"\n";
cout<<"Print all character of string present at top position in stack: ";
for(auto val:s.top()){
    cout<<val<<" ";
}
stack<string>s2(s); //copy contents of s to s2
cout<<"\nPrint all elements of stack: ";
// while(!s.empty()){
//     cout<<s.top()<<" ";
//     s.pop();
// }
Print_Stack(s2);
cout<<"\n";
return 0;
}