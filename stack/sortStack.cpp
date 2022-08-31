#include <bits/stdc++.h>
using namespace std;
void sortedInsert(stack<int> &s, int num)
{
    if (s.empty() || (!s.empty() && num >= s.top()))
    {
        s.push(num);
        return;
    }
    int x = s.top();
    s.pop();
    sortedInsert(s, num);
    s.push(x);
}
void sort(stack<int> &s)
{
    // base case
    if (s.empty())
    {
        return;
    }

    int x = s.top();
    s.pop();
    // top element ko alag krne ke bad baki ki stack ko recursion se sort krdo(faith)
    sort(s);
    // Ab finally faith and expectation ko link krdo by inserting the top element at it's appropriate position (baki ke elements apni shi jagah place ho chuke h recursion ki help se )
    sortedInsert(s, x);
}
void print(stack<int> s)
{
    // base case
    if (s.empty())
    {
        return;
    }
    int x = s.top();
    s.pop();
    print(s); // recursive call
    cout << x << " ";
    s.push(x);
}
class test
{
public:
    void Test()
    {
        stack<int> s;
        s.push(23);
        s.push(-5);
        s.push(1);
        s.push(32);
        s.push(-3);
        print(s);
        cout << "\n";
        sort(s);
        print(s);
        cout << "\n";
        // let's create a stack in sorted order using sortedinsert function
        stack<int> st;
        sortedInsert(st, 5);
        sortedInsert(st, 1);
        sortedInsert(st, -3);
        sortedInsert(st, 24);
        sortedInsert(st, 50);
        print(st);
        // sortedinsert function me kisi bhi order me elements push kro vo sorted order me hi store honge stack me
        // kitna amazing h wow
    }
};
int main()
{
    test t;
    t.Test();
    return 0;
}