#include <bits/stdc++.h>
using namespace std;
//static members are stored in heap 
static int SIZE;
static int MAX;
static int MIN;
static int HEIGHT;
// static Node* Predecessor;
// static Node* Successor;
static int Predecessor;
static int Successor;
static int State = 0;
static int Floor;
static int Ceil;
class Node
{
public:
    int data;
    vector<Node *> children;
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
void display(Node *root)
{
    string str = to_string(root->data) + "-->";
    for (Node *child : root->children)
    {
        str += to_string(child->data) + ", ";
    }
    str += ".";
    cout << str << endl;
    for (Node *child : root->children)
    {
        display(child);
    }
}
void multisolver(Node* node,int depth){
    //pre order
    SIZE++;
    MAX = node->data > MAX ? node->data : MAX;
    MIN = node->data < MIN ? node->data : MIN;
    HEIGHT = depth>HEIGHT ? depth : HEIGHT;
    //traversal
    for(Node* child: node->children){
        multisolver(child,depth + 1);
    }
}
void pred_succ(Node* node, int data){
    if(State == 0){
        if(node->data == data){
            State = 1;
        }
        else{
            Predecessor = node->data;
        }
    }else if(State == 1){
        Successor = node->data;
        State = 2;
    }
    for(Node* child : node->children){
        pred_succ(child,data);
    }
}
void Ceil_and_Floor(Node* node, int x){
    if(node->data < x){
        Floor = node->data > Floor ? node->data : Floor;
    }
    else if(node->data > x){
        Ceil = node->data < Ceil ? node->data : Ceil;
    }
    for(Node* child : node->children){
        Ceil_and_Floor(child,x);
    }
}
int kthLargest(Node *root, int k){
    Floor = INT_MIN;
    int result = INT_MAX;
    for(int i = 0; i < k; i++){
        Ceil_and_Floor(root,result);
        result = Floor;
        Floor = INT_MIN;
    }
    return result;
}
int sumTree(Node* root){
    int sum = root->data;
    for(Node* child : root->children){
        int sumSubTree = sumTree(child);
        sum += sumSubTree;
    }
    return sum;
}
int maxSubTreeSum1(Node* root){
    int ans = sumTree(root);
    for(Node* child: root->children){
        int sumSubTree = sumTree(child);
        if(sumSubTree > ans){
            ans = sumSubTree;
        }
    }
    return ans;
}
static int maxSumNode = 0;
static int maxSum = INT_MIN;
int nodeWithMaxSubTreeSum(Node* node){
    int sum = 0;
    for(Node* child : node->children){
        int child_sum = nodeWithMaxSubTreeSum(child);
        sum+=child_sum;
    }
    sum += node->data;
    if(sum > maxSum){
        maxSumNode = node->data;
        maxSum = sum;
    }
    return sum;
}
/*
static vector<Node*> Nodes;
void linearise(Node*root){
    Nodes.push_back(root);
    for(Node* child : root->children){
        linearise(child);
    }
}
*/

static int Diameter;
void diameter(Node* root, int n1, int n2){
    //I am assuming that n1 appears before n2 in the tree.
    if(root->data == n1){
        State = 1;
    }else if(root->data == n2){
        State = 2;
    }
    if(State == 1){
        Diameter++;
    }
    for(Node* child : root->children){
        diameter(child,n1,n2);
    }
}
int diameterOfTree(Node* node){
    //this function will calculate height of deepest node and second deepest node and will update the value of diameter 
    int dch = -1;
    int sdch = -1;
    for(Node* child : node->children){
        int ch = diameterOfTree(child);
        if(ch>dch){
            sdch = dch;
            dch = ch;
        }
        else if(ch>sdch){
            sdch = ch;
        }
    }
    int candidate = dch + sdch + 2;
    if(candidate > Diameter){
        Diameter = candidate;
    }
    dch +=1;
    return dch;
}
int main()
{
    SIZE = 0;
    MAX = INT_MIN;
    MIN = INT_MAX;
    HEIGHT = 0;
    int A[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    int s = sizeof(A) / sizeof(A[0]);
    Node *root = construct(A, s);
    /*
    display(root);
    multisolver(root,0);
    cout<<"Size of the given tree is: "<<SIZE<<"\n";
    cout<<"Height of the given tree is: "<<HEIGHT<<"\n";
    cout<<"Max of the given tree is: "<<MAX<<"\n";
    cout<<"Min of the given tree is: "<<MIN<<"\n";
    Predecessor = -1;
    Successor = -1;
    pred_succ(root,100);
    cout<<"Predecessor: "<<Predecessor<<" ,Successor: "<<Successor<<"\n";
    Floor = INT_MIN;
    Ceil = INT_MAX;
    Ceil_and_Floor(root,80);
    cout<<"Ceil: "<<Ceil<<" Floor: "<<Floor<<"\n";
    int ans = kthLargest(root,3);
    cout<<ans<<"\n";
    int B[] = {10, 20, -50, -1, -60, -1, -1, 30, -70, -1, 80, -110, -1, 120, -1, -1, 90, -1, -1, 40, -100, -1, -1, -1};
    int p = sizeof(B) / sizeof(B[0]);
    Node *root2 = construct(B, s);
    int var1 = maxSubTreeSum1(root2);
    cout<<var1<<"\n";
    int sum = nodeWithMaxSubTreeSum(root2);
    cout<<"Node with maximum sum of subtree is "<<maxSumNode<<" @ "<<maxSum<<"\n";
    linearise(root);
    for(auto val : Nodes){
        cout<<val->data<<" ";
    }cout<<"\n";
    State = 0;
    Diameter = 0;
    diameter(root,50,110);
    cout<<"Distance between two nodes in terms of edges is "<<Diameter<<"\n";
    Diameter = 0;
    int h = diameterOfTree(root);
    cout<<"Diameter of tree is: "<<Diameter<<"\n";
    */
    return 0; 
}