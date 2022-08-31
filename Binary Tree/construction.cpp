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
    Node(int data)
    {
        this->data = data;
    }
    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
    ~Node()
    {
        int value = this->data;
        if (this->left != NULL)
        {
            this->left = NULL;
            delete left;
        }
        if (this->right != NULL)
        {
            this->right = NULL;
            delete right;
        }
        cout << value << " is deleted from the tree\n";
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
void display1(Node *root)
{
    string str = "";
    str += root->left == NULL ? "." : to_string(root->left->data);
    str += " <- " + to_string(root->data) + " -> ";
    str += root->right == NULL ? "." : to_string(root->right->data);
    cout << str << "\n";

    if (root->left != NULL)
        display1(root->left);

    if (root->right != NULL)
        display1(root->right);
}
int size(Node *root)
{
    if (root == NULL)
        return 0;
    int left_size = size(root->left);
    int right_size = size(root->right);
    int total_size = left_size + right_size + 1;
    return total_size;
}
int sum(Node *root)
{
    if (root == NULL)
        return 0;
    int left_sum = sum(root->left);
    int right_sum = sum(root->right);
    int total_sum = left_sum + right_sum + root->data;
    return total_sum;
}
int Maximum(Node *root)
{
    if (root == NULL)
        return INT_MIN;
    int max = root->data;
    int left_max = Maximum(root->left);
    if (left_max > max)
        max = left_max;
    int right_max = Maximum(root->right);
    if (right_max > max)
        max = right_max;
    return max;
}
int height(Node *root)
{
    if (root == NULL)
    {
        // if height is to be returned in terms of edges than return -1 and if in terms of nodes return 0 in base case
        return 0;
    }

    int left_height = height(root->left);
    int right_height = height(root->right);
    int total_height = left_height > right_height ? left_height : right_height;

    total_height++;
    return total_height;
}
void traversals1(Node *node)
{
    if (node == NULL)
        return;
    cout << "Pre-order " << node->data << "\n";
    traversals1(node->left);
    cout << "In-order " << node->data << "\n";
    traversals1(node->right);
    cout << "Post-order " << node->data << "\n";
}
void preOrderTraversal(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    cout << node->data << " ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}
void inOrderTraversal(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    inOrderTraversal(node->left);
    cout << node->data << " ";
    inOrderTraversal(node->right);
}
void postOrderTraversal(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    cout << node->data << " ";
}
static int SIZE;
static int HEIGHT;
static int SUM;
static int MAX;
void properties(Node *root, int depth)
{
    if (root == NULL)
    {
        return;
    }

    SUM += root->data;
    if (root->data > MAX)
        MAX = root->data;
    if (depth > HEIGHT)
        HEIGHT = depth;
    SIZE++;

    properties(root->left, depth + 1);
    properties(root->right, depth + 1);
}
void levelOrderTraversal(Node *node)
{
    queue<Node *> mq;
    mq.push(node);

    while (mq.size() > 0)
    {
        int count = mq.size();
        for (int i = 0; i < count; i++)
        {
            Node *temp = mq.front();
            mq.pop();
            cout << temp->data << " ";
            if (temp->left != NULL)
            {
                mq.push(temp->left);
            }
            if (temp->right != NULL)
            {
                mq.push(temp->right);
            }
        }
        cout << "\n";
    }
}
void iterativeTraversal(Node *root)
{
    // will be done using Pair class that contains node as well as state
    stack<Pair *> st;
    Pair *rootPair = new Pair(root, 1);
    string pre = "";
    string in = "";
    string post = "";
    st.push(rootPair);
    while (!st.empty())
    {
        Pair *currPair = st.top();
        if (currPair->state == 1)
        {
            pre += to_string(currPair->node->data);
            pre += " ";
            currPair->state++;
            if (currPair->node->left != NULL)
            {
                Pair *leftPair = new Pair(currPair->node->left, 1);
                st.push(leftPair);
            }
        }
        else if (currPair->state == 2)
        {
            in += to_string(currPair->node->data);
            in += " ";
            currPair->state++;
            if (currPair->node->right != NULL)
            {
                Pair *rightPair = new Pair(currPair->node->right, 1);
                st.push(rightPair);
            }
        }
        else
        {
            post += to_string(currPair->node->data);
            post += " ";
            st.pop();
        }
    }
    cout << "Iterative Traversal\n";
    cout << "Pre-order: " << pre << "\n";
    cout << "In-order: " << in << "\n";
    cout << "Post-order: " << post << "\n";
}
bool find(Node *node, int x)
{
    if (node->data == x)
    {
        return true;
    }
    // check in left child if exists
    bool found;
    if (node->left != NULL)
    {
        found = find(node->left, x);
    }
    if (found)
    {
        return true;
    }
    else
    {
        if (node->right != NULL)
        {
            found = find(node->right, x);
        }
    }
    if (found)
        return true;
    // not found in both child's family
    return false;
}
vector<int> nodeToRootPath(Node *root, int x)
{
    if (root->data == x)
    {
        vector<int> ans;
        ans.push_back(root->data);
        return ans;
    }
    vector<int> childPath;
    if (root->left != NULL)
        childPath = nodeToRootPath(root->left, x);
    if (childPath.size() > 0)
    {
        childPath.push_back(root->data);
        return childPath;
    }
    else if (root->right != NULL)
        childPath = nodeToRootPath(root->right, x);
    if (childPath.size() > 0)
    {
        childPath.push_back(root->data);
        return childPath;
    }
    vector<int> notFound;
    return notFound;
}
static vector<int> path;
bool find_and_cal_path(Node *node, int data)
{
    if (node == NULL)
    {
        return false;
    }
    if (node->data == data)
    {
        path.push_back(node->data);
        return true;
    }
    bool findInLeftChild = find_and_cal_path(node->left, data);
    if (findInLeftChild)
    {
        path.push_back(node->data);
        return true;
    }
    bool findInRightChild = find_and_cal_path(node->right, data);
    if (findInRightChild)
    {
        path.push_back(node->data);
        return true;
    }
    // not found anywhere
    return false;
}
void print_K_LevelsDown(Node *node, int k)
{
    if (node == NULL || k < 0)
    {
        return;
    }
    if (k == 0)
    {
        cout << node->data << " ";
    }
    print_K_LevelsDown(node->left, k - 1);
    print_K_LevelsDown(node->right, k - 1);
}
void pathToLeafFromRoot(Node *node, string path, int sum, int lo, int hi)
{
    /*Problem statement: Print all root to leaf paths whose sum lie in a given range */
    if (node == NULL)
    {
        return;
    }
    if (node->left == NULL && node->right == NULL)
    {
        // when node is leaf
        sum += node->data;
        if (sum >= lo && sum <= hi)
        {
            path += to_string(node->data);
            cout << path << "\n";
        }
    }

    pathToLeafFromRoot(node->left, path + to_string(node->data) + " ", sum + node->data, lo, hi);
    pathToLeafFromRoot(node->right, path + to_string(node->data) + " ", sum + node->data, lo, hi);
}
Node *createLeftClone(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    Node *left_CloneRoot = createLeftClone(root->left);
    Node *right_CloneRoot = createLeftClone(root->right);
    Node *cloneNode = new Node(root->data, left_CloneRoot, NULL);
    root->left = cloneNode;
    root->right = right_CloneRoot;
    return root;
}
Node *originalFromClone(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    Node *left_root = originalFromClone(root->left->left);
    Node *right_root = originalFromClone(root->right);
    delete root->left;
    root->left = left_root;
    root->right = right_root;
    return root;
}
void printSingleChildNode(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if ((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL))
    {
        if (root->left != NULL)
            cout << root->left->data << "\n";
        else
            cout << root->right->data << "\n";
    }
    printSingleChildNode(root->left);
    printSingleChildNode(root->right);
}
Node *removeLeaves(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        delete root;
        return NULL;
    }
    root->left = removeLeaves(root->left);
    root->right = removeLeaves(root->right);
    return root;
}
int maximum(int a, int b)
{
    return a > b ? a : b;
}
int minimum(int a, int b)
{
    return a < b ? a : b;
}
int diameter1(Node *root)
{
    // diameter is defined as no.of edges between two nodes which are maximum edges apart from each other
    if (root == NULL)
    {
        return 0;
    }
    // maximum distance between 2 nodes of LHS
    int left_dia = diameter1(root->left);
    // maximum diatance between 2 nodes of RHS
    int right_dia = diameter1(root->right);

    // maximum distance between left node's deepest node and right's deepest node
    int factor = height(root->left) + height(root->right) + 2; // adding 2 since 2 edges are required to go from left to right node via root
    int dia = maximum(factor, maximum(left_dia, right_dia));
    return dia;
    // Note: this approach is less efficient since it contains calls for two recursive functions(height and diameter1) therefore making it O(n^2)
}

class DiaPair
{
public:
    int ht;  // it represents height
    int dia; // it represents diameter
};

DiaPair diameter2(Node *root)
{
    if (root == NULL)
    {
        DiaPair basePair;
        basePair.ht = 0;
        basePair.dia = 0;
        return basePair;
    }
    DiaPair lp = diameter2(root->left);
    DiaPair rp = diameter2(root->right);

    DiaPair myPair;
    myPair.ht = maximum(lp.ht, rp.ht) + 1;

    int factor = lp.ht + rp.ht + 2;
    myPair.dia = maximum(factor, maximum(lp.dia, rp.dia));

    return myPair;
}

class sumPair
{
public:
    int sum;
    int tilt;
};
static int Tilt = 0;
// tilt of a node is defined as the difference of sum of nodes of it's left and right subtree
// tilt of whole tree is defined as the sum of tilt of each node
sumPair tilt(Node *root)
{
    // base case
    if (root == NULL)
    {
        sumPair base;
        base.sum = 0;
        base.tilt = 0;
        return base;
    }

    // Recursive calls to get left and right pairs
    sumPair lp = tilt(root->left);
    sumPair rp = tilt(root->right);

    sumPair myPair;
    myPair.sum = lp.sum + rp.sum + root->data;

    if (lp.sum > rp.sum)
    {
        myPair.tilt = lp.sum - rp.sum;
    }
    else
    {
        myPair.tilt = rp.sum - lp.sum;
    }

    return myPair;
}
int tilt2(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftSum = tilt2(root->left);
    int rightSum = tilt2(root->right);
    int mySum = leftSum + rightSum + root->data;

    // update tilt (global variable)
    int ltilt = abs(leftSum - rightSum); // local tilt
    Tilt += ltilt;

    return mySum;
}

class BSTPair
{
public:
    int max;
    int min;
    bool isBST;
};
// function to check if Binary tree is a BST(Binary Search Tree)
BSTPair isBST(Node *root)
{
    if (root == NULL)
    {
        BSTPair base;
        base.isBST = true;
        base.min = INT_MAX;
        base.max = INT_MIN;
        return base;
    }

    BSTPair ls = isBST(root->left);
    BSTPair rs = isBST(root->right);

    BSTPair myPair;
    // the root node will qualify for bst if it satisfy the condition of bst as well both his children are also BST's
    myPair.isBST = ls.isBST && rs.isBST && (root->data > ls.max && root->data < rs.min);
    // calculate maximum and minimum for the node under consideration
    myPair.max = maximum(root->data, maximum(ls.max, rs.max));
    myPair.min = minimum(root->data, minimum(ls.min, rs.min));

    return myPair;
}
// check if a binary tree is balanced method 1
class BalancePair
{
public:
    bool isBalanced;
    int height;
};

BalancePair isBalanced1(Node *root)
{
    if (root == NULL)
    {
        BalancePair base;
        base.isBalanced = true;
        base.height = 0; 
        return base;
    }
    BalancePair lp = isBalanced1(root->left);
    BalancePair rp = isBalanced1(root->right);

    BalancePair myPair;
    myPair.isBalanced = lp.isBalanced && rp.isBalanced && (abs(lp.height - rp.height) <= 1);
    myPair.height = maximum(lp.height, rp.height) + 1;

    return myPair;
}
// check if binary tree is balanced method 2 (using traverse and change strategy)
static bool isBalanced = true;
int isBalanced2(Node *root)
{
    if (root == NULL)
    {
        return 0; // height of leaf node is 0
    }

    int left_tree_height = isBalanced2(root->left);
    int right_tree_height = isBalanced2(root->right);

    if (abs(left_tree_height - right_tree_height) > 1)
    {
        isBalanced = false;
    }

    int myHeight = maximum(left_tree_height, right_tree_height) + 1;
    return myHeight;
}

template <typename T>
void print(T ans)
{
    for (auto val : ans)
    {
        cout << val << " ";
    }
    cout << "\n";
}
void test()
{
    int A[] = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};
    int s = sizeof(A) / sizeof(A[0]);
    Node *root = construct(A, s);
    /*
    display1(root);
    SIZE = 0;
    MAX = INT_MIN;
    HEIGHT = 0;
    SUM = 0;
    properties(root, 0);
    cout << "Properties of given Binary Tree:-\n";
    cout << "Max: " << MAX << "\n";
    cout << "Height: " << HEIGHT << "\n";
    cout << "Sum: " << SUM << "\n";
    cout << "Size: " << SIZE << "\n";
    traversals1(root);
    cout<<"Pre-order Traversal:\n";
    preOrderTraversal(root);
    cout<<"\nIn-Order Traversal:\n";
    inOrderTraversal(root);
    cout<<"\nPost-order Traversal:\n";
    postOrderTraversal(root);
    levelOrderTraversal(root);
    iterativeTraversal(root);
    vector<int> ans = nodeToRootPath(root,70);
    print<vector<int>>(ans);
    bool found = find(root, 30);
    cout << found << "\n";
    bool flag = find_and_cal_path(root,70);
    print<vector<int>>(path);
    print_K_LevelsDown(root,2);
    pathToLeafFromRoot(root,"",0,40,600);
    Node* leftCloneTree = createLeftClone(root);
    cout<<"cloned tree\n";
    preOrderTraversal(leftCloneTree);
    cout<<"\n";
    Node* org =  originalFromClone(root);
    cout<<"orignal tree\n";
    preOrderTraversal(root);
    cout<<"\n";
    printSingleChildNode(root);
    cout<<"Before removing leaves: \n";
    preOrderTraversal(root);
    cout<<"\n";
    removeLeaves(root);
    cout<<"\nAfter removing leaves: \n";
    preOrderTraversal(root);
    cout<<"Diameter of the tree using method1: "<< diameter1(root)<<"\n";
    DiaPair p = diameter2(root);
    cout<<"Diameter of the tree using method2: "<< p.dia<<"\n";
    sumPair pair = tilt(root);
    cout<<pair.tilt<<"\n";
    int ts = tilt2(root);
    cout<<Tilt<<"\n";
    BSTPair mp = isBST(root);
    cout<<mp.isBST<<"\n";
    */
}
int main()
{
    test();
    return 0;
}