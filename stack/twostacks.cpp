#include <iostream>
using namespace std;
// program to implement two stacks in an array
class twoStacks
{
public:
    int top1;
    int top2;
    int size;
    int *arr;
    twoStacks(int size) 
    {
        this->size = size;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }
    void push1(int d)
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = d;
        }
        else
        {
            cout << "stack overflowed\n";
        }
    }
    void push2(int d)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = d;
            return;
        }
        else
        {
            cout << "stack overflowed\n";
        }
    }
    int pop1()
    {
        if (top1 >= 0)
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
        {
            return -1;
        }
    }
    int pop2()
    {
        if (top2 < size)
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
            return -1;
    }
    void print1()
    {
        if (top1 == -1)
        {
            cout << "stack 1 is empty\n";
            return;
        }
        else
        {
            for (int i = 0; i <= top1; i++)
            {
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
    }
    void print2()
    {
        if (top1 == size)
        {
            cout << "stack 2 is empty\n";
            return;
        }
        else
        {
            for (int i = size - 1; i >= top2; i--)
            {
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};
class test
{
public:
    test()
    {
        twoStacks s(10);
        s.push1(4);
        s.push2(10);
        s.push1(2);
        s.push2(20);
        s.push1(6);
        s.push2(30);
        s.push1(4);
        s.push2(10);
        s.push1(2);
        s.push2(20);
        s.print1();
        s.print2();
        s.print();
        int p = s.pop1();
        int q = s.pop2();
        cout << "element popped from stack1 : " << p << "\n";
        cout << "element popped from stack2 : " << q << "\n";
        s.print1();
        s.print2();
    }
};

int main(){
    test t;
    return 0;
}