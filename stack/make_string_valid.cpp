#include<iostream>
#include<stack>
using namespace std;
int findMinimumCost(string str) {
   //case1 string is of odd length
   if(str.length()%2==1){
       return -1;
   } 
   else{
       //step1: remove all valid substring/brackets
       stack<char> s;
       for(int i = 0; i< str.length(); i++){
           char ch = str[i];
           if(ch == '{'){
               s.push(ch);
           }
           else{
               if(!s.empty() && s.top()=='{'){
                   s.pop();
               }
               else{
                   s.push(ch);
               }
           }
       }
       //now the stack contains only invalid string
       //step2 : count the no.of operations required to make the remaining string valid
       int a = 0; //to count no.of '{'bracket
       int b = 0; //no.of '}'brackets
       while(!s.empty()){
           if(s.top()=='{'){
               a++;
           }
           else b++;
           s.pop();
       }
       int ans = (a+1)/2 + (b+1)/2;
       return ans;
   }
}
int main(){
    string s = "}{{}{}}}}{";
    cout<< findMinimumCost(s);
    return 0;
}