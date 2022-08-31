#include <bits/stdc++.h>
using namespace std;

bool Check_if_Redundant(string &str)
{
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            // this condition if for open bracket and operator
            s.push(ch);
        }
        else
        {
            // ignore if lowercase character and do some operations if closing bracket
            if (ch == ')')
            {
                bool isRedundant = true;
                while (s.top() != '(')
                {
                    char top = s.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isRedundant = false;
                    }
                    s.pop();
                }
                if (isRedundant == true)
                {
                    return true;
                }
                s.pop();
            }
        }
    }
    return false;
}
int main()
{
    // string str = "(a + b) + ((c + d))";
    string s;
    getline(cin,s);
    if (Check_if_Redundant(s))
    {
        cout << "true\n";
    }
    else
        cout << "false\n";
    return 0;
}