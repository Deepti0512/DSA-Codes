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
Node *construct(int *arr, int n)
{
    Node *root = new Node();
    stack<Node *> s;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
        {
            s.pop();
        }
        else
        {
            Node *temp = new Node();
            temp->data = arr[i];
            if (!s.empty())
            {
                Node *parent = s.top();
                parent->children.push_back(temp);
            }
            else
            {
                root = temp;
            }
            s.push(temp);
        }
    }
    return root;
}
class Pair
{
public:
    Node *node;
    int state;
    Pair(Node *node, int state)
    {
        this->node = node;
        this->state = state;
    }
};
void iterativeTraversal_pepcoding_approach(Node *node)
{
    string pre = "";
    string post = "";
    stack<Pair *> st;
    st.push(new Pair(node, -1));
    while (st.size() > 0)
    {
        Pair *top = st.top();
        if (top->state == -1)
        {
            pre += to_string(top->node->data) + " ";
            top->state++;
        }
        else if (top->state == top->node->children.size())
        {
            post += to_string(top->node->data) + " ";
            st.pop();
        }
        else
        {
            Pair *cp = new Pair(top->node->children[top->state], -1);
            st.push(cp);
            top->state++;
        }
    }
    cout << "Pre order Traversal: " << pre << "\n";
    cout << "Post order Traversal: " << post << "\n";
}
int main()
{
    int A[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    int s = sizeof(A) / sizeof(A[0]);
    Node *root = construct(A, s);
    iterativeTraversal_pepcoding_approach(root);
    return 0;
}