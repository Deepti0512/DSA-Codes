#include <bits/stdc++.h>
using namespace std;

class StackNode
{
public:
    int data;
    StackNode *next;
    StackNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class Stack
{
    StackNode *top;

public:
    // Push and pop operations
    void push(int data)
    {
        if (top == NULL)
        {
            top = new StackNode(data);
            return;
        }
        StackNode *s = new StackNode(data);
        s->next = top;
        top = s;
    }

    StackNode *pop()
    {
        StackNode *s = top;
        top = top->next;
        return s;
    }

    // prints contents of stack
    void display()
    {
        StackNode *s = top;
        while (s != NULL)
        {
            cout << s->data << " ";
            s = s->next;
        }
        cout << endl;
    }

    // Reverses the stack using simple linked list reversal logic.
    void reverse()
    {
        StackNode *prev, *cur, *succ;
        cur = prev = top;
        cur = cur->next;
        prev->next = NULL;
        while (cur != NULL)
        {
            succ = cur->next;
            cur->next = prev;
            prev = cur;
            cur = succ;
        }
        top = prev;
    }
};
class stack_array
{
public:
    // properties
    int *arr;
    int top;
    int size;
    // behavior
    stack_array() {}
    stack_array(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int data)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout << "Stack overflowed\n";
        }
    }
    int pop()
    {
        if (top != -1)
        {
            int val = arr[top];
            top--;
            return val;
        }
        else
        {
            cout << "Stack is empty\n";
            return -1;
        }
    }
    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "stack is empty\n";
            return -1;
        }
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
            return false;
    }
    void print()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    stack_array *reverse()
    {
        int s = this->size;
        stack_array *temp = new stack_array(s);
        while (s != 0)
        {
            temp->push(this->pop());
            s--;
        }
        return temp;
    }
};
class reverse_class
{
public:
    void Print_Stack(stack<int> s)
    {
        // base case
        if (s.empty())
        {
            return;
        }
        int x = s.top();
        s.pop();
        Print_Stack(s); // recursive call
        cout << x << " ";
        s.push(x);
    }
    void pushAtBottom(stack<int> &s, int x)
    {
        if (s.empty())
        {
            s.push(x);
            return;
        }
        int y = s.top();
        s.pop();
        pushAtBottom(s, x);
        s.push(y);
    }
    void reverse3(stack<int> &s)
    {
        // base case
        if (s.empty())
        {
            return;
        }
        // store the top element
        int a = s.top();
        s.pop();
        // use recursion to reverse the remaining elements
        reverse3(s);
        // now add the top element at bottom
        pushAtBottom(s, a);
    }
};
class test
{
public:
    test()
    {
        cout << "test case 1 (without using extra space)\n";
        Stack *s = new Stack();
        s->push(1);
        s->push(2);
        s->push(3);
        s->push(4);
        cout << "Original Stack\n";
        s->display();
        // reverse
        s->reverse();
        cout << "Reversed Stack\n";
        s->display();
        /*
        Following lines of code doesn't work
        Stack s1;
        s1.push(23);
        s1.push(45);
        s1.display();
        s1.reverse();
        s1.display();
        */
        cout << "test case2 (using extra space)\n";
        stack_array *s1 = new stack_array(5);
        s1->push(23);
        s1->push(12);
        s1->push(13);
        s1->push(34);
        s1->push(45);
        s1->print();
        stack_array *ans = s1->reverse();
        ans->print();
        cout << "Test case 3(using another logic with O(n²) time and no extra space)\n";
        stack<int> st;
        st.push(5);
        st.push(4);
        st.push(3);
        st.push(2);
        st.push(1);
        cout << "Original stack: ";
        reverse_class obj;
        obj.Print_Stack(st);
        cout<<"\n";
        obj.reverse3(st);
        cout << "Reversed Stack: ";
        obj.Print_Stack(st);
        cout<<"\n";
    }
};
int main()
{
    test t;
    return 0;
}
