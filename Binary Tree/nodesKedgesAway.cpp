#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

public:
    Node() {}
    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
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
Node *construct(int *arr, int n)
{
    stack<Pair *> st;
    Node *root = new Node(arr[0], NULL, NULL);
    Pair *rp = new Pair(root, 1); // make root pair namely rp
    st.push(rp);
    int index = 0;
    while (st.size() > 0)
    {
        Pair *top = st.top();
        if (top->state == 1)
        {
            index++;
            if (arr[index] != -1)
            {
                Node *newNode = new Node(arr[index], NULL, NULL);
                top->node->left = newNode;
                Pair *left_pair = new Pair(newNode, 1);
                st.push(left_pair);
            }
            else
            {
                top->node->left = NULL;
            }
            top->state++;
        }
        else if (top->state == 2)
        {
            index++;
            if (arr[index] != -1)
            {
                Node *newNode = new Node(arr[index], NULL, NULL);
                top->node->right = newNode;
                Pair *right_pair = new Pair(newNode, 1);
                st.push(right_pair);
            }
            else
            {
                top->node->right = NULL;
            }
            top->state++;
        }
        else
        {
            st.pop();
        }
    }
    return root;
}

static vector<Node *> path;
bool find(Node *node, int x)
{
    if (node->data == x)
    {
        path.push_back(node);
        return true;
    }
    if (find(node->left, x))
    {
        path.push_back(node);
        return true;
    }
    if (find(node->right, x))
    {
        path.push_back(node);
        return true;
    }
    return false;
}

void print_K_LevelsDown(Node *node, int k, Node* blocker)
{
    if (node == NULL || k < 0 || k == blocker->data)
    {
        return;
    }
    if (k == 0)
    {
        cout << node->data << " ";
    }
    print_K_LevelsDown(node->left, k - 1, blocker);
    print_K_LevelsDown(node->right, k - 1, blocker);
}

void print_k_nodesFar(Node *node, int data, int k)
{
    find(node, data);
    for (int i = 0; i < path.size() && i<=k ; i++)
    {
        Node* blocker;
        if (i == 0){
           blocker = new Node();
           blocker->data == -10;
        }
        else
            blocker = path[i - 1];
        print_K_LevelsDown(path[i], k - i, blocker);
    }
}

int main()
{
    int A[] = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};
    int s = sizeof(A) / sizeof(A[0]);
    Node *root = construct(A, s);
    print_k_nodesFar(root,70,2);
    return 0;
}