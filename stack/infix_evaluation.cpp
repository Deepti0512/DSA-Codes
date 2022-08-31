#include<bits/stdc++.h>
using namespace std;
int precedence(char op){
   if(op == '+' || op == '-'){
      return 1;
   }
   else return 2;
}
int operation(int v1, int v2, char op){
    if(op == '+'){
        return v1 + v2;
    }
    else if(op == '-'){
        return v1 - v2;
    }
    else if(op == '*'){
        return v1 * v2;
    }
    else {
        return v1/v2;
    }
}
void solve(string s){
    stack<char> optors;
    stack<int> opnds;
    for(int i = 0; i < s.length(); i++){
        char ch = s[i];
        if(ch == ')'){
            while(optors.top()!='('){
                char op = optors.top();
                optors.pop();
                int v1 = opnds.top();
                opnds.pop();
                int v2 = opnds.top();
                opnds.pop();
                int val = operation(v2,v1,op);
                opnds.push(val);
            }
            optors.pop();
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            //before pushing the operator in stack, solve for operators with higher or equal precendence
            while(optors.size()>0 && optors.top() != '(' && precedence(ch)<=precedence(optors.top()) ){
                char op = optors.top();
                optors.pop();
                int v1 = opnds.top();
                opnds.pop();
                int v2 = opnds.top();
                opnds.pop();
                int val = operation(v2,v1,op);
                opnds.push(val);
            }
            optors.push(ch);
        }
        else if(ch == '('){
            optors.push(ch);
        }
        else if(isdigit(ch)){
            opnds.push(ch - '0');
        }
    }
    while(!optors.empty()){
        char op = optors.top();
        optors.pop();
        int v1 = opnds.top();
        opnds.pop();
        int v2 = opnds.top();
        opnds.pop();
        int val = operation(v2,v1,op);
        opnds.push(val);
    }
    int ans = opnds.top();
    cout<<ans<<endl;
    return;
}

int main(){
    // string s = "2 + 6 * 4 / 8 - 3";
    // cin>>s;
    string exp;
    cin>>exp;
    solve(exp);
    return 0;
}