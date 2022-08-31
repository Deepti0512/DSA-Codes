#include <bits/stdc++.h>
using namespace std;
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
int main()
{
    return 0;
}