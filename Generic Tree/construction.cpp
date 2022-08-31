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
void display(Node *root)
{
    // we will use recursion ka faith
    // faith : jo node pass kiya h uska khud ka data plus uske children ki puri family print ho jayegi
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
int size(Node *root)
{
    int s = 0;
    for (Node *child : root->children)
    {
        int cs = size(child);
        s += cs;
    }
    s = s + 1;
    return s;
}
int maximum(Node *node)
{
    int max = INT_MIN;
    for (Node *child : node->children)
    {
        int cm = maximum(child);
        if (cm > max)
        {
            max = cm;
        }
    }
    if (node->data > max)
    {
        max = node->data;
    }
    return max;
}
int max2(Node *root)
{
    int max = root->data;
    for (Node *child : root->children)
    {
        int cm = maximum(child);
        if (cm > max)
        {
            max = cm;
        }
    }
    return max;
}
int height(Node *root)
{
    // if we want answer in terms of nodes then initialise h as 0 and for edges initialse as -1
    int h = 0;
    for (Node *child : root->children)
    {
        int ch = height(child);
        if (ch > h)
        {
            h = ch;
        }
    }
    h = h + 1;
    return h;
}
void traversal(Node *root)
{
    cout << "Node Pre " << root->data << "\n";
    for (Node *child : root->children)
    {
        cout << "Edge Pre " << root->data << "-" << child->data << "\n";
        traversal(child);
        cout << "Edge Post " << root->data << "-" << child->data << "\n";
    }
    cout << "Node Post " << root->data << "\n";
}
class Pair
{
public:
    Node *node;
    int level;
    Pair(Node *node, int level)
    {
        this->node = node;
        this->level = level;
    }
};
class LevelOrderTraversal
{
public:
    void clear(stack<Node *> &s)
    {
        while (!s.empty())
        {
            s.pop();
        }
    }
    void levelOrder(Node *root)
    {
        queue<Node *> q;
        q.push(root);
        while (q.size() > 0)
        {
            Node *temp = q.front();
            q.pop();
            cout << temp->data << " ";
            for (auto child : temp->children)
            {
                q.push(child);
            }
        }
        cout << ".\n";
    }
    void levelOrderLineWise1(Node *root)
    {
        cout << "This approach make use of two queues (main queue and child queue):\n";
        queue<Node *> mq;
        queue<Node *> cq;
        mq.push(root);
        while (mq.size() > 0)
        {
            Node *temp = mq.front();
            mq.pop();
            cout << temp->data << " ";
            for (Node *child : temp->children)
            {
                cq.push(child);
            }
            if (mq.size() == 0)
            {
                mq = cq;
                while (cq.size() > 0)
                    cq.pop();
                cout << "\n";
            }
        }
    }
    void levelOrderLineWise2(Node *root)
    {
        if (root == NULL)
            return;
        cout << "Using a queue and a null marker\nThis approach is also called delimiter approach\n";
        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            if (q.front() != NULL)
            {
                Node *temp = q.front();
                q.pop();
                cout << temp->data << " ";
                for (Node *child : temp->children)
                {
                    q.push(child);
                }
            }
            else
            {
                q.pop();
                cout << "\n";
                if (q.size() > 0)
                {
                    q.push(NULL);
                }
            }
        }
    }
    void levelOrderZigZag(Node *root)
    {
        stack<Node *> ms;
        stack<Node *> cs;
        ms.push(root);
        int level = 1;
        while (ms.size() > 0)
        {
            Node *temp = ms.top();
            ms.pop();
            cout << temp->data << " ";
            if (level & 1)
            {
                for (int i = 0; i < temp->children.size(); i++)
                {
                    Node *child = temp->children[i];
                    cs.push(child);
                }
            }
            else
            {
                for (int i = temp->children.size() - 1; i >= 0; i--)
                {
                    Node *child = temp->children[i];
                    cs.push(child);
                }
            }
            if (ms.size() == 0)
            {
                ms = cs;
                clear(cs);
                cout << "\n";
                level++;
            }
        }
    }
    void levelOrderLineWise3(Node *root)
    {
        cout << "Approach: count the no.of children in a level and run loop for that many times only\n";
        queue<Node *> q;
        q.push(root);
        while (q.size() > 0)
        {
            int childInCurrentNode = q.size();
            for (int i = 0; i < childInCurrentNode; i++)
            {
                Node *temp = q.front();
                q.pop();
                cout << temp->data << " ";

                for (Node *child : temp->children)
                {
                    q.push(child);
                }
            }
            cout << "\n";
        }
    }
    void levelOrderLineWise4(Node *root)
    {
        queue<Pair *> mq;
        Pair *a = new Pair(root, 1);
        mq.push(a);
        int level = 1;
        while (mq.size() > 0)
        {
            Pair *p = mq.front();
            mq.pop();
            if (p->level > level)
            {
                level = p->level;
                cout << "\n";
            }

            cout << p->node->data << " ";
            for (Node *child : p->node->children)
            {
                Pair *cp = new Pair(child, p->level + 1);
                mq.push(cp);
            }
        }
    }
};
void mirrorTransform(Node *node)
{
    for (Node *child : node->children)
    {
        mirrorTransform(child);
    }
    int start = 0;
    int end = node->children.size() - 1;
    while (start < end)
    {
        swap(node->children[start++], node->children[end--]);
    }
}
void removeLeaves(Node *node)
{
    for (int i = node->children.size() - 1; i >= 0; i--)
    {
        Node *child = node->children[i];
        if (child->children.size() == 0)
        {
            auto index = node->children.begin() + i;
            node->children.erase(index);
        }
    }
    for (Node *child : node->children)
    {
        removeLeaves(child);
    }
}
Node *getTail(Node *node)
{
    while (node->children.size() == 1)
    {
        node = node->children[0];
    }
    return node;
}
void LineariseTree(Node *node)
{
    // root ke sare children ko linearise krdo (faith on recursion)
    for (Node *child : node->children)
    {
        LineariseTree(child);
    }
    // faith meets expectation : linear order me connect krdo child node aur parent node ko
    while (node->children.size() > 1)
    {
        int size = node->children.size();
        Node *lastChild = node->children[size - 1];
        node->children.pop_back();
        Node *secondLastChild = node->children[size - 2];
        Node *secondLastTail = getTail(secondLastChild);
        secondLastTail->children.push_back(lastChild);
    }
}
Node* linearise2(Node* node){
    // This function linearise the node and returns tail
    if(node->children.size() == 0){
        // that is the node is a leaf so no need to linearise it
        //also if we will try to linearise then we will get exception due to line no 364
        return node;
    }
    Node* lastChildTail = linearise2(node->children[node->children.size()-1]);
    while(node->children.size() > 1){
        Node* last = node->children[node->children.size()-1];
        node->children.pop_back();
        Node* secondLast = node->children[node->children.size()-1];
        Node* secondLastTail = linearise2(secondLast);
        secondLastTail->children.push_back(last);
    }
    return lastChildTail;
}
bool find_element(Node *root, int x)
{
    if (root->data == x)
    {
        return true;
    }
    for (Node *child : root->children)
    {
        bool isPresentInChild = find_element(child, x);
        if (isPresentInChild)
        {
            return true;
        }
    }
    // agar node ke equal nhi h aur uske kisi child ki family me bhi nhi h toh mtlab pure tree me nhi h
    return false;
}
/*
void printIntList(list<int>ans){
     for (auto val : ans)
    {
        cout << val << "-->";
    }
    cout << "\n";
}
void printNodeList(list<Node *> ans)
{
    for (auto val : ans)
    {
        cout << val->data << "-->";
    }
    cout << "\n";
}
*/
vector<int> nodeToRootPath(Node *root, int x)
{
    if (root->data == x)
    {
        vector<int> ans;
        ans.push_back(root->data);
        return ans;
    }
    for (Node *child : root->children)
    {
        vector<int> pathTillChild = nodeToRootPath(child, x);
        if (!pathTillChild.empty())
        {
            pathTillChild.push_back(root->data);
            return pathTillChild;
        }
    }
    vector<int> res;
    return res;
}
void print(vector<int> v)
{
    for (auto val : v)
    {
        cout << val << " ";
    }
    cout << "\n";
}
int lowetCommonAncestor(Node *root, int node1, int node2)
{
    vector<int> Path1 = nodeToRootPath(root, node1);
    vector<int> Path2 = nodeToRootPath(root, node2);
    int i = Path1.size() - 1;
    int j = Path2.size() - 1;
    while (i >= 0 && j >= 0 && Path1[i] == Path2[j])
    {
        i--;
        j--;
    }
    i++;
    j++;
    int ans = Path1[i];
    return ans;
}
int distanceBtw2Nodes(Node *root, int n1, int n2)
{
    vector<int> Path1 = nodeToRootPath(root, n1);
    vector<int> Path2 = nodeToRootPath(root, n2);
    int i = Path1.size() - 1;
    int j = Path2.size() - 1;
    while (i >= 0 && j >= 0 && Path1[i] == Path2[j])
    {
        i--;
        j--;
    }
    i++;
    j++;
    return i + j;
}
bool areSimilar(Node *root1, Node *root2)
{
    if (root1->children.size() != root2->children.size())
    {
        return false;
    }
    int s = root1->children.size();
    for (int i = 0; i < s; i++)
    {
        Node *child1 = root1->children[i];
        Node *child2 = root2->children[i];
        if (areSimilar(child1, child2) == false)
        {
            return false;
        }
    }
    return true;
}
bool isMirror(Node *tree1, Node *tree2)
{
    if (tree1->children.size() != tree2->children.size())
    {
        return false;
    }
    int s = tree1->children.size();
    for (int i = 0, j = s - 1; i < s; i++, j--)
    {
        Node *child1 = tree1->children[i];
        Node *child2 = tree2->children[j];
        if (!isMirror(child1, child2))
        {
            return false;
        }
    }
    return true;
}
bool isSymmetric(Node *root)
{
    int s = root->children.size();
    for (int i = 0, j = s - 1; i < s / 2; i++, j--)
    {
        Node *child1 = root->children[i];
        Node *child2 = root->children[j];
        if (!isMirror(child1, child2))
        {
            return false;
        }
    }
    return true;
}
bool isSymmetric2(Node *root)
{
    // property of symmetric objects: they are mirror image of themselves!!
    return isMirror(root, root);
}
void test()
{
    int A[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    int s = sizeof(A) / sizeof(A[0]);
    Node *root = construct(A, s);
    /*
    int B[] = {11, 22, 55, -1, 66, -1, -1, 33, 77, -1, 88, 111, -1, 122, -1, -1, 99, -1, -1, 44, 500, -1, -1, -1};
    int C[] = {10, 20, -1, 30, 50, -1, 60, -1, -1, 40, -1, -1};
    int n = sizeof(B) / sizeof(B[0]);
    int m = sizeof(C) / sizeof(C[0]);
    Node *Tree1 = construct(B, n);
    Node *Tree2 = construct(C, m);
    display(root);
    cout << "maximum value in tree is: " << max2(root) << "\n";
    cout << "Traversal:\n";
    traversal(root);
    cout << "Level order traversal:\n";
    LevelOrderTraversal obj;
    obj.levelOrder(root);
    obj.levelOrderLineWise1(root);
    obj.levelOrderLineWise2(root);
    cout << "Level order traversal (Zig-Zag):\n";
    obj.levelOrderZigZag(root);
    obj.levelOrderLineWise3(root);
    obj.levelOrderLineWise4(root);
    int x = 110;
    if (find_element(root, x))
    {
        cout << x << " is present in tree\n";
    }
    else
        cout << x << " is not present in tree!\n";
    vector<int> ans = nodeToRootPath(root, x);
    print(ans);
    int LCA = lowetCommonAncestor(root, 80, 110);
    cout << "Lowest common ancestor of the two nodes is: " << LCA << "\n";
    cout << "Distance between the given nodes is: " << distanceBtw2Nodes(root, 70, 110);
    cout << "Tree1 display:\n";
    display(Tree1);
    cout << "Tree2 display:\n";
    display(Tree2);
    if (areSimilar(Tree1, Tree2))
    {
        cout << "Trees are similar in shape\n";
    }
    else
        cout << "Tree are not similar in shape\n";
    int D[] = {10, 20, 40, 80, -1, 100, -1, -1, 50, -1, -1, 30, 60, -1, 70, 110, -1, 90, -1, -1, -1, -1};
    int p = sizeof(A) / sizeof(A[0]);
    Node *tree3 = construct(D, p);
    if (isSymmetric(root))
    {
        cout << "YES\nGiven tree is symmetric!";
    }
    else
    {
        cout << "Not symmetric!\n";
    }
    */
    display(root);
    cout<<"\n";
    linearise2(root);
    display(root);
}

int main()
{
    test();
    return 0;
}
