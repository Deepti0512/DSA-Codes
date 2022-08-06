#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

bool detectLoop(Node *head)
{
    // TC : O(n)
    // SC : O(n)
    if (head == NULL)
    {
        return false;
    }
    map<Node *, bool> visited;
    Node *temp = head;
    while (temp != NULL)
    {
        // cycle(loop)present
        if (visited[temp] == true)
        {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

// Approach two
Node *floydsAlgoDetectLoop(Node *head)
{
    // TC: O(n)
    // SC: O(1)
    if (head == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        if (slow == fast)
        {
            return slow; // point of intersection returned
        }
    }
    return NULL;
}

Node *getStartingNode(Node *head)
{

    if (head == NULL)
    {
        return NULL;
    }
    Node *intersection = floydsAlgoDetectLoop(head);
    Node *fast = intersection;
    Node *slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
void removeLoop(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *start = getStartingNode(head);
    Node *temp = start;
    while (temp->next != start)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

int main()
{
    return 0;
}
