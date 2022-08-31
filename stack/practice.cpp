#include <bits/stdc++.h>
using namespace std;

void delete_middle(stack<int> &s, int initial_size)
{
    // base case
    if (s.size() == initial_size / 2 + 1)
    {
        s.pop();
        return;
    }
    int x = s.top();
    s.pop();
    delete_middle(s, initial_size);
    s.push(x);
}
bool findRedundantBrackets(string &str)
{
    stack<char> s;
    bool isRedundant = false;
    for(int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '+' || ch=='/' || ch == '(' || ch == '*' || ch == '-')
        {
            s.push(ch);
        }
        else{
            if(ch == ')'){
                if(s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/'){
                    s.pop();
                }
                else{
                    isRedundant = true;
                }
            }
            if(!s.empty()){
                s.pop();
            }
        }
    }
    if(isRedundant == true){
        return true;
    }
    else return false;
}

void print(stack<int> s)
{
    if (s.empty())
    {
        return;
    }
    int x = s.top();
    s.pop();
    print(s);
    cout << x << " ";
    s.push(x);
}

class test
{
public:
    test()
    {
        stack<int> s;
        for (int i = 1; i < 7; i++)
        {
            s.push(i);
        }
        print(s);
        cout << "\n";
        int n = s.size();
        delete_middle(s, n);
        print(s);
    }
};
int main()
{
    test t;
    return 0;
}