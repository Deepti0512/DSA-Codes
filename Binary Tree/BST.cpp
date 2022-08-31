#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node() {}
    Node(int data)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
Node *construct(int arr[], int n, int lo, int hi)
{
    // create binary search tree from sorted array
    if (lo > hi)
    {
        return NULL;
    }
    int mid = (lo + hi) / 2;
    int data = arr[mid];
    Node *lc = construct(arr, n, lo, mid - 1);
    Node *rc = construct(arr, n, mid + 1, hi);

    Node *newNode = new Node(data, lc, rc);
    return newNode;
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
static int size;
static int sum;
void sizeAndSum(Node *root)
{
    if (root == NULL)
        return;
    size++;
    sum += root->data;
    sizeAndSum(root->left);
    sizeAndSum(root->right);
}
int max(Node *node)
{
    if (node->right != NULL)
    {
        return max(node->right);
    }
    else
        return node->data;
}
int min(Node *node)
{
    if (node->left != NULL)
    {
        return min(node->left);
    }
    else
        return node->data;
}
bool find(Node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == data)
    {
        return true;
    }
    else if (root->data > data)
    {
        find(root->left, data);
    }
    else
    {
        find(root->right, data);
    }
}
void AddNodeToBST(Node *root, int data)
{
    if (data < root->data)
    {
        if (root->left != NULL)
            AddNodeToBST(root->left, data);
        else
        {
            Node *newNode = new Node(data);
            root->left = newNode;
        }
    }
    else if (data > root->data)
    {
        if (root->right != NULL)
            AddNodeToBST(root->right, data);
        else
        {
            Node *newNode = new Node(data);
            root->right = newNode;
        }
    }
    else
    {
        // if data is already present in the node then no need to add new node
    }
}
Node *removeNode(Node *node, int data)
{
    // remove node in such a way that the tree persist it's BST property
    if (node == NULL)
        return NULL;
    if (node->data > data)
    {
        node->left = removeNode(node->left, data);
    }
    else if (node->data < data)
    {
        node->right = removeNode(node->right, data);
    }
    else
    {
        if (node->left != NULL && node->right != NULL)
        {
            // return max from left side and then delete it from left subtree
            int lmax = max(node->left);
            node->data = lmax;
            node->left = removeNode(node->left, lmax);
            return node;
        }
        else if (node->left == NULL && node->right != NULL)
        {
            return node->right;
        }
        else if (node->right == NULL && node->left != NULL)
        {
            return node->left;
        }
        else
        {
            delete node;
            return NULL;
        }
    }
}
void replaceNodewithSumofLargerNodes(Node *root)
{
    // we will traverse in reverse in-order to get nodes in decreasing order
    if (root == NULL)
    {
        return;
    }
    // right call
    replaceNodewithSumofLargerNodes(root->right);
    // in-order
    int originalData = root->data;
    root->data = sum;
    sum += originalData;
    // left call
    replaceNodewithSumofLargerNodes(root->left);
}
int LCA(Node *node, int d1, int d2)
{
    // LCA : Lowest Common Ancestor
    // Method 1: find node to root path of both the nodes in calculate the lca
    // Method 2: since it's BST we can reduce the complexity (hehe)
    if (d1 < node->data && d2 < node->data)
    {
        // go to left subtree
        return LCA(node->left, d1, d2);
    }
    else if (d1 > node->data && d2 > node->data)
    {
        // go to right subtree
        return LCA(node->right, d1, d2);
    }
    else
    {
        // if one is smaller and the other is larger then the path will diverge and we need this diverging point as answer
        return node->data;
    }
}
void printInRange(Node *node, int d1, int d2)
{
    if (node == NULL)
        return;
    // find low and high and then print elements occuring in in-order from these two points
    if (d1 < node->data && d2 < node->data)
    {
        printInRange(node->left, d1, d2);
    }
    else if (d1 > node->data && d2 > node->data)
    {
        printInRange(node->right, d1, d2);
    }
    else
    {
        printInRange(node->left, d1, d2);
        cout << node->data << " ";
        printInRange(node->right, d1, d2);
    }
}

void traverseAndFill(Node *root, vector<int> &list)
{
    if (root == NULL)
    {
        return;
    }
    traverseAndFill(root->left, list);
    list.push_back(root->data);
    traverseAndFill(root->right, list);

    /* Time & Space complexity : O(n)*/
}

