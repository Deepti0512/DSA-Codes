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
    Node(int data){
        this->data = data;
    }
    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
    ~Node(){
       int value = this -> data;
       if(this->left != NULL){
           this->left = NULL;
           delete left;
       }
       if(this->right != NULL){
           this->right = NULL;
           delete right;
       }
       cout<<value<<" is deleted from the tree\n";
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

void printBT(const std::string& prefix, const Node* node, bool isLeft)
{
    if (node != nullptr)
    {
        cout << prefix;
        cout << (isLeft ? "|--" : "L--");
        // print the value of the node
        cout << node->data << endl;
        // enter the next tree level - left and right branch
        printBT(prefix + (isLeft ? "|   " : "    "), node->right, true);
        printBT(prefix + (isLeft ? "|   " : "    "), node->left, false);
    }
}

int main(){
    int A[] = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};
    int s = sizeof(A) / sizeof(A[0]);
    Node *root = construct(A, s);
    printBT("", root, false);
    return 0;
}