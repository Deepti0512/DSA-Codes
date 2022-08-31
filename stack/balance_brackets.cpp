#include <bits/stdc++.h>
using namespace std;
bool isValidBracket(string exp)
{
    // open braket aye toh stack me dal do aur closing aye toh pop krdo
    // agar end me stack empty ho jaye toh balanced h otherwise nhi h
    stack<char> s;
    for (int i = 0; i < exp.length(); i++)
    {
        // if opening bracket, push in stack
        char ch = exp[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else
        {
            // if closing bracket, first check if matching and then pop
            if (!s.empty())
            {
                char top = s.top();

                if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '['))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            return false;
        }
    }
    if (s.empty())
        return true;
    else
        return false;
}
int main()
{
    string s = "[[{()}]]";
    bool flag = isValidBracket(s);
    if (flag)
    {
        cout << "balanced\n";
    }
    else
        cout << "Not balanced\n";
    return 0;
}