class targetSumPair
{
public:
    void targetSumPair1(Node *root, Node *node, int target)
    {
        /*Approach1: traverse the nodes in in-order then check if their complement exist in tree i.e(target - node->data), if yes then print the node and the complement*/
        if (node == NULL)
        {
            return;
        }
        targetSumPair1(root, node->left, target);
        int complement = target - node->data;
        if (node->data < complement)
        {
            if (find(root, complement))
            {
                cout << node->data << " - " << complement << "\n";
            }
        }
        targetSumPair1(root, node->right, target);

        /* Time complexity of this approach is O(nlogn) since find is logn
        And Space complexity is n*height (sc of find is height, since find is called for n nodes therfore complexity is n*height)*/
    }
    void targetSumPair2(Node *root, int target)
    {
        /*Approach 2: traverse the tree and push the nodes in in-order int vector so that they are pushed in increasing order.
      Use this array to find the target sum pairs by two pointer approach */
        vector<int> list;
        traverseAndFill(root, list);
        int left = 0;
        int right = list.size() - 1;
        while (left < right)
        {
            if (list[left] + list[right] < target)
            {
                left++;
            }
            else if (list[left] + list[right] > target)
            {
                right--;
            }
            else
            {
                cout << list[left] << " - " << list[right] << "\n";
                left++;
                right--;
            }
        }
        /* Time Complexity : O(n) and Space Complexity: O(n)*/
    }

    class ITPair
    {
    public:
        Node *node;
        int state;
        ITPair(Node *node, int state)
        {
            this->node = node;
            this->state = state;
        }
    };

    Node *getNextFromNormalInorder(stack<ITPair *> &st)
    {
        while (!st.empty())
        {
            ITPair *top = st.top();
            if (top->state == 0)
            {
                if (top->node->left != NULL)
                {
                    st.push(new ITPair(top->node->left, 0));
                }
                top->state++;
            }
            else if (top->state == 1)
            {
                if (top->node->right != NULL)
                {
                    st.push(new ITPair(top->node->right, 0));
                }
                top->state++;
                return top->node;
            }
            else
            {
                st.pop();
            }
        }
        return NULL;
    }
    Node *getNextFromReverseInorder(stack<ITPair *> &st)
    {
        while (!st.empty())
        {
            ITPair *top = st.top();
            if (top->state == 0)
            {
                if (top->node->right != NULL)
                {
                    st.push(new ITPair(top->node->right, 0));
                }
                top->state++;
            }
            else if (top->state == 1)
            {
                if (top->node->left != NULL)
                {
                    st.push(new ITPair(top->node->left, 0));
                }
                top->state++;
                return top->node;
            }
            else
            {
                st.pop();
            }
        }
        return NULL;
    }

    void targetSumPair3(Node *root, int target)
    {
        stack<ITPair *> leftstack;
        stack<ITPair *> rightstack;

        leftstack.push(new ITPair(root, 0));
        rightstack.push(new ITPair(root, 0));

        Node *left = getNextFromNormalInorder(leftstack);
        Node *right = getNextFromReverseInorder(rightstack);

        while (left->data < right->data)
        {
            if (left->data + right->data < target)
            {
                left = getNextFromNormalInorder(leftstack);
            }
            else if (left->data + right->data > target)
            {
                right = getNextFromReverseInorder(rightstack);
            }
            else
            {
                cout << left->data << " - " << right->data << "\n";
                left = getNextFromNormalInorder(leftstack);
                right = getNextFromReverseInorder(rightstack);
            }
        }
        /*This is best approach for solving targetSumPair since its time complexity is O(n) and space complexity is O(height)*/
    }
};

int main()
{
    int arr[] = {12, 25, 30, 37, 50, 60, 62, 70, 87};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = construct(arr, n, 0, n - 1);
    int A[] = {12, 25, 37, 50, 62, 75, 87};
    Node *root2 = construct(A, 7, 0, 6);
    sum = 0;
    size = 0;
    /*
    display1(root);
    cout << find(root, 87) << "\n";
    removeNode(root, 25);
    cout<<"\n";
    display1(root2);
    cout<<"\n";
    sum = 0;
    replaceNodewithSumofLargerNodes(root2);
    display1(root2);
    cout<<LCA(root,12,60)<<"\n";
    printInRange(root2, 25, 75);
    targetSumPair obj;
    obj.targetSumPair1(root, root, 100);
    obj.targetSumPair2(root, 100);
    obj.targetSumPair3(root,100);
    */
    return 0;
}