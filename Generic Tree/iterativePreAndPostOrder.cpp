#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    vector<Node *> children;

public:
    Node() {}
    Node(int data)
    {
        this->data = data;
    }
};
class GenericTree
{
public:
    Node *root;
    GenericTree(Node *root)
    {
        this->root = root;
    }
};
Node *construct(int *arr, int n)
{
    Node *root;
    stack<Node *> st;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != -1)
        {
            if (!st.empty())
            {
                Node *top = st.top();
                Node *newNode = new Node(arr[i]);
                top->children.push_back(newNode);
                st.push(newNode);
            }
            else
            {
                root = new Node(arr[i]);
                st.push(root);
            }
        }
        else
        {
            st.pop();
        }
    }
    return root;
}
class Pair
{
public:
    int state;
    Node *node;
    Pair(Node *node, int state)
    {
        this->node = node;
        this->state = state;
    }
};
void iterativeTraversal(Node *root)
{
    Pair *mp = new Pair(root, -1);
    stack<Pair *> s;
    string pre;
    string post;
    s.push(mp);
    while (!s.empty())
    {
        Pair *top = s.top();
        if (top->state == -1)
        {
            pre += to_string(top->node->data) + " ";
            top->state++;
        }
        else if (top->state == top->node->children.size())
        {
            post += to_string(top->node->data) + " ";
            s.pop();
        }
        else
        {
            Pair *cp = new Pair(top->node->children[top->state], -1);
            s.push(cp);
            top->state++;
        }
    }
    cout << pre << "\n";
    cout << post << "\n";
}
int main()
{
    int A[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    int s = sizeof(A) / sizeof(A[0]);
    Node *root = construct(A, s);
    iterativeTraversal(root);
    return 0;
}