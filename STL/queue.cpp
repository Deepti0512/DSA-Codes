#include<iostream>
#include<queue>
using namespace std;

int main(){

    queue<string> q;
    q.push("Deepti");
    q.push("Mittal"); 
    q.push("is");
    q.push("a");
    q.push("good");
    q.push("progammer!");
    cout<<"first element: "<<q.front()<<endl;
    cout<<"last element: "<<q.back()<<endl;
    cout<<"size: "<<q.size()<<"\n";
    q.pop();
    cout<<"First element after pop operation: "<<q.front()<<endl;
    cout<<"size: "<<q.size()<<"\n";
    return 0;
}